#include "Distance.h"

Distance::Distance(int _ping_pin, int _echo_pin){
    ping_pin = _ping_pin; 
    echo_pin = _echo_pin;
    pinMode(ping_pin, OUTPUT);
    pinMode(echo_pin, INPUT);

};

int Distance::get(){
   long _pulse_duration;
   digitalWrite(ping_pin, LOW);
   delayMicroseconds(2);
   digitalWrite(ping_pin, HIGH);
   delayMicroseconds(10);
   digitalWrite(ping_pin, LOW);
   _pulse_duration = pulseIn(echo_pin, HIGH);
   return _pulse_duration / 29 / 2;
};