# include "../headers/motorLogic.hpp"
# include <Arduino.h>

int motorSpeedLeft = 0;
int motorSpeedRight = 0;

void motorSetup(void) {
  pinMode(M1Forward, OUTPUT);
  pinMode(M1Reverse, OUTPUT);
  pinMode(M2Forward, OUTPUT);
  pinMode(M2Reverse, OUTPUT);
}

void run(void) {
  if (motorSpeedLeft > 0) {
    analogWrite(M1Forward, motorSpeedLeft);
    analogWrite(M1Reverse, 0);
  } else {
    analogWrite(M1Reverse, -1 * motorSpeedLeft);
    analogWrite(M1Forward, 0);
  }

  if (motorSpeedRight > 0) {
    analogWrite(M2Forward, motorSpeedRight);
    analogWrite(M2Reverse, 0);
  } else {
    analogWrite(M2Reverse, -1 * motorSpeedRight);
    analogWrite(M2Forward, 0);
  }

}

void straight(void) {
  motorSpeedLeft = 50;
  motorSpeedRight = 50;
}
