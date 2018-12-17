#include "jsondata.h"
#include "ui_jsondata.h"
#include "iostream"

using namespace std;
JsonData::JsonData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JsonData)
{
    ui->setupUi(this);
}

JsonData::~JsonData()
{
    delete ui;
}

void JsonData::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

void JsonData::on_pushButton_2_clicked()
{
    QFile file;
    file.setFileName("E://WithQt//JsonBasaData.json");

    try
    {
        if(!file.open(QIODevice::ReadOnly|QFile::Text)){
            throw 3;
        }
    }
    catch(int i)
    {
        cout<<"Error #"<<i<<" - base don't read"<<endl;
    }

    file.open(QIODevice::ReadOnly|QFile::Text);

        doc1 = QJsonDocument::fromJson(QByteArray(file.readAll()),&docError1);//вытащим данные из файла выбраного пользователем

    file.close();

    if(docError1.errorString().toInt() == QJsonParseError::NoError)
    {
        //заполнение табличного компонента
        QStandardItemModel* model = new QStandardItemModel(nullptr);
        model->setHorizontalHeaderLabels(QStringList()<<"Health"<<"Score"<<"Time");

       docAr1 = QJsonValue(doc1.object().value("Platformer")).toArray();
       for(int i=0; i<docAr1.count(); i++)
       {
         QStandardItem* item_col_1 = new QStandardItem(QString::number(docAr1.at(i).toObject().value("Health").toInt()));
         QStandardItem* item_col_2 = new QStandardItem(QString::number(docAr1.at(i).toObject().value("Score").toInt()));
         QStandardItem* item_col_3 = new QStandardItem(QString::number(docAr1.at(i).toObject().value("Time").toInt()));

          model->appendRow(QList<QStandardItem*>()<<item_col_1<<item_col_2<<item_col_3);
       }

        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    }
}
