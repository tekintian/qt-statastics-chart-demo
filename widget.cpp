#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

#if 1
    m_chart = new QChart();

    QPieSeries *series = new QPieSeries();
    series->append("水果:30%",10);     //添加标签"水果:30%" 和 百分值30%
    series->append("零食:20%",50);
    series->append("主食:50%",100);

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

    // 代码创建动态虚拟 QVBoxLayout 然后添加到自定义的 myWidget中
    QWidget *myv = ui->myWidget;
    QVBoxLayout *pVLayout = new QVBoxLayout(myv);
    pVLayout->addWidget(chartView); //将图形添加到动态布局中

    //使用UI界面上的 动态虚拟layout
//     ui->vlayout_chart_pies->addWidget(chartView);


    resize(960, 720);
#endif

}

Widget::~Widget()
{
    delete ui;
}

