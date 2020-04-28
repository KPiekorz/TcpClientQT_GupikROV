#ifndef DATAPACKET_H
#define DATAPACKET_H

#include <QByteArray>
#include <QDebug>
#include <QVector>

/* parse packet function status */
enum{
    eth_packet_ok = 1,
    checksum_error,
    no_packet_found
};

/* packet type for data packet */
enum{
    sensor_data_standart = 1,
    motor_data_standard         // czyli tylko predkosci kazdego silnika
};

class DataPacket
{

private:

    /* raw packet bytes */
    int packt_type;
    int data_length;
    int data[30];
    int checksum;

    /* IMU sensor data */
    float accel_x;
    float accel_y;
    float accel_z;

    /* Pressure sensor data */
    float pressure;

    /* Motor speed */
    int motro_speed_1;
    int motro_speed_2;
    int motro_speed_3;
    int motro_speed_4;
    int motro_speed_5;

    /* private function */
    int QBytetoInt(char data);
    int ParseReceivedEthData(QByteArray eth_data);


public:
    DataPacket();

    /*
     * funkcja do przerobienia otrzymanych danych z stm32h7 po eth, analiza rodzaju danych i wyswietleniu konkretnych danych z czujnikow lub
     * motor speed (albo w aplikacji wielowatkowej wrzucenie do danej kolejki, ktora przekarze odebrane dane w odpowiednie miejsce)
     */
    void ConvertEthData(QByteArray eth_data);

    // jakies funckje ktore beda zwracaly wartosci predkosci lub przyspieszen lub czegosc innnego
    float get_actual_pressure();
    QVector<float> get_actual_rov_accel();
    QVector<int> get_actual_motor_speed();


    /*
     * Narazie funckja do wyciagania odpowiednich wartosci z odebranych danych
     * te podstawowe pola, dpiero potem funkcje specjalistyczne do przerabiania odebranych danych na
     * dane do wartosci z czujnikow i predkosci silnikow
     */

};

#endif // DATAPACKET_H
