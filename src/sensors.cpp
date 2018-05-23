# include "../headers/sensors.hpp"
# include <Arduino.h>

// Premapped starting and ending range values
#define RAW_START_L 20
#define RAW_START_FL 20
#define RAW_START_FR 20
#define RAW_START_R 20

#define RAW_END_L 20
#define RAW_END_FL 20
#define RAW_END_FR 20
#define RAW_END_R 20

// Mapped starting and ending range values
#define MAPPED_START 0
#define MAPPED_END 255

Sensors* mouseSens = new Sensors();

void sensorSetup(void) {
	pinMode(Emitter_L, OUTPUT);
	pinMode(Emitter_FL, OUTPUT);
	pinMode(Emitter_FR, OUTPUT);
	pinMode(Emitter_R, OUTPUT);

	digitalWrite(Emitter_L, LOW);
	digitalWrite(Emitter_FL, LOW);
	digitalWrite(Emitter_FR, LOW);
	digitalWrite(Emitter_R, LOW);

	pinMode(Receiver_L, INPUT);
	pinMode(Receiver_FL, INPUT);
	pinMode(Receiver_FR, INPUT);
	pinMode(Receiver_R, INPUT);
}

void getSensorValsLoop(void) {
	getSensorVals();
}

Sensors* getSensorVals(void) {

	digitalWrite(Emitter_L, HIGH);
	digitalWrite(Emitter_FL, HIGH);
	digitalWrite(Emitter_FR, HIGH);
	digitalWrite(Emitter_R, HIGH);

	mouseSens->l = analogRead(Receiver_L);
	mouseSens->fl = analogRead(Receiver_FL);
	mouseSens->fr = analogRead(Receiver_FR);
	mouseSens->r = analogRead(Receiver_R);

	digitalWrite(Emitter_L, LOW);
	digitalWrite(Emitter_FL, LOW);
	digitalWrite(Emitter_FR, LOW);
	digitalWrite(Emitter_R, LOW);

	return mouseSens;
}

int i = 0;
void sensorTestPrintLoop(void) {
	Serial.println(i);

	Serial.print("L: ");
	// Serial.println(mouseSens->l);

	Serial.print("FL: ");
	// Serial.println(mouseSens->fl);
	
	Serial.print("FR: ");
	// Serial.println(mouseSens->fr);

	Serial.print("R: ");
	// Serial.println(mouseSens->r);


	i++;
	Serial.println("\n");
}

void sensorTestPrintLoop(int del) {
	sensorTestPrintLoop();
	delay(del);
}
