QT       += core gui sql

#自行增加的类库
QT  += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barchart.cpp \
    chartdemo.cpp \
    driver/mysqldriver.cpp \
    main.cpp \
    myqchart.cpp \
    myqchartbar.cpp \
    myqchartline.cpp \
    myqchartpie.cpp \
    myqchartspline.cpp \
    widget.cpp

HEADERS += \
    barchart.h \
    chartdemo.h \
    driver/mysqldriver.h \
    myqchart.h \
    myqchartbar.h \
    myqchartline.h \
    myqchartpie.h \
    myqchartspline.h \
    widget.h

FORMS += \
    chartdemo.ui \
    widget.ui

TRANSLATIONS += \
    qt-chart_zh_CN.ts \
    qt-chart_en.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
