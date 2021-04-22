#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

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

private:
    void startup();
    void applyStyleSheet();

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
