#include "tcpclientsocket.h"

#include <QDebug>
#include <QHostAddress>

TcpClientSocket::TcpClientSocket(QObject *parent) : QObject(parent)
{

    connect(&socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

}

bool TcpClientSocket::doConnect(){

    socket.connectToHost(QHostAddress(ADDRESS), PORT);

    if(!socket.waitForConnected(5000)){
        return false;
    }
    return true;
}

void TcpClientSocket::disconnect(){

    socket.close();

}

void TcpClientSocket::writebytes(QByteArray bytes){

    socket.write(bytes);

}


void TcpClientSocket::onReadyRead()
{

    QByteArray datas = socket.readAll();

    eth_data.ParseReceivedEthData(datas);

}
