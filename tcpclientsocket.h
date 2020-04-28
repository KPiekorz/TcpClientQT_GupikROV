#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <string>

#include "datapacket.h"

#define ADDRESS     "169.254.0.20"
#define PORT        4242

class TcpClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit TcpClientSocket(QObject *parent = nullptr);

    bool doConnect();
    void disconnect();
    void writebytes(QByteArray bytes);

signals:

public slots:
    void onReadyRead();



private:
    QTcpSocket socket;

    DataPacket eth_data;

};

#endif // TCPCLIENTSOCKET_H
