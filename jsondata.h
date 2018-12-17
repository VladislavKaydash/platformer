#ifndef JSONDATA_H
#define JSONDATA_H

#include <QDialog>

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QFile>
#include <QFileDialog>
#include <QStandardItem>

namespace Ui {
class JsonData;
}

class JsonData : public QDialog
{
    Q_OBJECT

    QJsonDocument doc1;//отвечает за хранение файлов в формате json(хранятся данные от файла)
    QJsonArray docAr1;
    QJsonParseError docError1;


public:
    explicit JsonData(QWidget *parent = 0);
    ~JsonData();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::JsonData *ui;
};

#endif // JSONDATA_H
