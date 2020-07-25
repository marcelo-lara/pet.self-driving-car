#include "Arduino.h"

// hardware-setup //
//motors
#include "src/Engine/Engine.h"
#define MOTOR_A1 9
#define MOTOR_A2 6
#define MOTOR_B1 5
#define MOTOR_B2 3
Engine engine(MOTOR_A1, MOTOR_A2, MOTOR_B1, MOTOR_B2);

//radio
#include "src/RfComm/RfComm.h"
#define RF_SCK  13 //-> 5
#define RF_MOSI 11 //-> 6
#define RF_MISO 12 //-> 7
#define RF_CS    8 //-> 4
#define RF_CE    7 //-> 3
RfComm rf(RF_CE, RF_CS);
car_data_t car_data;

//distance sensor
#include "src/Distance/Distance.h"
#define USPROX_PING A1
#define USPROX_ECHO A0
Distance distance(USPROX_PING, USPROX_ECHO);


int cm;

void setup(){
  Serial.begin(115200);
  Serial.println(":: car node");

  rf.setup(IS_CAR);

  //
  memset(&car_data, 0, sizeof(car_data_t));
}

void loop(){
  
  cm = distance.get();
  car_data.dist=cm;
  rf.send(&car_data);

  delay(500);

}
