#include "barchart.h"

BarChart::BarChart()
{
    m_series = new QBarSeries();
}

BarChart::~BarChart()
{
    //清理
    m_barSetList.clear();

    delete m_series;
}

void BarChart::setData(QMap<QString, QList<qreal> > barMap, QStringList labelList)
{
    this->m_labelList = labelList;

    //如果有数据,先清除
    if(m_barSetList.size()>0){
        cout<<"delete";
        m_series->clear();
        m_barSetList.clear();
    }

    qreal maxRange=100;
    //遍历map
    for (QMap<QString, QList<qreal>>::Iterator iter=barMap.begin();iter !=barMap.end(); iter++) {
        //bar对象创建
        QBarSet *_bs = new QBarSet(iter.key());
        //循环QList并赋值给_bs
        _bs->append(iter.value());

        //放入到m_QBarSetList
        m_barSetList.push_back(_bs);
        //放入series
        m_series->append(_bs);

        //找最大数
        for(qreal _max:iter.value()){
            if(_max>maxRange) maxRange=_max;
        }

    }


    //设置Y坐标范围 最大数 +10

    //这里解决不能重复添加Series问题,如果存在,采用替换
    if(m_chart->series().size()){
        cout<<"replace series!";
        m_chart->series().replace(0,m_series);

        m_chartView->chart()->update(); //替换后需要刷新
        m_chart->update();

        cout<<m_chart->series().size();
    }else{
        m_chart->addSeries(m_series);
    }

    m_chart->setTitle(m_title);
    m_chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis * axisx = new QBarCategoryAxis();
    axisx->append(m_labelList);

    m_chart->createDefaultAxes();
    m_chart->setAxisX(axisx);

    m_chart->legend()->setVisible(true);					//设置图例为显示状态
    m_chart->legend()->setAlignment(Qt::AlignBottom);		//设置图例的显示位置在底部

    m_chartView->setRenderHints(QPainter::Antialiasing);	//抗锯齿
}
