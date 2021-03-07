#ifndef MYSQLDRIVER_H
#define MYSQLDRIVER_H

#include <QObject>
#include <QtSql>

class MysqlDriver : public QObject
{
    Q_OBJECT
public:
    explicit MysqlDriver(QObject *parent = nullptr);

    static QSqlQuery execSql(QString sql);//执行sql
    static QMap<QString, QVariant> getRow(QString tableName, QString fieldsStr, QString wherStr="");//获取一条数据
    static QList<QMap<QString, QVariant>> getList(QString tableName, QString fieldsStr, QString wherStr="");//获取多条数据

public:
     static QSqlDatabase db;


private:
    static QSqlDatabase getConnect();

signals:

};

#endif // MYSQLDRIVER_H
