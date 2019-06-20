#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <QDialog>
#include <QtGui/QtGui>
#include <QMessageBox>

#include <QDebug>

#include "gamescene.h"

namespace Ui {
class GamePad;
}

class GamePad : public QDialog
{
    Q_OBJECT

public:
    explicit GamePad(QWidget *parent = nullptr);
    ~GamePad();

private slots:
    void on_pushButton_clicked();
    void on_pause_clicked();
    void setScore(int);
    void next(int);
    void gg();

signals:
    void sendPause();
    void sendResume();

private:
    Ui::GamePad *ui;
    GameScene *scene;
    bool pau;
};

#endif // GAMEPAD_H
