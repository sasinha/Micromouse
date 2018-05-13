# include "../headers/motorLogic.hpp"
# include "../headers/encoders.hpp"


# include <Arduino.h>
# include <AutoPID.h>

int motorSpeedLeft = 0;
int motorSpeedRight = 0;

double leftDist = 0;
double rightDist = 0;

void motorSetup(void) {
  // Motor speed pins
  pinMode(M1Forward, OUTPUT);
  pinMode(M1Reverse, OUTPUT);
  pinMode(M2Forward, OUTPUT);
  pinMode(M2Reverse, OUTPUT);

}


void motorRun(void) {
  if (motorSpeedLeft > 0) {
    analogWrite(M2Forward, motorSpeedLeft % maxAnalogWrite);
    analogWrite(M2Reverse, 0);
  } else {
    analogWrite(M2Reverse, (-1 * motorSpeedLeft) % maxAnalogWrite);
    analogWrite(M2Forward, 0);
  }

  if (motorSpeedRight > 0) {
    analogWrite(M1Forward, motorSpeedRight % maxAnalogWrite);
    analogWrite(M1Reverse, 0);
  } else {
    analogWrite(M1Reverse, (-1 * motorSpeedRight) % maxAnalogWrite);
    analogWrite(M1Forward, 0);
  }

}

void straight(void) {
  motorSpeedLeft = 150;
  motorSpeedRight = 150;
}
