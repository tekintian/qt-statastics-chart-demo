#include "myqchartbar.h"


#include <QDebug>


MyQChartBar::MyQChartBar()
{
    set0 = new QBarSet("Jane");
    set1 = new QBarSet("Jone");
    set2 = new QBarSet("Mary");
    set3 = new QBarSet("Alsex");
    set4 = new QBarSet("Summer");

    series = new QBarSeries();
}


MyQChartBar::~MyQChartBar()
{
    delete set0;
    delete set1;
    delete set2;
    delete set3;
    delete set4;
    delete series;
}

void MyQChartBar::InitDate()
{
    i = 0;

    *set0 << 1 << 2 << 3 << 4 << 10;
    *set1 << 2 << 3 << 4 << 10 << 4;
    *set2 << 3 << 4 << 10 << 4 << 3;
    *set3 << 4 << 10 << 4 << 3 << 2;
    *set4 << 10 << 4 << 3 << 2 << 1;

    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    str << "Jan" << "Fed" << "Mar" << "Apr" << "Jun";
}

void MyQChartBar::InitAx()
{
    InitDate();
    m_chart->addSeries(series);
    m_chart->setTitle(m_Title);
    m_chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis * axisx = new QBarCategoryAxis();
    axisx->append(str);
    m_chart->createDefaultAxes();
    m_chart->setAxisX(axisx);

    m_chart->legend()->setVisible(true);					//设置图例为显示状态
    m_chart->legend()->setAlignment(Qt::AlignBottom);		//设置图例的显示位置在底部

    m_chartView->setRenderHints(QPainter::Antialiasing);	//抗锯齿
}

void MyQChartBar::refreshDate()
{
    i++;
    if (i >= 10) i = 0;
    qDebug() << i << "updere !!";
    //修改数据
    set0->remove(0);
    set0->insert(0, i);

    set0->remove(2);
    set0->insert(2, i);

    m_chartView->chart()->update();
}

void MyQChartBar::refreshAx()
{
    refreshDate();
    MyQChart::refreshAx();
}
