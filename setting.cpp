#include "setting.h"
#include "ui_setting.h"
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    GetSetting();
}

Setting::~Setting()
{
    delete ui;
}

void Setting::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

void Setting::on_pushButton_2_clicked()
{
    if(ui->videoset->isChecked()){
        setFullScreen = 1;
    }else
    {
        setFullScreen = 0;
    }
    if (ui->vidoset2->isChecked()){
        FrameRate = 1;

    }else{
        FrameRate = 0;
    }
    if (ui->vidoset3->isChecked()){

        Syns = 1;
}else{
        Syns = 0;
}


    Music = ui->musicset->value();
    Sound = ui->soundset->value();

    if (ui->ai->isChecked()){
        AI = 1;
    }
    else if (ui->ai_2->isChecked()){
        AI = 2;
    }
    else if (ui->ai_3->isChecked()){
        AI = 3;
    }
    WriteSetting();
}

void Setting::WriteSetting(){

    ofstream writeSetting("E:/WithQt/Setting.txt");

    try
    {
        if(!writeSetting.is_open()){

            throw 5;
        }
    }
    catch(int i)
    {
        cout<<"Error #"<<i<<" - setting don't write"<<endl;
    }


    writeSetting<<setFullScreen<<endl;
    writeSetting<<FrameRate<<endl;
    writeSetting<<Syns<<endl;
    writeSetting<<Music<<endl;
    writeSetting<<Sound<<endl;
    writeSetting<<AI<<endl;

    writeSetting.close();
}

void Setting::ReadSetting(){
    ifstream readSetting("E:/WithQt/Setting.txt");

    try
    {
        if(!readSetting.is_open()){
            throw 4;
        }
    }
    catch(int i)
    {
        cout<<"Error #"<<i<<" - setting don't open"<<endl;
    }
    while (readSetting>>setFullScreen &&readSetting>>FrameRate && readSetting>>Syns && readSetting>>Music && readSetting>>Sound && readSetting>>AI) {
       }
    readSetting.close();
}

void Setting::GetSetting(){
    ReadSetting();
    if(setFullScreen==1){
     ui->videoset->setChecked(true);
    }
    if(FrameRate==1){
        ui->vidoset2->setChecked(true);
    }
    if(Syns==1){
        ui->vidoset3->setChecked(true);
    }

    ui->musicset->setValue(Music);
    ui->soundset->setValue(Sound);

    switch(AI){
    case 1:ui->ai->setChecked(true);break;
    case 2:ui->ai_2->setChecked(true);break;
    case 3:ui->ai_3->setChecked(true);break;
    }
}
