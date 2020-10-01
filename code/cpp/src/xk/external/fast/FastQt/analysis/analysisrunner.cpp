/*
Copyright Copyright 2016-17 Sacha Schutz

    This file is part of fastQT.

    Foobar is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

    @author : Pierre Lindenbaum from FastQC <http://www.bioinformatics.babraham.ac.uk/projects/fastqc/>
    @author : Sacha Schutz <sacha@labsquare.org>
    @author : Pierre Marijon <pierre@marijon.fr>
*/
#include "analysisrunner.h"

#include "format_detection.h"

#include "analysisrunner.h"
#include "basicstatsanalysis.h"
#include "perbasequalityanalysis.h"
#include "persequencequalityanalysis.h"
#include "perbasecontentanalysis.h"
#include "overrepresentedseqsanalysis.h"
#include "perbasencontentanalysis.h"
#include "persequencegccontent.h"
#include "lengthdistributionanalysis.h"


AnalysisRunner::AnalysisRunner()
    :QRunnable()
{
    setAutoDelete(false); // don't delete threads
}

AnalysisRunner::AnalysisRunner(const QString &filename)
    :QRunnable()
{
    setAutoDelete(false); // don't delete threads

    setFilename(filename);

}

AnalysisRunner::~AnalysisRunner()
{
    mAnalysisHash.clear();
}

void AnalysisRunner::run()
{
    setStatus(Running);

    QFileInfo fileInfo(mFilename);

    QScopedPointer<QIODevice>  uncompressFile;
    QFile * rawFile = new QFile(mFilename);

    bool ubam = false;
    if (is_ubam(rawFile))
    {
        uncompressFile.reset(new QFile(mFilename));
        ubam = true;
    }
    else if (is_gz(rawFile))
    {
        // true  : mean delete rawFile with KCompressionDevice.
        // KcompressionDevice is a QScopedPointer and will be deleted at the end
      //?  uncompressFile.reset(new KCompressionDevice(rawFile,true,KCompressionDevice::GZip));
        if (!is_fastq(uncompressFile.data()))
        return;

    }
    else if (is_bz2(rawFile))
    {
     //?  uncompressFile.reset(new KCompressionDevice(rawFile, true, KCompressionDevice::BZip2));
        if (!is_fastq(uncompressFile.data()))
        return;
    }
    else if (is_xz(rawFile))
    {
     //?   uncompressFile.reset(new KCompressionDevice(rawFile,true, KCompressionDevice::Xz));
        if (!is_fastq(uncompressFile.data()))
        return;
    }
    else if (is_fastq(rawFile))
    {
        // rawFile is QScopedPointer in the case
        uncompressFile.reset(rawFile);
        if (!is_fastq(uncompressFile.data()))
        return;



    }

    if (uncompressFile.isNull())
    {
        qDebug()<<Q_FUNC_INFO<<fileInfo.suffix()<< " file is not supported";
        setStatus(Canceled);
        return;
    }

    if (fileInfo.size() == 0)
    {
        setStatus(Canceled);
        return;
    }


    if (uncompressFile.data()->open(QIODevice::ReadOnly))
    {
        mSequenceCount = 0;
        mProgression   = 0;

        AbstractSequenceReader* reader = nullptr;
        if (ubam)
        {
            reader = new BamReader(static_cast<QFile*>(rawFile));
        }
        else
        {
            reader = new FastqReader(uncompressFile.data());
        }
        mStartTime.start();

        for (Analysis * a : mAnalysisHash)
            a->before();

        while (reader->next() && !isCanceled())
        {

            // check if first sequence is valid..Means it's probably a good file
            if (mSequenceCount == 0)
            {
                if (!reader->sequence().isValid())
                {
                    qCritical()<<Q_FUNC_INFO<<"Cannot read sequence. Are you sure it's a Fastq file ?";
                    setStatus(Canceled);
                    return ;
                }
            }


            ++mSequenceCount;
            // this is critcal and can decrease the speed. Send message only 1 sequence / 1000
            if (mSequenceCount % 1000 == 0)
            {
                int percentNow = qRound(static_cast<qreal>(rawFile->pos()) / fileInfo.size() * 100);

                // if percentNow is still null, return empty percent ...
                if ( (percentNow >= mProgression + 5) || (percentNow == 0))
                {
                    mProgression = percentNow;
                    //emitUpdate(tr("%1 Sequences procceed ( %2 \% )").arg(mSequenceCount).arg(mProgression));
                }
            }


            for (Analysis * a : mAnalysisHash)
            {
                a->processSequence(reader->sequence());
            }
        }

        for (Analysis * a : mAnalysisHash)
            a->after();

        mProgression = 100;
        //emitUpdate(tr("Complete "));
        if (!mCancel)
            setStatus(Finished);

        mDuration = mStartTime.elapsed();

        delete reader;
    }

    else
    {
        qDebug()<<Q_FUNC_INFO<<"Cannot open file";
    }



}

