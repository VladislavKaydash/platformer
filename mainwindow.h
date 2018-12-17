#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "howplay.h"
#include "setting.h"
#include "jsondata.h"



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
    void on_StartButton_clicked();

    void on_pushButton_2_clicked();   

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    HowPlay *howplay;
    Setting *setting;
    JsonData *jsondata;




};

#endif // MAINWINDOW_H
