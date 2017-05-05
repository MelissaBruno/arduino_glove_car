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
  
  Serial.begin(9600);
  
  vw_set_rx_pin(2);
  vw_setup(4000);
  vw_rx_start();
}

void loop() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  if (vw_get_message(buf, &buflen)) {
    
     if(buf[0]=='0') {
        if(distance <= 10){
          control.release();  
        }
        else{
          control.forward();
        }
     }
     if(buf[0]=='1') {
        control.release();
     }
     if(buf[0]=='2') {
        control.backward();
     }
     if(buf[0]=='3') {
        control.turnLeft();
     }
     if(buf[0]=='4') {
        control.turnRight();
     }
 
  } //if
} //loop
