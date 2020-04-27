#include "datapacket.h"

DataPacket::DataPacket()
{
    packt_type = 0;
    data_length = 0;
    data.clear();
    checksum = 0;
}


int DataPacket::ParseReceivedEthData(QByteArray eth_data){

    /*empty atributes of class */
    packt_type = 0;
    data_length = 0;
    data.clear();
    checksum = 0;

    qDebug() << eth_data;

    /* tempolary variable */
    int index = 0;
    int calc_checksum = 0;
    int eth_data_length = eth_data.length();

    // find start new packet in ethernet data
    while((index < eth_data_length) && (eth_data[index] != 's')) index++; calc_checksum += (int)'s';

    if(index >= eth_data_length) return no_packet_found;

    index++; if( eth_data[index] != 'n' ) return no_packet_found; calc_checksum += (int)'n';
    index++; if( eth_data[index] != 'p' ) return no_packet_found; calc_checksum += (int)'p';

    //read command number and save in packet type variable
    index++; packt_type = eth_data[index]; calc_checksum += packt_type;

    //read number of parameters
    index++; data_length = eth_data[index]; calc_checksum += data_length;

    //read parameters value
    int i;
    for(i=0; i<data_length; i++){
        index++;

        data.append((int)eth_data[index]); calc_checksum += (int)data[0];
        qDebug() << (char)eth_data[index];
    }

    // calcualte receive checksum
    int buf = 0;
    index++; buf = (int)eth_data[index]; buf = buf << 8;
    index++; buf = buf|133;
    checksum = buf;

    QChar znak = eth_data.at(index);

    if(calc_checksum != checksum) return checksum_error;

    return eth_packet_ok;

}
