// Motor setup

# pragma once

# include "macros.hpp"

typedef struct Dist {
	int left;
	int right;
} Dist;

extern Dist* mouseDist;

void encoderReset(void);

void encoderSetup(void);

Dist* encoderVals(void);
void encoderLoop(void);


void encoderPrint(void);
void encoderPrint(int del);
