#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QCoreApplication>

#include "sqltablemodel.h"

class DBManager : QObject
{
    Q_OBJECT
public:
    DBManager();
    ~DBManager();
    bool tryCreateNewDB();
    int showRecCounter() const;
    void setShowRecCounter(int showRecCounter);
    QSqlTableModel *getLastRecordsModel();
    bool addNewRecord();

private:
    int m_showRecCounter;
    QSqlDatabase m_db;
    SqlTableModel* m_currentModel;
    QString DBCurrentPath = DB_DEFAULT_PATH;
};

#endif // DBMANAGER_H
