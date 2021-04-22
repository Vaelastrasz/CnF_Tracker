#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QObject>

#define DB_DEFAULT_PATH QString("D:\\Projects\\CnF_Tracker\\resources\\CarsDB.db")

class DBManager : QObject
{
Q_OBJECT
public:
    DBManager();
    int showRecCounter() const;
    void setShowRecCounter(int showRecCounter);

private:
    QSqlDatabase m_db;
    int m_showRecCounter;
};

#endif // DBMANAGER_H
