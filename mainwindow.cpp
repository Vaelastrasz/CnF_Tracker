#include "mainwindow.h"
#include "ui_mainwindow.h"

#define TEXT(x) tr(x)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(TEXT("C&F Tracker"));
    this->setWindowIcon(QIcon(":/icons/truck.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
