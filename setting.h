#ifndef SETTING_H
#define SETTING_H

#include <QDialog>

namespace Ui {
class Setting;
}

class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void WriteSetting();

    void ReadSetting();

    void GetSetting();

private:
    Ui::Setting *ui;
    int setFullScreen, FrameRate, Syns, Music, Sound, AI;
};

#endif // SETTING_H
