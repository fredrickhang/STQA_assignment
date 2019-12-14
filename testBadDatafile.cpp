#include<ostream>
#include<fstream>
#include <iostream>
#include<vector>
#include<cstdlib>
#include<sstream>
#include"job.h"
#include "inputMethod.h""
#include<queue>
#include"testBadDatafile.h"
using namespace std;
void testBadDatafile() {
	Job j;
	queue<Job> jobList1;
	jobList1.push(j);
	queue<Job> jobList12;
	jobList12=inputMethod( jobList1);
	

}