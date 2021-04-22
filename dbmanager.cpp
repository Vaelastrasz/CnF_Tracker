#include "dbmanager.h"

DBManager::DBManager() : m_showRecCounter(0),
  m_db(QSqlDatabase::addDatabase("QSQLITE")) {

    if (QFile::exists(DBCurrentPath)) {
        m_db.setDatabaseName(DBCurrentPath);
    } else {
        tryCreateNewDB();
    }

    if (!m_db.open()) {
        qDebug() << TEXT("Error: the connection to the database failed");
    } else {
        qDebug() << TEXT("Database: conection ok");
    }
}

DBManager::~DBManager() {

    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool DBManager::tryCreateNewDB() {

    DBCurrentPath = QDir::currentPath() + "/CarsDB.db";

    qDebug() << TEXT("DB not found!");
    QFile DBNewFile(DBCurrentPath);
    if (!DBNewFile.open(QFile::ReadWrite)) {
        qDebug() << TEXT("Can't create database at default location!");
        qDebug() << TEXT("DB Location : ") + DBCurrentPath;
        qDebug() << TEXT("Exiting...");
        QCoreApplication::quit();
    }
    DBNewFile.close();

    qDebug() << TEXT("DB not found! Creating database at default location...");
    qDebug() << TEXT("DB Location : ") + DBCurrentPath;
}

int DBManager::showRecCounter() const {

    return m_showRecCounter;
}

void DBManager::setShowRecCounter(int showRecCounter) {

    m_showRecCounter = showRecCounter;
}