void AnalysisRunner::addAnalysis(Analysis *analysis)
{
    analysis->setRunner(this);
    mAnalysisHash.insert(analysis->metaObject()->className(),analysis);
}

void AnalysisRunner::setFilename(const QString &filename)
{
    mFilename = filename;
    QFileInfo fileInfo(mFilename);
    mFileSize = fileInfo.size();
}

void AnalysisRunner::reset()
{
    for (Analysis * a : analysisList())
        a->reset();
}

const QString &AnalysisRunner::filename() const
{
    return mFilename;
}

AnalysisRunner::Status AnalysisRunner::status() const
{
    return mStatus;
}



int AnalysisRunner::progression() const
{
    return mProgression;
}

int AnalysisRunner::sequenceCount() const
{
    return mSequenceCount;
}

void AnalysisRunner::cancel()
{
    QMutexLocker locker(&mMutex);
    mCancel = true;
    mStatus = Canceled;
}

bool AnalysisRunner::isCanceled()
{
    QMutexLocker locker(&mMutex);
    return mCancel;
}

qint64 AnalysisRunner::fileSize() const
{
    return mFileSize;
}

QString AnalysisRunner::humanFileSize() const
{
    int unit;
    const char *units [] = {" Bytes", " kB", " MB", " GB"};
    float size = float(fileSize()); // or whatever

    for (unit=-1; (++unit<3) && (size>1023); size/=1024);

    return QString::number(size, 'f', 1) + QString::fromLatin1(units[unit]);

}

const QString &AnalysisRunner::lastMessage() const
{
    return mMessage;
}

int AnalysisRunner::duration() const
{
    if (status() != Running)
        return mDuration;

    else
        return mStartTime.elapsed();

}


QList<Analysis*> AnalysisRunner::analysisList() const
{
    return mAnalysisHash.values();
}



Analysis *AnalysisRunner::analysis(const QString &className)
{
    if (mAnalysisHash.contains(className))
        return mAnalysisHash[className];
    return nullptr;
}


void AnalysisRunner::saveAll(const QString &path)
{
    QFileInfo info(filename());
    QDir dir(path);
    dir.mkpath(info.baseName());
    dir.cd(info.baseName());

    for (Analysis * a : mAnalysisHash)
        a->save(dir.path());

}


void AnalysisRunner::emitUpdate(const QString &message)
{
    mMessage = message;
}

void AnalysisRunner::setStatus(AnalysisRunner::Status status)
{
    mStatus = status;

}

AnalysisRunner* AnalysisRunner::createAnalysisRunner()
{
    AnalysisRunner* runner = new AnalysisRunner();

    runner->addAnalysis(new BasicStatsAnalysis);
    runner->addAnalysis(new PerBaseQualityAnalysis);
    runner->addAnalysis(new PerSequenceQualityAnalysis);
    runner->addAnalysis(new OverRepresentedSeqsAnalysis);
    runner->addAnalysis(new PerBaseNContentAnalysis);
    runner->addAnalysis(new PerSequenceGCContent);
    runner->addAnalysis(new LengthDistributionAnalysis);
    runner->addAnalysis(new PerBaseContentAnalysis);

    return runner;
}
