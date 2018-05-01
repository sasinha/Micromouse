# include "../headers/encoders.hpp"
# include <Arduino.h>

int enc_LA = 0;
int enc_LB = 0;
int enc_RA = 0;
int enc_RB = 0;


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

void resetEncoders(void) {
  enc_LA = 0;
  enc_LB = 0;
  enc_RA = 0;
  enc_RB = 0;
}


void setupEncoders(void) {

  pinMode(EncoderL_A, INPUT);
  attachInterrupt(EncoderL_A, enc_LA_inc, CHANGE);

  pinMode(EncoderL_B, INPUT);
  attachInterrupt(EncoderL_B, enc_LB_inc, CHANGE);

  pinMode(EncoderR_A, INPUT);
  attachInterrupt(EncoderR_A, enc_RA_inc, CHANGE);

  pinMode(EncoderR_B, INPUT);
  attachInterrupt(EncoderR_B, enc_RB_inc, CHANGE);

  resetEncoders();
}

void findFirstForward(void) {
  // make sure motorspeed is going forward
  if (enc_LA > enc_LB) {
    Serial.println("L: A");
    
  } else {
    Serial.println("L: B");
  }

  Serial.println(enc_LA);
  Serial.println(enc_LB);

  if (enc_RA > enc_RB) {
    Serial.println("R: A");
  } else {
    Serial.println("R: B");
  }

  Serial.println(enc_RA);
  Serial.println(enc_RB);
}
