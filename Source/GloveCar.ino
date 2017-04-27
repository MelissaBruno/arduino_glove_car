#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

int leftSwitch, rightSwitch;

Adafruit_MotorShield motor1 = Adafruit_MotorShield();

Adafruit_DCMotor *leftMotor = motor1.getMotor(2);
Adafruit_DCMotor *rightMotor = motor1.getMotor(1);


void setup() {
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  leftSwitch = 0;
  rightSwitch = 0;

  motor1.begin();
  leftMotor->setSpeed(175);
  rightMotor->setSpeed(175); 
}

void loop() {
  leftSwitch = digitalRead(7);
  rightSwitch = digitalRead(8);

  if(leftSwitch == HIGH){
    leftMotor->run(FORWARD);
  }
  else{
    leftMotor->run(RELEASE);
  }
  if(rightSwitch == HIGH){
    rightMotor->run(FORWARD);
  }
  else{
    rightMotor->run(RELEASE);
  }
}
