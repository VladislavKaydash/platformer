/********************************************************************************
** Form generated from reading UI file 'howplay.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOWPLAY_H
#define UI_HOWPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HowPlay
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *HowPlay)
    {
        if (HowPlay->objectName().isEmpty())
            HowPlay->setObjectName(QStringLiteral("HowPlay"));
        HowPlay->resize(800, 600);
        HowPlay->setMinimumSize(QSize(800, 600));
        HowPlay->setMaximumSize(QSize(800, 600));
        pushButton = new QPushButton(HowPlay);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 510, 150, 75));
        pushButton->setMinimumSize(QSize(150, 75));
        pushButton->setStyleSheet(QLatin1String("font-family:Helvetica,Arial,sans-serif;\n"
"	font-size: 20px;\n"
"font-weight:bold"));
        label = new QLabel(HowPlay);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 70, 871, 451));
        label->setPixmap(QPixmap(QString::fromUtf8("image/2.png")));

        retranslateUi(HowPlay);

        QMetaObject::connectSlotsByName(HowPlay);
    } // setupUi

    void retranslateUi(QDialog *HowPlay)
    {
        HowPlay->setWindowTitle(QApplication::translate("HowPlay", "Platformer", Q_NULLPTR));
        pushButton->setText(QApplication::translate("HowPlay", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HowPlay: public Ui_HowPlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOWPLAY_H
