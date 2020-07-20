#pragma once
#include "Arduino.h"

class Engine{
public:
    Engine(int _mA1, int _mA2, int _mB1, int _mB2);

    void test();
    void stop();


private:
    int motorA1;
    int motorA2;
    int motorB1;
    int motorB2;

    void testOut(int _pin);

};

