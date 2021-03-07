#include "widget.h"
#include "ui_widget.h"
#include "chartdemo.h"
#include "myqchartbar.h"
#include <QRandomGenerator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("QT Statics Chart Demo"));

    //显示自定义图形
    showMyPies();


    //继承图形使用
    MyQChartBar *myCharBar = new MyQChartBar;
    myCharBar->initAx(); //初始化数据
    QString barTtile =tr("Chart Bar");//设置标题
    myCharBar->setTitlrText(barTtile);

    // 继承的chart bar 使用
    ui->vlayout_chart_bar->addWidget(myCharBar->getView());



    QTimer *timer = new QTimer(this);
    timer->start(2000);
    connect(timer,&QTimer::timeout,[=](){
        myCharBar->refreshData();
        myCharBar->refreshAx();
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
    QRandomGenerator *rdg = QRandomGenerator::global();


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


void Widget::on_pushButton_clicked()
{
    ChartDemo *cd = new ChartDemo(this);
    cd->show();

}
