#ifndef GLOBALSCOPE_H
#define GLOBALSCOPE_H

#include <QSqlTableModel>
#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQueryModel>

#include <QString>
#include <QDebug>
#include <QDateTime>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QIcon>
#include <QThread>
#include <QCalendarWidget>
#include <QTableView>

#define TEXT(x) tr(x)
#define DB_DEFAULT_PATH QString("D:\\Projects\\CnF_Tracker\\resources\\CarsDB.db")
#define UI_TABLE_WIDGET ui->tv_mainTableView
#define UI_FILTER_WIDGET ui->tv_result

struct CarRecord {
    QString   carName;
    QString   driver;
    int       tankCapacity;
    int       mileage;
    QDate     date;
    int       alreadyRun;
    int       fueling;
    int       fuelingNorm;
};

#endif // GLOBALSCOPE_H
