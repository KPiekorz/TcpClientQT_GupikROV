#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>

class TcpClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit TcpClientSocket(QObject *parent = nullptr);

    void doConnect();

signals:

public slots:
    void onReadyRead();

private:
    QTcpSocket _socket;

};

#endif // TCPCLIENTSOCKET_H
