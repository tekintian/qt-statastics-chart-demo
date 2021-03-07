#ifndef MYQCHARTSPLINE_H
#define MYQCHARTSPLINE_H

#include <myqchart.h>
#include <QSplineSeries>

class MyQChartSpline : public MyQChart
{
    Q_OBJECT
public:
    explicit MyQChartSpline(QObject *parent = nullptr);
    ~MyQChartSpline();

    virtual	void initAx();			//初始化坐标轴
    virtual	void initData();		//初始化数据
    virtual	void refreshData();		//刷新数据
    virtual void refreshAx();		//刷新坐标轴
    template <typename A_Val, typename B_Val>void addDate(A_Val valX, B_Val valY);
private:
    int i;							//test date
    QSplineSeries* series;

signals:

};


template <typename A_Val, typename B_Val>
void MyQChartSpline::addDate(A_Val valX, B_Val valY)
{
    series->append(valX, valY);
    m_chartView->chart()->update();
}

#endif // MYQCHARTSPLINE_H
