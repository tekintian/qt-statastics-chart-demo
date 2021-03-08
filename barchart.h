#ifndef BARCHART_H
#define BARCHART_H

#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include "myqchart.h"

class BarChart : public MyQChart
{
    Q_OBJECT
public:
    BarChart();//注意这里不能有参数
     virtual ~BarChart();

    //初始数据设置
    void setData(QMap<QString, QList<qreal>> barMap, QStringList labelList);//设置列表数据

private:
    //主数据list
    QList<QBarSet *> m_barSetList;
    QStringList m_labelList;
    QBarSeries * m_series;

signals:

};

#endif // BARCHART_H
