/*
 * Library for setting up and controlling the car
 */

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "Control.h"

Adafruit_MotorShield motor1 = Adafruit_MotorShield();

Adafruit_DCMotor *leftMotor = motor1.getMotor(2);
Adafruit_DCMotor *rightMotor = motor1.getMotor(1);

ControlClass::ControlClass(){
}

void ControlClass::SETUP(){
  motor1.begin();
  leftMotor->setSpeed(175);
  rightMotor->setSpeed(175); 
}

/*
 * Returns position of cursor
 */
void ControlClass::forward(){
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
}

void ControlClass::turnLeft(){
  leftMotor->run(RELEASE);
  rightMotor->run(FORWARD);
}

void ControlClass::turnRight(){
  leftMotor->run(FORWARD);
  rightMotor->run(RELEASE);
}

void ControlClass::release(){
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
}

