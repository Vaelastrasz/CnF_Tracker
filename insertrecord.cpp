#include "insertrecord.h"
#include "ui_insertrecord.h"

InsertRecord::InsertRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertRecord) {

    ui->setupUi(this);
    applyStyleSheet();
    this->setWindowIcon(QIcon(":/icons/plus.png"));
    this->setWindowTitle("Add new record");
}

InsertRecord::~InsertRecord() {

    delete ui;
}

void InsertRecord::on_buttonBox_accepted() {

    //TODO: Add QCompleter
    //TODO: Add QValidator

    CarRecord* newRec = new CarRecord;
    newRec->carName = ui->edit_carName->text();
    newRec->driver = ui->edit_driver->text();
    newRec->tankCapacity = ui->edit_tankCap->text().toInt();
    newRec->mileage = ui->edit_mileage->text().toInt();
    newRec->date = QDate::fromString(ui->edit_date->text(), "dd/MM/yyyy");
    newRec->alreadyRun = ui->edit_alreadyRun->text().toInt();
    newRec->fueling = ui->edit_fueling->text().toInt();
    newRec->fuelingNorm = ui->edit_fuelingNorm->text().toInt();
    clearAllEdit();
    emit insertNewRecord(newRec);
    delete newRec;
}

void InsertRecord::on_buttonBox_rejected() {

    clearAllEdit();
}

void InsertRecord::applyStyleSheet() {

    QFile style(":/Medize.qss");
    style.open(QIODevice::ReadOnly);
    QString styleSheet = QString(style.readAll());
    style.close();
    this->setStyleSheet(styleSheet);
}

void InsertRecord::clearAllEdit() {

    ui->edit_carName->clear();
    ui->edit_driver->clear();
    ui->edit_tankCap->clear();
    ui->edit_mileage->clear();

    ui->edit_alreadyRun->clear();
    ui->edit_fueling->clear();
    ui->edit_fuelingNorm->clear();
}
