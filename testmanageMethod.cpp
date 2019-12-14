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

void testmanageMethods() {
	Job a;
	Job b;
	Job c;
	//a
	a.setjobID(1);
	a.setjobProcesser(16);
	a.setjobTime(60);
	a.setjobType("short");
	a.setResource(1);
	a.settimeCurrent(60);
	a.setuseGPU("n");
	a.setuserType("IT");
	a.setwaitingTime(2);

	//b
	b.setjobID(2);
	b.setjobProcesser(32);
	b.setjobTime(60*8);
	b.setjobType("medium");
	b.setResource(3);
	b.settimeCurrent(60*8);
	b.setuseGPU("n");
	b.setuserType("IT");
	b.setwaitingTime(9);

	//c
	c.setjobID(3);
	c.setjobProcesser(32);
	c.setjobTime(60 * 16);
	c.setjobType("small");
	c.setResource(3);
	c.settimeCurrent(60*16);
	c.setuseGPU("n");
	c.setuserType("Lr");
	c.setwaitingTime(60);


	queue<Job> testlist;
	testlist.push(a);
	testlist.push(b);
	//testlist.push(c);

	vector<Resource> resourceist;
	Resource IT;
	Resource Lr;
	Resource Mr;
	Resource Sr;
	Resource Ls;
	Resource Ms;
	Resource Ss;
	Center center;

	resourceist = initializeResources(IT, Lr, Mr, Sr, Ls, Ms, Ss);


	center.setcurrentProcesser(120 * 16);
	manageMethod(testlist, center, resourceist[0], resourceist[1], resourceist[2], resourceist[3], resourceist[4], resourceist[5], resourceist[6]);
}