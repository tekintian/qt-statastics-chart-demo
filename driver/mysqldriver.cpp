#include "mysqldriver.h"

#include <QDebug>
#define cout qDebug()

//初始化数据库连接 仅初始化一次
QSqlDatabase MysqlDriver::db=MysqlDriver::getConnect();

MysqlDriver::MysqlDriver(QObject *parent) : QObject(parent)
{

}

//执行SQL
QSqlQuery MysqlDriver::execSql(QString sql)
{
    QSqlQuery query;
    query.prepare(sql);
    query.exec();
    return query;
}

 QMap<QString, QVariant> MysqlDriver::getRow(QString tableName, QString fieldsStr, QString wherStr)
{
    QString  sql = QString("select %1 from %2 ").arg(fieldsStr).arg(tableName);
    if(!wherStr.isEmpty()){
        sql += wherStr;
    }

    QSqlQuery query;
    query.prepare(sql);
    query.exec();

    QStringList fieldList = fieldsStr.split(","); //将字符串分隔为list


    QMap<QString, QVariant> map;

    cout<< "row"<<fieldList.size();

    cout<< "query"<<query.size();

    while (query.next()) {

        //每条数据循环一次
        for(int j=0; j<fieldList.size(); j++){

            cout<<"for"<< query.value(fieldList.at(j));

            map[fieldList.at(j)] = query.value(fieldList.at(j));
        }
    }

    cout<<"mapsize="<<map.size();
    return map;

}

QList<QMap<QString, QVariant>> MysqlDriver::getList(QString tableName, QString fieldsStr, QString wherStr)
{
    QString  sql = QString("select DISTINCT %1 from %2 ").arg(fieldsStr).arg(tableName);
    if(!wherStr.isEmpty()){
        sql += wherStr;
    }

    QSqlQuery query;
    query.prepare(sql);
    query.exec();

    QStringList fieldList = fieldsStr.split(","); //将字符串分隔为list

    QList<QMap<QString, QVariant>> list;

    QMap<QString, QVariant> map;


    while (query.next()) {
        //每条数据循环一次
        for(int j=0;j<fieldList.size();j++){
            map[fieldList.at(j)] = query.value(fieldList.at(j));
        }
        list.push_back(map); //每个list都是一个map
    }

    return list;
}

QSqlDatabase MysqlDriver::getConnect()
{
    static QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //数据库连接
    db.setHostName("localhost");
    db.setUserName("qt");
    db.setPassword("qt888");
    db.setDatabaseName("qt_car");
    db.setPort(3306);

    if(db.open()){
        qDebug()<<"连接成功!";
    }else{
        qDebug()<<"连接失败:"<< db.lastError().text();
    }

    //数据库连接 end
    return db;
}
