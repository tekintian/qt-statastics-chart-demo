#ifndef MYQCHART_H
#define MYQCHART_H

#include <QWidget>
#include <QChart>
#include <QChartView>
#include <QValueAxis>
#include <QString>
#include <QTimer>

QT_CHARTS_USE_NAMESPACE

#include <QDebug>
#define cout qDebug()

//#define F2 "%.2f"
//#define D "%d"
//#define G "%.2g"

class MyQChart:public QWidget
{
public:
    MyQChart();
    virtual ~MyQChart();

    QChartView * getView();

    virtual	void initAx();			//初始化坐标轴
    virtual	void initData();		//初始化数据
    virtual	void refreshData();		//刷新数据
    virtual void refreshAx();		//刷新坐标轴
    void refrshAx(int minX, int minY, int maxX, int maxY);			//刷新坐标轴刻度

    void setTitlrText(QString &title);
    void setAxisX(QString &xTitle, QString &xText);
    void setAxisY(QString &yTitle, QString &yText);

    QChart *m_chart;
    QChartView *m_chartView;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;

    QString m_title;
    QString m_xTitle;
    QString m_yTitle;

    QString m_xText;
    QString m_yText;
};


#endif // MYQCHART_H
