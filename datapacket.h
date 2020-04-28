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
    int data[30];
    int checksum;

    int QBytetoInt(char data);

    /* private function */
    int ParseReceivedEthData(QByteArray eth_data);


public:
    DataPacket();

    /*
    void ConvertEthData(QByteArray eth_data);

    /*
     * Narazie funckja do wyciagania odpowiednich wartosci z odebranych danych
     * te podstawowe pola, dpiero potem funkcje specjalistyczne do przerabiania odebranych danych na
     * dane do wartosci z czujnikow i predkosci silnikow
     */

};

#endif // DATAPACKET_H
