#include "myqchart.h"
#include "ui_myqchart.h"

MyQChart::MyQChart()
{
    m_chart = new QChart;
    m_chartView = new QChartView(m_chart);

    m_Title = "";
    m_XTitle = "";
    m_YTitle = "";

    m_XText = G;
    m_YText = G;

}

MyQChart::~MyQChart()
{
    delete m_chart;
    delete m_chartView;
}

void MyQChart::InitAx()
{
    InitDate();
    //建立坐标轴
    m_axisX = new QValueAxis;
    //m_axisX->setRange(0, 20);			//设置范围
    m_axisX->setLabelFormat(m_XText);		//设置刻度格式
        //m_axisX->setGridLineVisible(false);	//网格不可见
        //m_axisX->setTickCount(10);
        //m_axisX->setMinorTickCount(1);
    m_axisX->setTitleText(m_XTitle);				//描述

    m_axisY = new QValueAxis;
    //m_axisY->setRange(0, 10);			//设置范围
    m_axisY->setLabelFormat(m_YText);		//设置刻度格式
        //m_axisY->setGridLineVisible(false);	//网格不可见
        //m_axisY->setTickCount(10);
        //m_axisY->setMinorTickCount(1);
    m_axisY->setTitleText(m_YTitle);			//描述

    m_chart->addAxis(m_axisX, Qt::AlignBottom);		//下Qt::AlignBottom 上Qt::AlignTop
    m_chart->addAxis(m_axisY, Qt::AlignLeft);		//左 Qt::AlignLeft  右 Qt::AlignRight

    m_chart->setTitle(m_Title);
    m_chart->setAnimationOptions(QChart::SeriesAnimations);
    m_chart->legend()->hide();
    //m_chartView->chart()->addSeries(series);
    //m_chart->setAxisX(m_axisX, series);
    //m_chart->setAxisY(m_axisY, series);
}
void MyQChart::InitDate()
{
    ;
}
void MyQChart::refreshDate()
{
    ;
}
void MyQChart::refreshAx()
{
    m_chartView->chart()->update();
}

void MyQChart::setTitlrText(QString &title)
{
    m_Title = title;
}

void MyQChart::setAxisX(QString& XTitle, QString& XText)
{
    m_XTitle = XTitle;
    m_XText = XText;
}
void MyQChart::setAxisY(QString& YTitle, QString& YText)
{
    m_YTitle = YTitle;
    m_YText = YText;
}

QChartView * MyQChart::getView()
{
    return m_chartView;
}

void MyQChart::refrshAx(int minX, int minY, int maxX, int maxY)
{
    m_axisX->setRange(minX, maxX);
    m_axisY->setRange(minY, maxY);
}

