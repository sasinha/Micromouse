# include "../headers/sensors.hpp"
# include <Arduino.h>

// Premapped starting and ending range values
#define RAW_START_L 20;
#define RAW_START_FL 20;
#define RAW_START_FR 20;
#define RAW_START_R 20;

#define RAW_END_L 20;
#define RAW_END_FL 20;
#define RAW_END_FR 20;
#define RAW_END_R 20;

// Mapped starting and ending range values
#define MAPPED_START 0;
#define MAPPED_END 255;

void sensorSetup(void) {
	pinMode(Emitter_L, OUTPUT);
	digitalWrite(Emitter_L, HIGH);

	pinMode(Emitter_FL, OUTPUT);
	digitalWrite(Emitter_FL, HIGH);

	pinMode(Emitter_FR, OUTPUT);
	digitalWrite(Emitter_FR, HIGH);
	
	pinMode(Emitter_R, OUTPUT);
	digitalWrite(Emitter_R, HIGH);

	pinMode(Receiver_L, INPUT);
	pinMode(Receiver_FL, INPUT);
	pinMode(Receiver_FR, INPUT);
	pinMode(Receiver_R, INPUT);
}

int getSensorRead(int receiverPin)
{
	int RAW_START;
	int RAW_END;
	int emitter;
	switch(receiverPin)
	{
		case Receiver_L:
			RAW_START = RAW_START_L;
			RAW_END = RAW_END_L;

			emitter = Emitter_L;
			break;
		case Receiver_FL:
			RAW_START = RAW_START_FL;
			RAW_END = RAW_END_FL;

			emitter = Emitter_FL;
			break;
		case Receiver_FR:
			RAW_START = RAW_START_FR;
			RAW_END = RAW_END_FR;

			emitter = Emitter_FR;
			break;
		case Receiver_R:
			RAW_START = RAW_START_R;
			RAW_END = RAW_END_R;

			emitter = Emitter_R;
			break;
		default:
			return -1; 
	}
	digitalWrite(emitter, HIGH);

	int toRet = map(receiverPin, RAW_START,
		RAW_END, MAPPED_START, MAPPED_END);


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
