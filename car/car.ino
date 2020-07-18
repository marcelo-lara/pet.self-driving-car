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
#include "src/RfControl/RfControl.h"
#define RF_MOSI 11
#define RF_MISO 12
#define RF_SCK  13
#define RF_CE    7
#define RF_CS    8
RfControl rf(RF_CE, RF_CS);

//distance sensor
#include "src/Distance/Distance.h"
#define USPROX_PING A0
#define USPROX_ECHO A1
Distance distance(USPROX_PING, USPROX_ECHO);

void setup(){
  Serial.begin(115200);
  rf.setup();
}

void loop(){


}
