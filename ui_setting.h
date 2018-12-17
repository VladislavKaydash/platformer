/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Setting
{
public:
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QCheckBox *videoset;
    QCheckBox *vidoset2;
    QCheckBox *vidoset3;
    QGroupBox *groupBox_2;
    QSlider *musicset;
    QSlider *soundset;
    QGroupBox *groupBox_3;
    QRadioButton *ai;
    QRadioButton *ai_2;
    QRadioButton *ai_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Setting)
    {
        if (Setting->objectName().isEmpty())
            Setting->setObjectName(QStringLiteral("Setting"));
        Setting->resize(800, 600);
        Setting->setMinimumSize(QSize(800, 600));
        Setting->setMaximumSize(QSize(800, 600));
        pushButton = new QPushButton(Setting);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 520, 121, 71));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setPointSize(16);
        pushButton->setFont(font);
        groupBox = new QGroupBox(Setting);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(60, 70, 201, 291));
        videoset = new QCheckBox(groupBox);
        videoset->setObjectName(QStringLiteral("videoset"));
        videoset->setGeometry(QRect(10, 50, 161, 41));
        videoset->setTristate(false);
        vidoset2 = new QCheckBox(groupBox);
        vidoset2->setObjectName(QStringLiteral("vidoset2"));
        vidoset2->setGeometry(QRect(10, 130, 141, 17));
        vidoset3 = new QCheckBox(groupBox);
        vidoset3->setObjectName(QStringLiteral("vidoset3"));
        vidoset3->setGeometry(QRect(10, 180, 121, 41));
        groupBox_2 = new QGroupBox(Setting);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(320, 80, 191, 291));
        musicset = new QSlider(groupBox_2);
        musicset->setObjectName(QStringLiteral("musicset"));
        musicset->setGeometry(QRect(50, 70, 22, 160));
        musicset->setMaximum(100);
        musicset->setSingleStep(25);
        musicset->setValue(100);
        musicset->setOrientation(Qt::Vertical);
        musicset->setTickPosition(QSlider::TicksAbove);
        soundset = new QSlider(groupBox_2);
        soundset->setObjectName(QStringLiteral("soundset"));
        soundset->setGeometry(QRect(110, 70, 22, 160));
        soundset->setMaximum(100);
        soundset->setSingleStep(25);
        soundset->setPageStep(10);
        soundset->setValue(100);
        soundset->setSliderPosition(100);
        soundset->setOrientation(Qt::Vertical);
        soundset->setInvertedAppearance(false);
        soundset->setInvertedControls(false);
        soundset->setTickPosition(QSlider::TicksBelow);
        soundset->setTickInterval(0);
        groupBox_3 = new QGroupBox(Setting);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(570, 80, 201, 291));
        ai = new QRadioButton(groupBox_3);
        ai->setObjectName(QStringLiteral("ai"));
        ai->setGeometry(QRect(30, 80, 111, 41));
        ai->setChecked(true);
        ai_2 = new QRadioButton(groupBox_3);
        ai_2->setObjectName(QStringLiteral("ai_2"));
        ai_2->setGeometry(QRect(30, 130, 111, 41));
        ai_2->setChecked(false);
        ai_3 = new QRadioButton(groupBox_3);
        ai_3->setObjectName(QStringLiteral("ai_3"));
        ai_3->setGeometry(QRect(30, 180, 111, 41));
        pushButton_2 = new QPushButton(Setting);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 390, 131, 61));
        pushButton_2->setFont(font);

        retranslateUi(Setting);

        QMetaObject::connectSlotsByName(Setting);
    } // setupUi

    void retranslateUi(QDialog *Setting)
    {
        Setting->setWindowTitle(QApplication::translate("Setting", "Platformer", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Setting", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Setting", "Video", Q_NULLPTR));
        videoset->setText(QApplication::translate("Setting", "FULL Screen", Q_NULLPTR));
        vidoset2->setText(QApplication::translate("Setting", "Frame limit(60)", Q_NULLPTR));
        vidoset3->setText(QApplication::translate("Setting", "Vertical synhronise", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Setting", "Sound", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Setting", "AI enemies", Q_NULLPTR));
        ai->setText(QApplication::translate("Setting", "Ezy", Q_NULLPTR));
        ai_2->setText(QApplication::translate("Setting", "Medium", Q_NULLPTR));
        ai_3->setText(QApplication::translate("Setting", "Hard", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Setting", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Setting: public Ui_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
