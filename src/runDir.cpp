# include "../headers/runDir.hpp"
# include "../headers/motorLogic.hpp"

# include "../headers/encoders.hpp"

# include <AutoPID.h>

int ticksNeeded = 0;

double input, setpoint, output;

// Turn tunings and output mins and maxs as constants/macros
AutoPID straightPID(&input, &setpoint, &output, 0, MAX_SPEED, 1, 1, 1);


void setDist(int setTicks) {
	ticksNeeded = setTicks;

	motorSpeedLeft = MID_SPEED;
}

bool runStraight(void) {
	if (ticksNeeded <= 0) {
		straightPID.stop();
		motorSpeedLeft = 0;
		motorSpeedRight = 0;

		encoderReset();
		ticksNeeded = 0;
		return true;
	}

	motorSpeedRight = MID_SPEED;

	input = (double) mouseDist->left;
	setpoint = (double) mouseDist->right;
	straightPID.run();

	// Serial.println(output);
	motorSpeedLeft = (int) output;

	ticksNeeded -= mouseDist->right;
	
	return false;
}


