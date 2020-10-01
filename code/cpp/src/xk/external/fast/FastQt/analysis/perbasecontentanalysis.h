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
#ifndef PERBASECONTENTANALYSIS_H
#define PERBASECONTENTANALYSIS_H
#include <QtCore>
#include <QtCharts>
#include "analysis.h"
#include "basegroup.h"
#include "lengthdistributionanalysis.h"

using namespace QT_CHARTS_NAMESPACE;
/*!
 * \class PerBaseContentAnalysis
 * \brief Per Base Sequence Content plots out the proportion of each base position in a file for which each of the four normal DNA bases has been called.
 * Relative to Per Base Sequence Content FastQC module Basic
 * <http://www.bioinformatics.babraham.ac.uk/projects/fastqc/Help/3%20Analysis%20Modules/4%20Per%20Base%20Sequence%20Content.html>
 */
class PerBaseContentAnalysis : public Analysis
{
    Q_OBJECT

public:
    PerBaseContentAnalysis(QObject * parent = nullptr);

    virtual void processSequence(const Sequence& sequence) Q_DECL_OVERRIDE;
    virtual void reset() Q_DECL_OVERRIDE;
    virtual QWidget* createResultWidget() Q_DECL_OVERRIDE;


protected:
    void computePercentages();
    virtual void after() Q_DECL_OVERRIDE;


private:
    QVector<quint64> mGCounts;
    QVector<quint64> mACounts;
    QVector<quint64> mCCounts;
    QVector<quint64> mTCounts;
    QVector<quint64> mXCounts;

    QVector<qreal> gPercent;
    QVector<qreal> aPercent;
    QVector<qreal> tPercent;
    QVector<qreal> cPercent;

    QVector<QString> mXCategories;
    QVector<quint64>* counts[256];

};

#endif // PERBASECONTENTANALYSIS_H
