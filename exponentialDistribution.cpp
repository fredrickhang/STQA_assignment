#include "exponentialDistribution.h"
#include <random>
#include <iostream>

void exponentialDistribution(double randomWaitTimeList[500]) {
	
	std::random_device rd;
	std::exponential_distribution<>rng(1 / 0.2);
	std::mt19937 rnd_gen(rd());

	for (int k = 0; k < 500; k++) {
		randomWaitTimeList[k] = rng(rnd_gen);
		//std::cout << rng(rnd_gen) * 60 << "\n";
	}

	
}