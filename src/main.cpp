# include "../headers/sensors.hpp"
# include "../headers/motorLogic.hpp"
# include "../headers/encoders.hpp"
# include "../headers/runDir.hpp"
# include "../headers/states.hpp"

# include "../headers/macros.hpp"
# include "../headers/main.hpp"

# include <Arduino.h>

void setupMM(void) {
	sensorSetup();
	motorSetup();
	encoderSetup();

	// motorSpeedLeft = MID_SPEED;
	// motorSpeedRight = MID_SPEED;

}

enum MMState state = COMPUTE;
bool finished;
void loopMM(void) {

	switch (state) {
		case COMPUTE:
			

			setDist(10000);

			state = STRAIGHT;
			delay(500);
			break;
		case STRAIGHT:

			finished = runStraight();
			if (finished) {
				state = STOP;
			}

			break;
		case TURN:

			break;

		case STOP:

			break;

	}

	getSensorValsLoop();
	motorRunLoop();
	encoderLoop();


	// encoderPrint(500);
	// sensorTestPrintLoop(500);

}