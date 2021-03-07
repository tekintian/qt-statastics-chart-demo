#include "myqchartpie.h"

MyQChartPie::MyQChartPie()
{
    series = new QPieSeries();
}


MyQChartPie::~MyQChartPie()
{
    delete series;
}

void  MyQChartPie::InitAx()
{
    InitDate();
    m_chart->addSeries(series);
    m_chart->setTitle(m_Title);

    m_chartView->setRenderHint(QPainter::Antialiasing);
}

void MyQChartPie::InitDate()
{
    i = 0;

    m_slice0 = new QPieSlice("text1", 1);
    m_slice1 = new QPieSlice("text2", 2);
    m_slice2 = new QPieSlice("text3", 3);
    //...
    QList<QPieSlice*> sliceList ;

    sliceList << m_slice0 << m_slice1 << m_slice2;
    series->append(sliceList);


    series->setLabelsVisible();

    //m_slice0 = series->slices().at(0);
}

void MyQChartPie::refreshDate()
{
    i++;
    if (i >= 10) i = 0;
    m_slice0->setValue(i);
}
void MyQChartPie::refreshAx()
{
    refreshDate();
    MyQChart::refreshAx();
}
