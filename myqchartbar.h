#ifndef MYQCHARTBAR_H
#define MYQCHARTBAR_H

#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include "myqchart.h"

class MyQChartBar :
    public MyQChart
{
public:
    MyQChartBar();
    virtual ~MyQChartBar();

    virtual	void initAx();			//初始化坐标轴
    virtual	void initData();		//初始化数据
    virtual	void refreshData();		//刷新数据
    virtual void refreshAx();		//刷新坐标轴

    int i;							//test val;
private:
    QBarSet * set0; //...
    QBarSet * set1; //...
    QBarSet * set2; //...
    QBarSet * set3; //...
    QBarSet * set4; //...

    QStringList str;

    QBarSeries * series;
};

#endif // MYQCHARTBAR_H
