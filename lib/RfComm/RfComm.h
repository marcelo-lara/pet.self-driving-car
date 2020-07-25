#pragma once
#include "Arduino.h"

#define IS_SRV  0
#define IS_CAR  1
struct car_data_t {
    //motors
    byte motorA1;
    byte motorA2;
    byte motorB1;
    byte motorB2;

    //sensors
    byte dist;
};

class RfComm{
public:
    RfComm(int _rf_ce, int _rf_cs);
    bool setup(int node);
    bool online;

    bool update();
    bool send(car_data_t *pkt);
    car_data_t receive();

    long lastRecvTime;
    car_data_t packet;

};
