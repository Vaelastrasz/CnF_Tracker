#include "sqltablemodel.h"

SqlTableModel::SqlTableModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db) {

    m_limit = -1;
}

int SqlTableModel::limit() const {

    return m_limit;
}

void SqlTableModel::setLimit(int newLimit) {

    if(newLimit > 0) {
        m_limit = newLimit;
    }
}

bool SqlTableModel::addNewRecord(CarRecord* rec) {

    QSqlRecord newRecord = record();
    newRecord.setValue("CarName", rec->carName);
    newRecord.setValue("Driver", rec->driver);
    newRecord.setValue("TankCapacity", rec->tankCapacity);
    newRecord.setValue("Mileage", rec->mileage);
    newRecord.setValue("Date", QDateTime::currentDateTime()); //TODO: CHANGE
    newRecord.setValue("AlreadyRun", rec->alreadyRun);
    newRecord.setValue("Fueling", rec->fueling);
    newRecord.setValue("FuelingNorm", rec->fuelingNorm);

    if (insertRecord(rowCount(), newRecord)) {
        qDebug() << "New record inserted";
        return true;
    }

    return false;
}

QString SqlTableModel::selectStatement() const {

    QString query = QSqlTableModel::selectStatement();
    if(m_limit > 0)
        query += QString(" LIMIT %1").arg(m_limit);
    return query;
}
