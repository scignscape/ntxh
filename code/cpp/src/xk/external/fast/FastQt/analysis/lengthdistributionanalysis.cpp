#include "lengthdistributionanalysis.h"
LengthDistributionAnalysis::LengthDistributionAnalysis(QObject * parent)
    :Analysis(parent)
{
    setName(tr("Sequence Length Distribution"));
    setDescription(tr("Shows the distribution of sequence length over all sequences"));
}

void LengthDistributionAnalysis::processSequence(const Sequence &sequence)
{

    int seqLen = sequence.size();
    if (seqLen + 2 > mLengthCounts.length())
        mLengthCounts.resize(seqLen + 2);

    ++mLengthCounts[seqLen];

}

void LengthDistributionAnalysis::reset()
{
    mLengthCounts.clear();
    mGraphCounts.clear();
}

QWidget *LengthDistributionAnalysis::createResultWidget()
{

    QChartView * view = new QChartView;
    view->setRenderHint(QPainter::Antialiasing);

    if (mGraphCounts.isEmpty())
        return view;

    QLineSeries * serie = new QLineSeries;

    int yMax = 0;
    auto graph_count_it = mGraphCounts.begin();
    for (int i=mMin; i < mMax+mIntervale; i += mIntervale)
    {
        serie->append(i, *graph_count_it);
        if(yMax < *graph_count_it)
            yMax = *graph_count_it;
        graph_count_it++;
    }

    QChart * chart = new QChart ;
    chart->addSeries(serie);

    /* Create fake series for set the chart dimension */
    QLineSeries * fakeSerie = new QLineSeries();
    fakeSerie->append(0, 0);
    fakeSerie->append(mGraphCounts.size(), yMax);
    fakeSerie->setVisible(false);
    chart->addSeries(fakeSerie);

    chart->createDefaultAxes();
    chart->axisX()->setTitleText(tr("Position in read (bp)"));
    chart->axisY()->setTitleText(tr("Sequence count"));


    /* Set label of axis */
    dynamic_cast<QValueAxis*>(chart->axisX())->setMin(mMin);
    dynamic_cast<QValueAxis*>(chart->axisX())->setLabelFormat("%d");
    dynamic_cast<QValueAxis*>(chart->axisY())->setLabelFormat("%d");

    if (mGraphCounts.size() < 5)
        dynamic_cast<QValueAxis*>(chart->axisX())->setTickCount(mGraphCounts.size());

    chart->setTitle(tr("Distribution of sequence length over all sequences"));
    chart->setAnimationOptions(QChart::NoAnimation);
    // add Actions
    view->setRubberBand(QChartView::HorizontalRubberBand);
    QAction * zoomReset = new QAction(QFontIcon::icon(0xf002), tr("Zoom reset"), view);
    QAction * zoomIn    = new QAction(QFontIcon::icon(0xf00e), tr("Zoom in"), view);
    QAction * zoomOut   = new QAction(QFontIcon::icon(0xf010), tr("Zoom out"), view);

    connect(zoomReset, &QAction::triggered, [chart](){chart->zoomReset();});
    connect(zoomIn, &QAction::triggered, [chart](){chart->zoomIn();});
    connect(zoomOut, &QAction::triggered, [chart](){chart->zoomOut();});

    view->addAction(zoomReset);
    view->addAction(zoomIn);
    view->addAction(zoomOut);
    view->setChart(chart);

    return view;
}

void LengthDistributionAnalysis::after()
{
    computeDistribution();
}

void LengthDistributionAnalysis::computeDistribution()
{
    int maxLen = 0;
    int minLen = -1;

    //    qDebug()<<mLengthCounts.length();
    // Find the min and max lengths
    for (int i=0;i<mLengthCounts.length();i++) {
        if (mLengthCounts[i]>0) {
            if (minLen < 0) {
                minLen = i;
            }
            maxLen = i;
        }
    }

    // We put one extra category either side of the actual size
    if (minLen>0) minLen--;
    maxLen++;


    QVector<int> startAndInterval = sizeDistribution(minLen, maxLen);

    // Work out how many categories we need
    int categories = 0;
    int currentValue = startAndInterval[0];
    while (currentValue<= maxLen) {
        ++categories;
        currentValue+= startAndInterval[1];
    }

    mGraphCounts.resize(categories);

    for (int i=0;i<mGraphCounts.length();i++) {

        int minValue = startAndInterval[0]+(startAndInterval[1]*i);
        int maxValue = (startAndInterval[0]+(startAndInterval[1]*(i+1)))-1;

        if (maxValue > maxLen) {
            maxValue = maxLen;
        }

        for (int bp=minValue;bp<=maxValue;bp++) {
            if (bp < mLengthCounts.length()) {
                mGraphCounts[i] += mLengthCounts[bp];
            }
        }

        if (mGraphCounts[i] > mMax) mMax = mGraphCounts[i];
    }

    mIntervale = startAndInterval[1];
    mMin = minLen;
    mMax = maxLen;
}

QVector<int> LengthDistributionAnalysis::sizeDistribution(int min, int max)
{
    int base = 1;
    while (base > (max-min)) {
        base /= 10;
    }

    int interval =0;
    int starting =0;

    QVector<int> divisions ={1,2,5};

    // Little hack to exit the while loop..
    bool loop = true;
    while (loop) {
        for (int d=0;d<divisions.length();d++) {
            int tester = base * divisions[d];
            if (((max-min) / tester) <= 50) {
                interval = tester;
                loop = false;
                break;
            }
        }
        if (loop == true)
            base *=10;

    }

    //    // Now we work out the first value to be plotted
    int basicDivision = (int)(min/interval);

    int testStart = basicDivision * interval;

    starting = testStart;

    return {starting,interval};

}
