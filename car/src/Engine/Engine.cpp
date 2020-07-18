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
