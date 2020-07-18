#pragma once
#include "Arduino.h"

class Distance{
public:
    Distance(int _ping_pin, int _echo_pin);

private:
    int ping_pin;
    int echo_pin;
};