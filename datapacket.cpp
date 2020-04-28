#include "datapacket.h"

DataPacket::DataPacket()
{
    packt_type = 0;
    data_length = 0;
    checksum = 0;
}


int DataPacket::ParseReceivedEthData(QByteArray eth_data){

    /*empty atributes of class */
    packt_type = 0;
    data_length = 0;
    checksum = 0;

    int hej = 0;
    int wartosci[10];
    for(int i=0; i<10; i++) wartosci[i]=0;

    /* tempolary variable */
    int index = 0;
    int calc_checksum = 0;
    int eth_data_length = eth_data.length();

    // find start new packet in ethernet data
    while((index < eth_data_length) && (eth_data[index] != 's')) index++; calc_checksum += (int)'s'; wartosci[hej++] = (int)'s';

    if(index >= eth_data_length) return no_packet_found;

    index++; if( eth_data[index] != 'n' ) return no_packet_found; calc_checksum += (int)'n'; wartosci[hej++] = (int)'n';
    index++; if( eth_data[index] != 'p' ) return no_packet_found; calc_checksum += (int)'p'; wartosci[hej++] = (int)'p';

    //read command number and save in packet type variable
    index++; packt_type = QBytetoInt(eth_data[index]); calc_checksum += packt_type; wartosci[hej++] = packt_type;

    //read number of parameters
    index++; data_length = QBytetoInt(eth_data[index]); calc_checksum += data_length; wartosci[hej++] = data_length;

    //read parameters value
    int i;
    for(i=0; i<data_length; i++){
        index++;

        data[i] = QBytetoInt(eth_data[index]); calc_checksum += data[i]; wartosci[hej++] = data[i];

    }

    // calcualte receive checksum
    int buf = 0;
    index++; buf = QBytetoInt(eth_data[index]); buf = buf << 8;
    index++; buf = buf|QBytetoInt(eth_data[index]);
    checksum = buf;

    qDebug() << calc_checksum;
    qDebug() << checksum;

    if(calc_checksum != checksum) return checksum_error;

    return eth_packet_ok;

}


int DataPacket::QBytetoInt(char data){

    int data_int;

    data_int = (static_cast<unsigned int>(data) & 0xFF);

    return data_int;
}
