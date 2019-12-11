
#include<vector>
#include"job.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<math.h>
#include<queue>
#include"stringSplitTools.h"
#include"exponentialDistribution.h"
using namespace std;

void inputMethod(queue<Job> jobList) {
	double randomWaitTimeList[500];
	queue<Job> jlist;
	ifstream inFile("datainput.csv", ios::in);
	if (!inFile) {
		cout << "can not find file, please create a file named inputdata.csv";
	
	}
	vector<string> res1;
	int i = 0;
	string line1;
	string field;
	while (getline(inFile, line1)) {
		string field;
		istringstream sin(line1);
		while (getline(sin, field)) {

			res1.push_back(field);
		}
		if (i>50) {
			break;
		}
		//cout << res1[i]<< endl;
		i++;
	}

	Job inputjob;
	exponentialDistribution(randomWaitTimeList);
	for (int k = 0; k < res1.size()-1;k++) {
		string re = res1[k+1];
		vector<string> job;
		job=split(re, ",");
		inputjob.setuserType(job[0]);
		inputjob.setjobType(job[1]);
		inputjob.setjobProcesser(atoi(job[2].c_str()));
		inputjob.setuseGPU(job[3]);
		inputjob.settimeCurrent(ceil(randomWaitTimeList[0]));
		inputjob.setjobID(k+1);
		jlist.push(inputjob);
	}
	
	while (!jlist.empty) {
		jobList.push(jlist.front());
		jlist.pop();

	}
	

	


	

}