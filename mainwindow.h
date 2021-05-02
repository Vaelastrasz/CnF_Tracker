#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbmanager.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionMaximizeWindow_toggled(bool arg1);

    void on_actionMinimizeWindow_triggered();

    void on_actionSwitchTab_triggered();

    void on_rb_show1d_clicked();

    void on_rb_show1h_clicked();

    void on_rb_show1k_clicked();

    void on_actionExit_triggered();

    void on_tabs_currentChanged(int index);

private:
    void startup();
    void applyStyleSheet();
    void fitModelToView();
    void applyAndFitModel(QSqlQueryModel*);

    DBManager* m_dbHnd;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
