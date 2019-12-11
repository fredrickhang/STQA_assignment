#include"job.h"
#include"inputMethod.h"
#include "exponentialDistribution.h"
#include <iostream>
#include<queue>
#include"resource.h"
#include"InitializeResources.h"
#include"center.h"
#include"manageMethod.h"
int main() {

	queue<Job> joblist2;
	Resource IT;
	Resource Lr;
	Resource Mr;
	Resource Sr;
	Resource Ls;
	Resource Ms;
	Resource Ss;
	Center center;
	inputMethod(joblist2);
	initializeResources(IT,Lr,Mr,Sr,Ls,Ms,Ss);
	center.setcurrentProcesser(120*16);
	

	
	

	return 0;
}



