#ifndef COMMANDPACKET_H
#define COMMANDPACKET_H


class CommandPacket
{
private:
    /* variable containing values of packet */


    // char vector of command parameters

//    void PacketValueUpdate();

public:
    CommandPacket();

    int CalculateCheckSum();

};

#endif // COMMANDPACKET_H
