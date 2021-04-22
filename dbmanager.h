#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

#include <QFile>
#include <QDir>

#include <QDebug>
#include <QObject>
#include <QCoreApplication>
#include "globalscope.h"

class DBManager : QObject
{
    Q_OBJECT
public:
    DBManager();
    ~DBManager();
    bool tryCreateNewDB();
    int showRecCounter() const;
    void setShowRecCounter(int showRecCounter);

private:
    QSqlDatabase m_db;
    int m_showRecCounter;
    QString DBCurrentPath = DB_DEFAULT_PATH;
};

#endif // DBMANAGER_H
