#include "dbmanager.h"

DBManager::DBManager() {

    m_showRecCounter = 0;
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(DB_DEFAULT_PATH);

    if (!m_db.open()) {
        qDebug() << "Error: the connection to the database failed";
    } else {
        qDebug() << "Database: conection ok";
    }
}

int DBManager::showRecCounter() const {

    return m_showRecCounter;
}

void DBManager::setShowRecCounter(int showRecCounter) {

    m_showRecCounter = showRecCounter;
}
