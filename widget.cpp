#include "widget.h"
#include "ui_widget.h"
#include "chartdemo.h"
#include "barchart.h"
#include <QRandomGenerator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("QT Statics Chart Demo"));

    //显示自定义图形
    showMyPies();

    cout<<D;

    //继承图形使用
    BarChart *myChartBar = new BarChart;

    QString barTtile =tr("Chart Bar");//设置标题
    myChartBar->setTitlrText(barTtile);
    QString xstr,ystr;
    xstr="Hello"; ystr="World";

    //准备数据
    QStringList labelList;
    labelList<<"Jon" << "Fed" << "Mar" << "Apr" << "Jun"<< "Sep"; // 统计月份 需要统计几个月就有几个数字, 需要和下面的numListx 数据条数对应


    QMap<QString, QList<qreal>> barMap;
    QList<qreal> numList1,numList2,numList3,numList4,numList5;

    barMap=generateRandBarMapData();

    // barMap["xxx"] 这里的xxx 即为需要在图上面显示的名称 , 后面的值是这个名称对应的数据 条数需要和labelList的大小一致

    myChartBar->setData(barMap,labelList);


    // 继承的chart bar 使用
    ui->vlayout_chart_bar->addWidget(myChartBar->getView());



    QTimer *timer = new QTimer(this);
    timer->start(2000);
    connect(timer,&QTimer::timeout,[=](){

        myChartBar->setData(generateRandBarMapData(),labelList);
        //必须先清除原来的item
        ui->vlayout_chart_pies->removeItem(ui->vlayout_chart_pies->itemAt(0));
        showMyPies();
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::showMyPies()
{

    //随机数生成器
    QRandomGenerator *rdg=QRandomGenerator::global();

    //定义图形用的数据变量
    QVector<int> intList;
    intList<< rdg->bounded(10,100)<< rdg->bounded(20,90)<< rdg->bounded(10,80);

    QStringList strList;
    strList<<"水果"<<"零食"<<"主食";

    double total=0;
    for(int sum:intList){
        total+=sum;
    }

    m_chart = new QChart();
    QPieSeries *series = new QPieSeries();

    QString pStr;
    for (int i=0; i<strList.size() ; i++ ) {
        //注意这里除法类型 如果都是整数返回结果为整数,小数全部为 0 , 所以必须由一个数是浮点数才能返回小数
         double _percentNum = intList.at(i)/total * 100;
         //格式化结果为2位小数
         pStr = pStr.sprintf("%.2f",_percentNum);

        QString _str = QString("%1:%2%").arg(strList.at(i)).arg(pStr);
        series->append(_str, intList.at(i));
    }



    series->setLabelsVisible(true);
    series->setUseOpenGL(true);
    series->slices().at(0)->setColor(QColor(13,128,217));   //设置颜色
    series->slices().at(0)->setLabelColor(QColor(13,128,217));

    series->slices().at(1)->setColor(QColor(69,13,217));
    series->slices().at(1)->setLabelColor(QColor(69,13,217));
    series->slices().at(2)->setColor(QColor(13,217,152));
    series->slices().at(2)->setLabelColor(QColor(13,217,152));

    m_chart->setTheme(QChart::ChartThemeLight);//设置白色主题
    m_chart->setDropShadowEnabled(true);//背景阴影
    m_chart->addSeries(series);//添加系列到QChart上

    m_chart->setTitle("饼状图"); //图形标题
    m_chart->setTitleBrush(QBrush(QColor(0,0,255)));//设置标题Brush
    m_chart->setTitleFont(QFont("Microsoft YaHei"));//设置标题字体

    //修改说明样式
    m_chart->legend()->setVisible(true); //设置图形数据说明是否显示
    m_chart->legend()->setAlignment(Qt::AlignBottom);//底部对齐  默认顶部对齐
    m_chart->legend()->setBackgroundVisible(true);//设置背景是否可视
    m_chart->legend()->setAutoFillBackground(true);//设置背景自动填充
    m_chart->legend()->setColor(QColor(222,233,251));//设置颜色
    m_chart->legend()->setLabelColor(QColor(0,100,255));//设置标签颜色
    m_chart->legend()->setMaximumHeight(50); //设置最大高度

    QChartView *chartView = new QChartView(m_chart);
    chartView->setRenderHint(QPainter::Antialiasing);

//    chartView->chart()->update();

    ui->vlayout_chart_pies->addWidget(chartView); //将图形添加到动态布局中

}

//生成随机数据
QMap<QString, QList<qreal> > Widget::generateRandBarMapData()
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


void Widget::on_pushButton_clicked()
{
    ChartDemo *cd = new ChartDemo(this);
    cd->show();

}
