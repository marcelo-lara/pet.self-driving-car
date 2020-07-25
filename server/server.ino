#include "Arduino.h"

//radio
#include "src/RfComm/RfComm.h"
#define RF_SCK  13 //-> 5
#define RF_MOSI 11 //-> 6
#define RF_MISO 12 //-> 7
#define RF_CS    8 //-> 4
#define RF_CE    7 //-> 3
RfComm rf(RF_CE, RF_CS);
car_data_t car_data;

void setup(){
  Serial.begin(115200);
  Serial.println(":: server node");
  rf.setup(IS_SRV);

  memset(&car_data, 0, sizeof(car_data_t));

}

int cm;

void loop(){
  rf.update();
  delay(10);

}
