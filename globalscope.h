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
#include <QThread>

#define TEXT(x) tr(x)
#define DB_DEFAULT_PATH QString("D:\\Projects\\CnF_Tracker\\resources\\CarsDB.db")
#define UI_MODEL ui->tv_mainTableView->model()
#define UI_TABLE ui->tv_mainTableView

struct TypicalRecord {
    QString   carName;
    QString   driver;
    int       tankCapacity;
    int       mileage;
    QDateTime date;
    int       alreadyRun;
    int       fueling;
    int       fuelingNorm;
};

#endif // GLOBALSCOPE_H
