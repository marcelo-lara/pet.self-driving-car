#pragma once
#include "Arduino.h"

class RfControl{
public:
    RfControl(int _rf_ce, int _rf_cs);
    bool setup();
};
