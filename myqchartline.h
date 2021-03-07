#ifndef MYQCHARTLINE_H
#define MYQCHARTLINE_H

#include "myqchart.h"
#include <QLineSeries>

class MyQChartLine :
    public MyQChart
{
public:
    MyQChartLine();
    virtual ~MyQChartLine();
    virtual	void InitAx();			//初始化坐标轴
    virtual	void InitDate();		//初始化数据
    virtual	void refreshDate();		//刷新数据
    virtual void refreshAx();		//刷新坐标轴
    template <typename A_Val, typename B_Val>void addDate(A_Val valX, B_Val valY);
private:
    int i;
    QLineSeries* series;
};

template <typename A_Val, typename B_Val>
void MyQChartLine::addDate(A_Val valX, B_Val valY)
{
    series->append(valX, valY);
    m_chartView->chart()->update();
}


#endif // MYQCHARTLINE_H
