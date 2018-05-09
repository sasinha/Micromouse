// Motor setup

# pragma once

# include "macros.hpp"


typedef struct dist {
	float left;
	float right;
} dist;

void setupEncoders(void);

void findFirstForward(void);

dist getDist(void);


