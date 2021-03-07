#include "myqchartspline.h"

MyQChartSpline::MyQChartSpline(QObject *parent)
{
    series = new QSplineSeries();
}

MyQChartSpline::~MyQChartSpline()
{
    delete series;
}

void MyQChartSpline::initAx()
{
    MyQChart::initAx();
    m_chartView->chart()->addSeries(series);
    m_chart->setAxisX(m_axisX, series);
    m_chart->setAxisY(m_axisY, series);
}

void MyQChartSpline::initData()
{
    i = 0;
}

void MyQChartSpline::refreshData()
{
    i++;
}
void MyQChartSpline::refreshAx()
{
    refreshData();
    addDate<int, float>(i, float(i) * float(i));	//曲线图刷新
    if (i <= 20)
    {
        MyQChart::refrshAx(0, 0, i, (i + 1)*(i + 1));
    }
    else {
        MyQChart::refrshAx(0, 0, i, (i + 1)*(i + 1) / 2);
    }
}
