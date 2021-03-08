#ifndef CHARTDEMO_H
#define CHARTDEMO_H

#include <QMainWindow>

#include <QLineSeries>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QValueAxis>

#include <QTimer>
#include <QString>

//包含自定义的类
#include "myqchartspline.h"
#include "myqchartline.h"
#include "myqchartbar.h"
#include "myqchartpie.h"

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class ChartDemo;
}

class ChartDemo : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChartDemo(QWidget *parent = nullptr);
    ~ChartDemo();

    void initLayout(); //布局初始化
    void startTimer(const int mdelay);	//设置定时时间（ms）

    //template <typename A_Val> void refreshData(A_Val valX, A_Val valY, A_Val incrementX, const int num);

public slots:
    void timeoutHandlerSlots();

    QMap<QString, QList<qreal>> generateRandBarMapData();

private:
    MyQChartPie *m_myChartPie;
    MyQChartBar *m_myChartBar;
    MyQChartLine *m_myChartLine;
    MyQChartSpline *m_myChartSpline;

    QLineSeries *series;
    QVBoxLayout *m_layout;
    QHBoxLayout *m_hlayout1;
    QHBoxLayout *m_hlayout2;

    QValueAxis *m_axisX;
    QValueAxis *m_axisY;

    QTimer *timer;
    QWidget *widget;

private:
    Ui::ChartDemo *ui;
};

#endif // CHARTDEMO_H
