#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_dbHnd(new DBManager()),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    startup();
}

MainWindow::~MainWindow() {

    if (m_dbHnd) {
        delete m_dbHnd;
    }
    delete ui;
}

void MainWindow::on_actionMaximizeWindow_toggled(bool arg1) {

    if (arg1) {
        this->setWindowState(Qt::WindowMaximized);
    } else {
        this->setWindowState(Qt::WindowNoState);
    }
}

void MainWindow::on_actionMinimizeWindow_triggered() {

    this->setWindowState(Qt::WindowMinimized);
}

void MainWindow::startup() {

    this->setWindowTitle(TEXT("C&F Tracker v 0.0.1"));
    this->setWindowIcon(QIcon(":/icons/truck.png"));
    ui->btn_addRecord->setIcon(QIcon(":/icons/plus.png"));
    applyStyleSheet();
    on_rb_show1d_clicked();
}

void MainWindow::applyStyleSheet() {

    QFile style(":/Medize.qss");
    style.open(QIODevice::ReadOnly);
    QString styleSheet = QString(style.readAll());
    style.close();
    this->setStyleSheet(styleSheet);
}

void MainWindow::fitModelToView() {

    int colCnt = ui->tv_mainTableView->model()->columnCount();
    int* tableSizeArray = new int[colCnt];
    ui->tv_mainTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < colCnt - 1; i++) {
        tableSizeArray[i] = ui->tv_mainTableView->horizontalHeader()->sectionSize(i);
    }

    ui->tv_mainTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    for (int i = 0; i < colCnt - 1; i++) {
        ui->tv_mainTableView->horizontalHeader()->sectionResized(i, 0, tableSizeArray[i]);
        qDebug() << ui->tv_mainTableView->horizontalHeader()->sectionSize(i);
    }

    delete[] tableSizeArray;
}

void MainWindow::applyAndFitModel(QSqlQueryModel* model) {

    ui->tv_mainTableView->setModel(model);
    fitModelToView();
}

void MainWindow::on_actionSwitchTab_triggered() {

    int idx = ui->tabs->currentIndex();

    if (idx == ui->tabs->count() - 1) {
        ui->tabs->setCurrentIndex(0);
    } else {
        ui->tabs->setCurrentIndex(++idx);
    }
}

void MainWindow::on_rb_show1d_clicked() {

    m_dbHnd->setShowRecCounter(ui->rb_show1d->text().toInt());
    applyAndFitModel(m_dbHnd->getLastRecordsModel());
}

void MainWindow::on_rb_show1h_clicked() {

    m_dbHnd->setShowRecCounter(ui->rb_show1h->text().toInt());
    applyAndFitModel(m_dbHnd->getLastRecordsModel());
}

void MainWindow::on_rb_show1k_clicked() {

    m_dbHnd->setShowRecCounter(ui->rb_show1k->text().toInt());
    applyAndFitModel(m_dbHnd->getLastRecordsModel());
}

void MainWindow::on_actionExit_triggered() {

    QCoreApplication::exit();
}

void MainWindow::on_tabs_currentChanged(int index) {

    if (index == 0) {
        //update db rec show last
        applyAndFitModel(m_dbHnd->getLastRecordsModel());
    }
}
