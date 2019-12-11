#include "exponentialDistribution.h"
#include <random>
#include <iostream>
using namespace std;
void exponentialDistribution(double randomWaitTimeList[500]) {
	
	random_device rd;
	exponential_distribution<>rng(1 / 0.2);
	mt19937 rnd_gen(rd());

	for (int k = 0; k < 500; k++) {
		randomWaitTimeList[k] = rng(rnd_gen);
		//std::cout << rng(rnd_gen) * 60 << "\n";
	}

	
}