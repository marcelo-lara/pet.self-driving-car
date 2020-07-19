#pragma once
#include "RfControl.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <printf.h>


#define rfChannel      0x5B   
#define rf_server_tx   0x50
#define rf_server_rx   0x51
#define rf_car_tx      0x55
#define rf_car_rx      0x56

#define rf_ce   A3 
#define rf_csn  A2 
RF24 radio(rf_ce,rf_csn);


RfControl::RfControl(int _rf_ce, int _rf_cs){
    
};

bool RfControl::setup(){
    Serial.begin(115200);
    printf_begin();
    online=false;

    radio.begin();
    radio.setPALevel(RF24_PA_HIGH); //RF24_PA_HIGH | RF24_PA_LOW | RF24_PA_MAX
    radio.setDataRate(RF24_1MBPS);
    radio.enableDynamicAck();
    radio.setCRCLength(RF24_CRC_8);
    radio.setChannel(rfChannel);
    radio.setRetries(20, 10);  

    //pipes setup
    radio.openWritingPipe(rf_server_rx);
    radio.openReadingPipe(1, rf_car_rx);

    //debug
    online = (rfChannel == radio.getChannel()); //test if radio is enabled
    if(online) radio.printDetails();    
    Serial.println(online?"rf online":"rf offline");

    return online;
};