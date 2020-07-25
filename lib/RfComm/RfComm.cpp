#pragma once
#include "RfComm.h"

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <printf.h>


#define rfChannel      0x5B   
#define rf_server      0x50
#define rf_car         0x55
#define RF_CS          A2
#define RF_CE          A3

RF24 radio(RF_CE, RF_CS);


RfComm::RfComm(int _rf_ce, int _rf_cs){
    
};

bool RfComm::setup(int node){
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
    switch (node)    {
    case IS_CAR:
        radio.openWritingPipe(rf_server);
        radio.openReadingPipe(1, rf_car);
        break;
    case IS_SRV:
        radio.openWritingPipe(rf_car);
        radio.openReadingPipe(1, rf_server);
        break;
    default:
        break;
    }

    //debug
    online = (rfChannel == radio.getChannel()); //test if radio is enabled
    if(online) radio.printDetails();    
    Serial.println(online?"rf online":"rf offline");

    return online;
};

bool RfComm::send(car_data_t *pkt){
    radio.stopListening();
    Serial.print(pkt->dist);
    bool result = radio.write(pkt, sizeof(unsigned long), 0);
    radio.startListening();
    Serial.println("rf -> " + result?"ok":"error");
    return result;
};

bool RfComm::update(){
    if(!online) return false;
    if(!radio.available()) return false;
    Serial.print(". ");

	while (radio.available()) {
		radio.read(&packet, sizeof(car_data_t));
	}

	//prepare for next packet
	radio.startListening();
    lastRecvTime = millis();
    Serial.println("rf <-");
    return true;
};
