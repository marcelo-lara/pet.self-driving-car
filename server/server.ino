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
car_rf_cnc_t data;

void setup(){
  Serial.begin(115200);
  rf.setup();

  memset(&data, 0, sizeof(car_rf_cnc_t));

}

int cm;

void loop(){



}
