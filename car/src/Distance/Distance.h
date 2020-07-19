#pragma once
#include "Arduino.h"

class Distance{
public:
    Distance(int _ping_pin, int _echo_pin);
    int get();

private:
    int ping_pin;
    int echo_pin;
};