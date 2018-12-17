#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include "mainer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resource/image/dd2.png");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w,h));



    howplay = new HowPlay();
    connect(howplay,&HowPlay::firstWindow,this,&MainWindow::show);

    setting = new Setting();
    connect(setting,&Setting::firstWindow,this,&MainWindow::show);

    jsondata = new JsonData();
    connect(jsondata,&JsonData::firstWindow,this,&MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_StartButton_clicked()
{
    //QApplication::quit();
    QMessageBox::StandardButton exist = QMessageBox::question(this,"Exist","Are u sure!?", QMessageBox::Yes | QMessageBox::No);
    if (exist==QMessageBox::Yes){
        QApplication::quit();
    }
    else if (exist==QMessageBox::No){
        QMessageBox::information(this,"Thanks", "U're nice!");
        //QMessageBox::about(this,"Error","Error #123: data don't find");
        //QMessageBox::critical (this,"Error","Error #123: data don't find");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    howplay->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    Mainer a(10,10,10.0,10.0);
    a.Mfunc();

}

void MainWindow::on_pushButton_4_clicked()
{
    this->hide();
    setting->show();
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    jsondata->show();
}
