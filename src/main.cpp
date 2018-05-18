# include "../headers/main.hpp"

void setupMM(void) {
	sensorSetup();
}


void loopMM(void) {

	getSensorValsLoop();
	sensorTestPrintLoop(500);
}