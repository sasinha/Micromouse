// IR Sensor code

# pragma once

# include "macros.hpp"

typedef struct Sensors {
	int l, fl, r, fr;
} Sensors;

extern Sensors* mouseSens;

void sensorSetup(void);

Sensors* getSensorVals(void);
void getSensorValsLoop(void);

void sensorTestPrintLoop(void);
void sensorTestPrintLoop(int del);

