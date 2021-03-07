#include "myqchartspline.h"

#include <QSplineSeries>
#include "myqchart.h"

MyQChartSpline::MyQChartSpline()
{
    series = new QSplineSeries();
}


MyQChartSpline::~MyQChartSpline()
{
    delete series;
}

void MyQChartSpline::InitAx()
{
    MyQChart::InitAx();
    m_chartView->chart()->addSeries(series);
    m_chart->setAxisX(m_axisX, series);
    m_chart->setAxisY(m_axisY, series);
}

void MyQChartSpline::InitDate()
{
    i = 0;
}

void MyQChartSpline::refreshDate()
{
    i++;
}
void MyQChartSpline::refreshAx()
{
    refreshDate();
    addDate<int, float>(i, float(i) * float(i));	//曲线图刷新
    if (i <= 20)
    {
        MyQChart::refrshAx(0, 0, i, (i + 1)*(i + 1));
    }
    else {
        MyQChart::refrshAx(0, 0, i, (i + 1)*(i + 1) / 2);
    }
}
