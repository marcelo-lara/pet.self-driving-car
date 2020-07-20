#include "Arduino.h"

//radio
#include "src/RfServer/RfServer.h"
#define RF_SCK  13 //-> 5
#define RF_MOSI 11 //-> 6
#define RF_MISO 12 //-> 7
#define RF_CS    8 //-> 4
#define RF_CE    7 //-> 3
RfServer rf(RF_CE, RF_CS);

#include "src/comm_protocol/car_cnc.h"

void setup(){
  Serial.begin(115200);
  rf.setup();
}

int cm;
car_rf_cnc_t current_packet;

void loop(){



}
