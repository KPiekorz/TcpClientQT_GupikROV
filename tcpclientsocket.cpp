#include "tcpclientsocket.h"

#include <QDebug>
#include <QHostAddress>

TcpClientSocket::TcpClientSocket(QObject *parent) : QObject(parent)
{
    _socket.connectToHost(QHostAddress("127.0.0.1"), 4242);
    connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}


void TcpClientSocket::onReadyRead()
{
    QByteArray datas = _socket.readAll();
    qDebug() << datas;
    _socket.write(QByteArray("ok !\n"));
}
