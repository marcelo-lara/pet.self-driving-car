#pragma once
#include "Arduino.h"

class RfServer{
public:
    RfServer(int _rf_ce, int _rf_cs);
    bool setup();

    bool online;

};
