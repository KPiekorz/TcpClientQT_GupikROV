#ifndef DATAPACKET_H
#define DATAPACKET_H

#include <QByteArray>
#include <QDebug>

/* parse packet function status */
enum{
    eth_packet_ok = 1,
    checksum_error,
    no_packet_found
};

class DataPacket
{

private:

    int packt_type;
    int data_length;
    QByteArray data;
    int checksum;


public:
    DataPacket();

    int ParseReceivedEthData(QByteArray eth_data);

    /*
     * Narazie funckja do wyciagania odpowiednich wartosci z odebranych danych
     * te podstawowe pola, dpiero potem funkcje specjalistyczne do przerabiania odebranych danych na
     * dane do wartosci z czujnikow i predkosci silnikow
     */

};

#endif // DATAPACKET_H
