// Motor setup

# pragma once

# include "macros.hpp"


typedef struct dist {
	float left;
	float right;
} dist;

extern volatile dist mouseDist;

void setupEncoders(void);

void findFirstForward(void);

dist getDist(void);


