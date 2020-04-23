#include "commandpacket.h"

CommandPacket::CommandPacket()
{
    /* initialize command sensor packet */
    commad_sensor_pakcet.resize(7);
    commad_sensor_pakcet.clear();
}

int16_t CommandPacket::CalculateCheckSum(QByteArray command_packet, int command_packet_length){

    int16_t checksum = 0;
    for(int i=0; i<command_packet_length; i++){
        checksum+=command_packet[i];
    }

    return checksum;
}


void CommandPacket::ConstructCommadSensorPacket(int sensor_command_parameter_value){

    commad_sensor_pakcet.clear();

    commad_sensor_pakcet[0] = 's';
    commad_sensor_pakcet[1] = 'n';
    commad_sensor_pakcet[2] = 'p';

    commad_sensor_pakcet[3] = sensor_command; // command number
    commad_sensor_pakcet[4] = sensor_command_parameter_value; // parametr 0 value

    int16_t checksum = CalculateCheckSum(commad_sensor_pakcet, 5);

    commad_sensor_pakcet[5] = checksum>>8;
    commad_sensor_pakcet[6] = checksum&0xFF;

}


void CommandPacket::ConstructCommandMotorPacket(int motor_number, int motor_speed){


}
