#ifndef MYQCHARTPIE_H
#define MYQCHARTPIE_H

#include <myqchart.h>
#include <QPieSeries>
#include <QPieSlice>

class MyQChartPie :
    public MyQChart
{
public:
    MyQChartPie();
    virtual ~MyQChartPie();
    virtual	void initAx();			//初始化坐标轴
    virtual	void initData();		//初始化数据
    virtual	void refreshData();		//刷新数据
    virtual void refreshAx();		//刷新坐标轴;
private:
    int i;
    QPieSlice *m_slice0;
    QPieSlice *m_slice1;
    QPieSlice *m_slice2;
    //....

    QPieSeries *series;
};

#endif // MYQCHARTPIE_H
