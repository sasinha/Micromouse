# include "../headers/preSetup.hpp"
# include <Arduino.h>


bool diffMacroPins(void) {
	const int allMacros[] = {
		M1Forward,
		M1Reverse,
		M2Reverse,
		M2Forward,

		Emitter_L,
		Emitter_R,
		Emitter_FR,
		Emitter_FL,

		Receiver_L,
		Receiver_R,
		Receiver_FR,
		Receiver_FL,

		EncoderL_B,
		EncoderL_A,
		EncoderR_A,
		EncoderR_B,

		TeensyLED
	};

	int macroLen = MacroLen;

	int visited[MaximumPin];
	for (int i = 0; i < MaximumPin; i++) {
		visited[i] = 0;
	}

	for (int i = 0; i < macroLen; i++) {
		if (visited[allMacros[i]]) {
			return false;
		} else {
			visited[allMacros[i]] = 1;
		}
	}

	return true;
}