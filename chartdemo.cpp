#include "chartdemo.h"
#include "ui_chartdemo.h"
#include <QDateTime>

#include <QRandomGenerator>

ChartDemo::ChartDemo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChartDemo)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("图表控件封装继承 演示 QT Chart Demo"));

    //对象初始化
    m_myChartPie = new MyQChartPie;
    m_myChartBar = new MyQChartBar;
    m_myChartLine = new MyQChartLine;
    m_myChartSpline = new MyQChartSpline;

    initLayout();

    //数据初始化
    m_myChartPie->initAx();
    m_myChartBar->initAx();
    m_myChartLine->initAx();
    m_myChartSpline->initAx();

    startTimer(1000);
    timeoutHandlerSlots();//默认初始化


}

ChartDemo::~ChartDemo()
{
    delete ui;
}

//布局初始化
void ChartDemo::initLayout()
{
    //指针置空
    widget = NULL;
    m_layout = NULL;

    //设置图形标题
    QString splineTtile =tr("Chart Spline");
    m_myChartSpline->setTitlrText(splineTtile);

    QString barTtile =tr("Chart Bar");
    m_myChartBar->setTitlrText(barTtile);

    QString lineTtile =tr("Chart Line");
    m_myChartLine->setTitlrText(lineTtile);

    QString pieTtile =tr("Chart Pie");
    m_myChartPie->setTitlrText(pieTtile);

#if 0
    //在mainWindow中加入widget，展示
    widget = new QWidget();
    this->setCentralWidget(widget);
    m_layout = new QVBoxLayout();
    m_hlayout1 = new QHBoxLayout();
    m_hlayout2 = new QHBoxLayout();

    m_hlayout1->addWidget(m_myChartPie->getView());
    m_hlayout1->addWidget(m_myChartBar->getView());
    m_hlayout2->addWidget(m_myChartLine->getView());
    m_hlayout2->addWidget(m_myChartSpline->getView());

    m_layout->addLayout(m_hlayout1);
    m_layout->addLayout(m_hlayout2);


    centralWidget()->setLayout(m_layout);
#endif


    // 自定义UI界面显示
    ui->vlayout_pie->addWidget(m_myChartPie->getView());
    ui->vlayout_bar->addWidget(m_myChartBar->getView());
    ui->vlayout_line->addWidget(m_myChartLine->getView());
    ui->vlayout_spline->addWidget(m_myChartSpline->getView());


}

void ChartDemo::startTimer(const int mdelay)
{
    timer = new QTimer(this); //初始化时间对象
    timer->start(mdelay); //开启时间

    //绑定超时信号  Lambda表达式
    connect(timer,&QTimer::timeout,[=](){
        timeoutHandlerSlots();

    });

    //传统写法
   // connect(timer,&QTimer::timeout,this,&ChartDemo::timeoutHandlerSlots);
}

void ChartDemo::timeoutHandlerSlots()
{
    m_myChartPie->refreshAx();		//曲线图刷新
    m_myChartBar->refreshAx();		//柱状图刷新
    m_myChartLine->refreshAx();		//饼状图刷新
    m_myChartSpline->refreshAx();

    //m_Mychart->m_axisX->setRange(0, i);
    //m_Mychart->m_axisY->setRange(0, i);

    // 当前时间显示
    QDateTime curTime = QDateTime::currentDateTime();
    //显示时间，格式为：年-月-日 时：分：秒 周几
    QString curTimeStr = curTime.toString("yyyy-MM-dd hh:mm:ss ddd");
    //时间显示格式可自由设定，如hh:mm ddd 显示 时：分 周几
    //具体格式见函数QString QDateTime::​toString(const QString & format) const
    ui->label_time->setText(QString("<h1 align=\"center\">当前时间:<span style=\" font-size:18pt; color:#405cff; front-weight:bold;\">%1</span></h1>").arg(curTimeStr));

}

//生成随机数据
QMap<QString, QList<qreal> > ChartDemo::generateRandBarMapData()
{

    //随机数生成器
    QRandomGenerator *rdg=QRandomGenerator::global();

    QMap<QString, QList<qreal>> barMap;
    QList<qreal> numList1,numList2,numList3,numList4,numList5;

    barMap["Tekin"] = numList1<< rdg->bounded(60,90) << rdg->bounded(30,100) << rdg->bounded(10,90) << rdg->bounded(10,90) << rdg->bounded(10,90)<< rdg->bounded(60,90);
    barMap["Andy"] = numList2 << rdg->bounded(60,90) << rdg->bounded(60,90) << rdg->bounded(10,90) << rdg->bounded(10,90) << rdg->bounded(10,90)<< rdg->bounded(20,90);
    barMap["Alex"] = numList3<< rdg->bounded(60,90) << rdg->bounded(60,90) << rdg->bounded(10,90) << rdg->bounded(10,90)<< rdg->bounded(10,90)<< rdg->bounded(30,90);
    barMap["Jone"] = numList4<< rdg->bounded(60,90) << rdg->bounded(60,90) << rdg->bounded(10,90) << rdg->bounded(10,90)<< rdg->bounded(10,90)<< rdg->bounded(5,90);
    barMap["jack"] = numList5<< rdg->bounded(60,90) << rdg->bounded(60,90) << rdg->bounded(10,90) << rdg->bounded(10,90)<< rdg->bounded(10,90)<< rdg->bounded(1,90);
    return barMap;
}

