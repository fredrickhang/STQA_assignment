#include"job.h"
#include"inputMethod.h"
#include "exponentialDistribution.h"
#include <iostream>
#include<queue>
#include"resource.h"

int main() {
	queue<Job> joblist2;
	double randomWaitTimeList[500];
	inputMethod(joblist2);

	exponentialDistribution(randomWaitTimeList);
	

	
	

	return 0;
}



