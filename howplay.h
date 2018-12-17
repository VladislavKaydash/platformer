#ifndef HOWPLAY_H
#define HOWPLAY_H

#include <QDialog>

namespace Ui {
class HowPlay;
}

class HowPlay : public QDialog
{
    Q_OBJECT

public:
    explicit HowPlay(QWidget *parent = 0);
    ~HowPlay();
signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HowPlay *ui;
};

#endif // HOWPLAY_H
