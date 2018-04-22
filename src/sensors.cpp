# include "../headers/sensors.hpp"
# include <Arduino.h>

void sensorSetup(void) {
	pinMode(Emitter_L, OUTPUT);
	digitalWrite(Emitter_L, HIGH);

	pinMode(Emitter_R, OUTPUT);
	digitalWrite(Emitter_R, HIGH);

	pinMode(Emitter_FR, OUTPUT);
	digitalWrite(Emitter_FR, HIGH);

	pinMode(Emitter_FL, OUTPUT);
	digitalWrite(Emitter_FL, HIGH);

	pinMode(Receiver_L, INPUT);
	pinMode(Receiver_R, INPUT);
	pinMode(Receiver_FR, INPUT);
	pinMode(Receiver_FL, INPUT);
}

void sensorTestPrint(void) {
	Serial.print("L: ");
	Serial.println(analogRead(Receiver_L));

	Serial.print("FL: ");
	Serial.println(analogRead(Receiver_FL));

	Serial.print("R: ");
	Serial.println(analogRead(Receiver_R));

	Serial.print("FR: ");
	Serial.println(analogRead(Receiver_FR));

	Serial.println("\n");

	delay(500);
}