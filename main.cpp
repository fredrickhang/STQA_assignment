#include"job.h"
#include"inputMethod.h"
#include <iostream>
#include<queue>
#include"resource.h"
#include"InitializeResources.h"
#include"center.h"
#include"manageMethod.h"
#include"testReadfile.h"
#include"stringSplitTools.h"
#include "testStringSplit.h"
#include<ctime>
#include "testBadDatafile.h"
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

	///*test part*/
	////test readfile function
	//testReadfile();
	////test split string function, split as ','
	//testStringSplit();
	////test exponential probability distribution,
	//srand(time(0));
	//for (int i = 0; i < 10;i++) {
	//	
	//	double num = rand() % 10 + 1.0;
	//	double waitTime = 60 * (1 / num);
	//	cout << waitTime << endl;
	//}
	////Combining inputMethod interface test and bad data test
	//testBadDatafile();
	

	return 0;
}



