#include "mainwindow.h"

#include <QApplication>

#include "tcpclientsocket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    TcpClientSocket clientsocket;


    return a.exec();
}
