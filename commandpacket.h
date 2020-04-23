#ifndef COMMANDPACKET_H
#define COMMANDPACKET_H

#include <QByteArray>
#include <QVector>
#include <stdint.h>
#include <stdio.h>

/* packet type for command packet */
enum{
    sensor_command  = 0x01,
    motor_command
};

/* parametr 0 value */
enum{
    sensor_standard = 0x01,
    accel_calibration
};

class CommandPacket
{
private:

    int16_t CalculateCheckSum(QByteArray command_packet, int command_packet_length);

public:
    CommandPacket();

    QByteArray commad_sensor_pakcet;
    QByteArray command_motor_packet;

    void ConstructCommadSensorPacket(int sensor_command_parameter_value);
    void ConstructCommandMotorPacket(int motor_number, int motor_speed);

};

#endif // COMMANDPACKET_H
