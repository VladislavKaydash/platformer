#include "howplay.h"
#include "ui_howplay.h"
#include <QPixmap>

HowPlay::HowPlay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HowPlay)
{
    ui->setupUi(this);

    QPixmap pix(":/resource/image/2.png");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w,h));
}

HowPlay::~HowPlay()
{
    delete ui;
}

void HowPlay::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();

}
