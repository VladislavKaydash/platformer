/********************************************************************************
** Form generated from reading UI file 'jsondata.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JSONDATA_H
#define UI_JSONDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_JsonData
{
public:
    QPushButton *pushButton;
    QTableView *tableView;
    QPushButton *pushButton_2;

    void setupUi(QDialog *JsonData)
    {
        if (JsonData->objectName().isEmpty())
            JsonData->setObjectName(QStringLiteral("JsonData"));
        JsonData->resize(800, 600);
        pushButton = new QPushButton(JsonData);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 530, 121, 51));
        tableView = new QTableView(JsonData);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(215, 11, 381, 401));
        pushButton_2 = new QPushButton(JsonData);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 420, 371, 41));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        pushButton_2->setFont(font);

        retranslateUi(JsonData);

        QMetaObject::connectSlotsByName(JsonData);
    } // setupUi

    void retranslateUi(QDialog *JsonData)
    {
        JsonData->setWindowTitle(QApplication::translate("JsonData", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("JsonData", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("JsonData", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\274\320\276\320\270 \321\200\320\265\320\272\320\276\321\200\320\264\321\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JsonData: public Ui_JsonData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JSONDATA_H
