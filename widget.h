#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QtCharts>
// 这个宏是 using namespace QtCharts 的定义  也可以直接使用namespace; 不指定这个会发生编译错误
QT_CHARTS_USE_NAMESPACE


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void showMyPies();


private slots:
    void on_pushButton_clicked();

private:
    //成员属性定义
    QChart *m_chart;


private:
    Ui::Widget *ui;

};
#endif // WIDGET_H
