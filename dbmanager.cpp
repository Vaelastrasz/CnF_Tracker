#include "dbmanager.h"

DBManager::DBManager() : m_showRecCounter(0),
  m_db(QSqlDatabase::addDatabase("QSQLITE")) {

    //TODO: update DBName from registry
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

    m_currentModel = new SqlTableModel(this, m_db);
    m_currentModel->setTable("CarsGeneralTable");
    m_currentModel->setEditStrategy(QSqlTableModel::OnRowChange);
    m_currentModel->setLimit(showRecCounter());
    m_currentModel->sort(4, Qt::DescendingOrder); //sort by date desc
}

DBManager::~DBManager() {

    if (m_db.isOpen()) {
        m_db.close();
    }
    if (m_currentModel) {
        delete m_currentModel;
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
        return false;
    }
    DBNewFile.close();

    qDebug() << TEXT("DB not found! Creating database at default location...");
    qDebug() << TEXT("DB Location : ") + DBCurrentPath;
    return true;
}

int DBManager::showRecCounter() const {

    return m_showRecCounter;
}

void DBManager::setShowRecCounter(int showRecCounter) {

    m_showRecCounter = showRecCounter;
}

QSqlTableModel* DBManager::getLastRecordsModel() {

    m_currentModel->setLimit(m_showRecCounter);
    if (m_currentModel->select()) {
        return m_currentModel;
    } else {
        qDebug() << "Error selecting values";
        return nullptr;
    }
}

void DBManager::addNewRecord(CarRecord *rec) {

    m_currentModel->addNewRecord(rec);
}
