# include "../headers/encoders.hpp"
# include <Arduino.h>

# define EncCountsPerRev 12
# define Pi 3.14159

int enc_LA = 0;
int enc_LB = 0;
int enc_RA = 0;
int enc_RB = 0;

Dist* mouseDist = new Dist();


void enc_LA_inc(void) {
  enc_LA += 1;
}

void enc_LB_inc(void) {
  enc_LB += 1;
}

void enc_RA_inc(void) {
  enc_RA += 1;
}

void enc_RB_inc(void) {
  enc_RB += 1;
}

void encoderReset(void) {
  enc_LA = 0;
  enc_LB = 0;
  enc_RA = 0;
  enc_RB = 0;

  mouseDist->left = 0;
  mouseDist->right = 0;
}


void encoderLoop(void) {
  encoderVals();
}

Dist* encoderVals(void) {

  mouseDist->left = enc_LA;
  mouseDist->right = enc_RA;

  return mouseDist;
}

void encoderSetup(void) {

  pinMode(EncoderL_A, INPUT);
  attachInterrupt(EncoderL_A, enc_LA_inc, CHANGE);

  pinMode(EncoderL_B, INPUT);
  attachInterrupt(EncoderL_B, enc_LB_inc, CHANGE);

  pinMode(EncoderR_A, INPUT);
  attachInterrupt(EncoderR_A, enc_RA_inc, CHANGE);

  pinMode(EncoderR_B, INPUT);
  attachInterrupt(EncoderR_B, enc_RB_inc, CHANGE);

  encoderReset();
}

void encoderPrint(int del) {
  encoderPrint();
  delay(del);
}

void encoderPrint(void) {
  // make sure motorspeed is going forward

  Serial.print("LA: ");
  Serial.println(enc_LA);

  Serial.print("LB: ");
  Serial.println(enc_LB);

  Serial.print("Computed L: ");
  Serial.println(mouseDist->left);

  Serial.print("R: A");
  Serial.println(enc_RA);

  Serial.print("R: B");
  Serial.println(enc_RB);

  Serial.print("Computed R: ");
  Serial.println(mouseDist->right);
}
