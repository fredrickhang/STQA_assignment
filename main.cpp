#include"inputMethod.h"
#include "exponentialDistribution.h"
#include <chrono>
#include <iostream>
#include<ctime>
#include <map>
#include <iomanip>
#include<queue>
#include"job.h"
#include"resource.h"
//double random_unint(unsigned int min, unsigned int max, unsigned int seed = 0)
//{
//	/*static std::default_random_engine e(seed);
//	static std::uniform_real_distribution<double> u(0, 10);*/
//	return u(e);
//}
int main() {
	queue<Job> joblist;
	double randomWaitTimeList[500];
	inputMethod(joblist);

	exponentialDistribution(randomWaitTimeList);
	

	
	

	return 0;
}



