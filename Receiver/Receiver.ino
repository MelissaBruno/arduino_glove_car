/*
 * Class for recieving and moving the car.
 */

#include <VirtualWire.h>
#include "Control.h"

#define TRIG_PIN 7
#define ECHO_PIN 8

ControlClass control = ControlClass();

long duration;
int distance;

void setup() {
  control.SETUP();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  vw_set_rx_pin(2);
  vw_setup(4000);
  vw_rx_start();
}

void loop() {
  
  // Monitors the distance of object in front of it
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Reads echoPin, returns the sound wave travel time and calculates distance
  duration = pulseIn(ECHO_PIN, HIGH);
  distance= duration*0.034/2;
  
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  if (vw_get_message(buf, &buflen)) {
     if(buf[0]=='0') {
        if(distance <= 10){     //If distance is less than 6", stop the car
          control.release();  
        }
        else{
          control.forward();    //Forward
        }
     }
     if(buf[0]=='1') {
        control.release();      //Stop
     }
     if(buf[0]=='2') {
        control.backward();     //Reverse
     }
     if(buf[0]=='3') {
        control.turnLeft();     //Left turn
     }
     if(buf[0]=='4') {
        control.turnRight();    //Right turn
     }
  }
} //loop
