#include "Control.h"

ControlClass control = ControlClass();
int leftSwitch, rightSwitch;

void setup() {
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  leftSwitch = 0;
  rightSwitch = 0;

  control.SETUP();
}

void loop() {
  leftSwitch = digitalRead(7);
  rightSwitch = digitalRead(8);
  Serial.print(leftSwitch + " " + rightSwitch);

  if(leftSwitch == HIGH){
    control.turnLeft();
  }
  else{
    control.release();
  }
  if(rightSwitch == HIGH){
    control.turnRight();
  }
  else{
    control.release();
  }
  if(leftSwitch == HIGH && rightSwitch == HIGH){
    control.forward();
  }


  
} //End loop
