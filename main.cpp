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
	vector<Resource> resourceist;
	Resource IT;
	Resource Lr;
	Resource Mr;
	Resource Sr;
	Resource Ls;
	Resource Ms;
	Resource Ss;
	Center center;

	resourceist= initializeResources(IT, Lr, Mr, Sr, Ls, Ms, Ss);

	
	center.setcurrentProcesser(120 * 16);
	joblist2=inputMethod(joblist2);

	manageMethod(joblist2,center, resourceist[0], resourceist[1], resourceist[2], resourceist[3], resourceist[4], resourceist[5], resourceist[6]);

	
	

	return 0;
}



