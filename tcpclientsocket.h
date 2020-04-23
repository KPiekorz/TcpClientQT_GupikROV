#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

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

};

#endif // TCPCLIENTSOCKET_H
