/*
Copyright Copyright 2016-17 Pierre Marijon

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
#ifndef PERSEQUENCEGCCONTENT_H
#define PERSEQUENCEGCCONTENT_H

#include <QtCore>
#include <QtCharts>

#include "analysis.h"
#include "basegroup.h"

using namespace QT_CHARTS_NAMESPACE;

/*!
 * \class PerSequenceGCCContent
 * \brief Per Sequence GC Content plots out the mean sequence GC % distribution
 * <http://www.bioinformatics.babraham.ac.uk/projects/fastqc/Help/3%20Analysis%20Modules/5%20Per%20Sequence%20GC%20Content.html>
 */
class PerSequenceGCContent : public Analysis
{
    Q_OBJECT
public:
    PerSequenceGCContent(QObject * parent = nullptr);

    virtual void processSequence(const Sequence& sequence) Q_DECL_OVERRIDE;
    virtual void reset() Q_DECL_OVERRIDE;
    virtual QWidget* createResultWidget() Q_DECL_OVERRIDE;

private:

    QVector<quint64> mGCCounts;
    quint64 mNbSeq;
    quint64 mXMax;
};

#endif // PERSEQUENCEGCCONTENT_H
