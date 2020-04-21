#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->label->setText("Tcp connecting...");
    bool tcpconRovstatus = tcpclientROV.doConnect();
    if(tcpconRovstatus == true){
        ui->label->setText("Connected!");
    }else{
        ui->label->setText("No Connected!");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    tcpclientROV.disconnect();
    ui->label->setText("Disconnected!");
}
