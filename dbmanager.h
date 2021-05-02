#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQueryModel>

#include <QFile>
#include <QDir>
#include <QThread>

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
    QSqlQueryModel* getLastRecordsModel();

private:
    int m_showRecCounter;
    QSqlDatabase m_db;
    QSqlQueryModel* m_currentModel;
    QString DBCurrentPath = DB_DEFAULT_PATH;
};

#endif // DBMANAGER_H
