#include "sqltablemodel.h"

SqlTableModel::SqlTableModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db) {

    m_limit = -1;
}

int SqlTableModel::limit() const {

    return m_limit;
}

void SqlTableModel::setLimit(int limit) {

    if(limit > 0) {
        m_limit = limit;
    }
}

bool SqlTableModel::addNewRecord() {

    QSqlRecord newRecord = record();
    newRecord.setValue("CarName", "Enter Car");
    newRecord.setValue("Driver", "Enter Driver");
    newRecord.setValue("TankCapacity", 0);
    newRecord.setValue("Mileage", 0);
    newRecord.setValue("Date", QDateTime::currentDateTime());
    newRecord.setValue("AlreadyRun", 0);
    newRecord.setValue("Fueling", 0);
    newRecord.setValue("FuelingNorm", 0);

    if (insertRecord(rowCount(), newRecord)) {
        qDebug() << "New record inserted";
    }
}

QString SqlTableModel::selectStatement() const {

    QString query = QSqlTableModel::selectStatement();
    if(m_limit > 0)
        query += QString(" LIMIT %1").arg(m_limit);
    return query;
}
