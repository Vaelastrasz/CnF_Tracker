#include "mainwindow.h"
#include "ui_mainwindow.h"

#define TEXT(x) tr(x)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    startup();
}

MainWindow::~MainWindow() {
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

    this->setWindowTitle(TEXT("C&F Tracker"));
    this->setWindowIcon(QIcon(":/icons/truck.png"));
    ui->btn_addRecord->setIcon(QIcon(":/icons/plus.png"));
    applyStyleSheet();
}

void MainWindow::applyStyleSheet() {
    QFile style(":/Medize.qss");
    style.open(QIODevice::ReadOnly);
    QString styleSheet = QString(style.readAll());
    style.close();
    this->setStyleSheet(styleSheet);
}
