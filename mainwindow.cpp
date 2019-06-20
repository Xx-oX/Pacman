#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame()
{
    gamePad = new GamePad();
    this->hide();
    int padReturn = gamePad->exec();
    if(padReturn == QDialog::Rejected){
        this->show();
    }
}

void MainWindow::on_pushButton_clicked()
{
    startGame();
}
