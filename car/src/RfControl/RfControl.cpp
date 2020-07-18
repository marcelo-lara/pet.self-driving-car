#pragma once
#include "RfControl.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


#define rf_ce   7 
#define rf_csn  8 
RF24 radio(rf_ce,rf_csn);


RfControl::RfControl(int _rf_ce, int _rf_cs){
    
};

bool RfControl::setup(){

    return true;
};