/*
    Driver: L293D
*/


#include "Engine.h"

Engine::Engine(int _mA1, int _mA2, int _mB1, int _mB2){
    motorA1=_mA1;
    motorA2=_mA2;
    motorB1=_mB1;
    motorB2=_mB2;

    //set outputs
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
    stop();
};

void Engine::stop(){
    analogWrite(motorA1, 0);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 0);
};

void Engine::test(){
    int i;
    Serial.print("A1 "); testOut(motorA1);
    Serial.print("A2 "); testOut(motorA2);
    Serial.print("B1 "); testOut(motorB1);
    Serial.print("B2 "); testOut(motorB2);

};

void Engine::testOut(int _pin){
    for (int i = 0; i < 255; i++){
        analogWrite(_pin, i);
        Serial.print(".");
        delay(10);
    }       
    stop();    
    Serial.println(" stop");
}