#include "gamepad.h"
#include "ui_gamepad.h"

GamePad::GamePad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GamePad)
{
    ui->setupUi(this);
    scene = new GameScene(0, 0,
                          ui->view->width()-2,
                          ui->view->height()-2);
    scene->setBackgroundBrush(Qt::black);
    ui->view->setScene(scene);

    ui->score->setDigitCount(4);

    pau = false;

    connect(scene,SIGNAL(changeScore(int)),this,SLOT(setScore(int)));
    connect(scene,SIGNAL(win(int)),this,SLOT(next(int)));
    connect(this,SIGNAL(sendPause()),scene,SLOT(timePause()));
    connect(this,SIGNAL(sendResume()),scene,SLOT(timeResume()));
    connect(scene,SIGNAL(gg()),this,SLOT(gg()));
}

GamePad::~GamePad()
{
    delete ui;
}

void GamePad::on_pushButton_clicked()
{
    this->close();
}

void GamePad::setScore(int k)
{
    ui->score->display(k);
}

void GamePad::next(int k)
{
    ui->rank->setText(QString::number(k));
    QMessageBox::information(this,tr("win"),tr("NEXT LEVEL"));
}

void GamePad::gg()
{
    QMessageBox::critical(this,tr("gg"),tr("YOU'RE DEAD!!"));
}


void GamePad::on_pause_clicked()
{
    if(!pau){
        emit sendPause();
        pau = !pau;
    }
    else{
        emit sendResume();
        pau = !pau;
    }
}
