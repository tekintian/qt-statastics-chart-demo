#ifndef MYQCHARTSPLINE_H
#define MYQCHARTSPLINE_H

#include <QSplineSeries>
#include "myqchart.h"

class MyQChartSpline :
    public MyQChart
{
public:
    MyQChartSpline();
    virtual ~MyQChartSpline();
    virtual	void InitAx();			//初始化坐标轴
    virtual	void InitDate();		//初始化数据
    virtual	void refreshDate();		//刷新数据
    virtual void refreshAx();		//刷新坐标轴
    template <typename A_Val, typename B_Val>void addDate(A_Val valX, B_Val valY);
private:
    int i;							//test date
    QSplineSeries* series;
};

template <typename A_Val, typename B_Val>
void MyQChartSpline::addDate(A_Val valX, B_Val valY)
{
    series->append(valX, valY);
    m_chartView->chart()->update();
}

#endif // MYQCHARTSPLINE_H
