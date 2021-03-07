#ifndef MYQCHART_H
#define MYQCHART_H

#include <QChart>
#include <QChartView>
#include <QValueAxis>
#include <QString>
#include <QTimer>

QT_CHARTS_USE_NAMESPACE

#define F2	"%.2f"
#define D	"%d"
#define G   "%.2g"

class MyQChart:public QWidget
{
public:
    MyQChart();
    virtual ~MyQChart();

    QChartView * getView();

    virtual	void InitAx();			//初始化坐标轴
    virtual	void InitDate();		//初始化数据
    virtual	void refreshDate();		//刷新数据
    virtual void refreshAx();		//刷新坐标轴
    void refrshAx(int minX, int minY, int maxX, int maxY);			//刷新坐标轴刻度

    void setTitlrText(QString &title);
    void setAxisX(QString &XTitle, QString &XText);
    void setAxisY(QString &YTitle, QString &YText);

    QChart *m_chart;
    QChartView *m_chartView;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;

    QString m_Title;
    QString m_XTitle;
    QString m_YTitle;

    QString m_XText;
    QString m_YText;
};


#endif // MYQCHART_H
