#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_dbHnd(new DBManager()),
    m_insertRecWindow(new InsertRecord),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
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

    this->setWindowTitle(TEXT("C&F Tracker v0.0.1"));
    this->setWindowIcon(QIcon(":/icons/truck.png"));
    ui->btn_addRecord->setIcon(QIcon(":/icons/plus.png"));
    ui->btn_refresh->setIcon(QIcon(":/icons/refresh.png"));
    ui->btn_apply->setIcon(QIcon(":/icons/apply.png"));

    connect(m_insertRecWindow, &InsertRecord::insertNewRecord, m_dbHnd, &DBManager::addNewRecord);
    connect(m_insertRecWindow, &InsertRecord::insertNewRecord, this, &MainWindow::on_btn_refresh_clicked);
    connect(this, &MainWindow::setStyleSignal, m_insertRecWindow, &InsertRecord::applyStyleSheet);
    connect(this, &MainWindow::getNames, m_dbHnd, &DBManager::processCarNamesRequest);
    connect(m_dbHnd, &DBManager::sendCarNames, this, &MainWindow::setUniqueNamesToCombo);
    connect(m_dbHnd, &DBManager::sendCarNames, m_insertRecWindow, &InsertRecord::setUniqueNamesToCombo);

    ui->edit_startDate->setCalendarPopup(true);
    ui->edit_startDate->calendarWidget()->setFirstDayOfWeek(Qt::Monday);
    ui->edit_endDate->setCalendarPopup(true);
    ui->edit_endDate->calendarWidget()->setFirstDayOfWeek(Qt::Monday);

    applyStyleSheet(QString(":/Medize.qss"));
    on_rb_show1k_clicked();
}

void MainWindow::applyStyleSheet(QString fileName) {

    QFile style(fileName);
    style.open(QIODevice::ReadOnly);
    QString styleSheet = QString(style.readAll());
    style.close();
    this->setStyleSheet(styleSheet);
    emit setStyleSignal(fileName);
}

void MainWindow::fitModelToView() {

    int colCnt;
    if (!UI_MODEL)
        return;
    colCnt = UI_MODEL->columnCount();
    int* tableSizeArray = new int[colCnt];
    UI_TABLE->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < colCnt - 1; i++) {
        tableSizeArray[i] = UI_TABLE->horizontalHeader()->sectionSize(i);
    }

    UI_TABLE->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    for (int i = 0; i < colCnt - 1; i++) {
        emit UI_TABLE->horizontalHeader()->sectionResized(i, 0, tableSizeArray[i]);
        qDebug() << UI_TABLE->horizontalHeader()->sectionSize(i);
    }

    delete[] tableSizeArray;
}

void MainWindow::applyAndFitModel(QSqlTableModel* model) {

    if (!model) return;
    UI_TABLE->setModel(model);
    fitModelToView();
}

void MainWindow::fillComboNames() {

    emit getNames();
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
        applyAndFitModel(m_dbHnd->getLastRecordsModel());
    }
    if (index == 1) {
        fillComboNames();
    }
}

void MainWindow::showEvent(QShowEvent *event) {

    Q_UNUSED(event);
    startup();
}

void MainWindow::resizeEvent(QResizeEvent *event) {

    QMainWindow::resizeEvent(event);
    fitModelToView();
}

void MainWindow::on_btn_refresh_clicked() {

    applyAndFitModel(m_dbHnd->getLastRecordsModel());
}

void MainWindow::on_btn_addRecord_clicked() {

    qDebug() << "addRecord";
    fillComboNames();

    m_insertRecWindow->setModal(true);
    m_insertRecWindow->exec();
}

void MainWindow::on_actionMedize_triggered() {

    applyStyleSheet(QString(":/Medize.qss"));
}

void MainWindow::on_actionDiffnes_triggered() {

    applyStyleSheet(QString(":/Diffnes.qss"));
}

void MainWindow::on_actionStartPage_triggered() {

    applyStyleSheet(QString(":/Cstartpage.qss"));
}

void MainWindow::on_actionMailSy_triggered() {

    applyStyleSheet(QString(":/MailSy.qss"));
}

void MainWindow::setUniqueNamesToCombo(QStringList names) {

    ui->combo_carNumber->clear();
    ui->combo_carNumber->addItems(names);
}
