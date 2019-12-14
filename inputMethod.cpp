
#include<vector>
#include"job.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<math.h>
#include<queue>
#include"stringSplitTools.h"
#include<cstdlib>
using namespace std;

queue<Job> inputMethod(queue<Job> jobList1) {
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
	double num = 1;
	double waitTime;
	for (int k = 0; k < res1.size()-1;k++) {
		string re = res1[k+1];
		vector<string> job;
		job=split(re, ",");
		inputjob.setuserType(job[0]);
		inputjob.setjobType(job[1]);
		inputjob.setjobProcesser(atoi(job[2].c_str()));
		inputjob.setuseGPU(job[3]);
		if (job[0]!="IT"&& job[0] != "Sr" && job[0] != "Mr" && job[0] != "Lr" && job[0] != "SS" && job[0] != "Ms" && job[0] != "Ls") {
			cout << "data wrong, please insert right data" << endl;
			break;
		
		}
		if (job[1]=="short") {
			num=num+1;
			waitTime = 60*(1/(num));
			std::cout << waitTime << endl;
			inputjob.setwaitingTime(ceil(waitTime));
			inputjob.settimeCurrent(60);
		
		}
		else if (job[1] == "medium") {
			num = num + 1;
			waitTime = 60 * (1 / (num));
			std::cout << waitTime << endl;
			inputjob.settimeCurrent(480);
			inputjob.setwaitingTime(ceil(waitTime));
		}
		else if (job[1]=="large") {
			
			num = num + 1;
			waitTime = 60 * (1 / (num));
			std::cout << waitTime << endl;
			inputjob.settimeCurrent(960);
			inputjob.setwaitingTime(ceil(waitTime));
		}
		else if (job[1]=="huge") {
			
			num = num + 1;
			waitTime = 60 * (1 / (num));
			std::cout << waitTime << endl;
			inputjob.setwaitingTime(ceil(waitTime));
		
		}
		else {
			cout << "data wrong, please insert right data" << endl;
			break;
		}
		inputjob.setjobID(k+1);
		inputjob.setResource(atoi(job[4].c_str()));
		jlist.push(inputjob);
	}
	bool button = true;
	while (button) {
		if (jlist.empty()) {
		
			button = false;
			break;
		}
		jobList1.push(jlist.front());
	
		jlist.pop();
	}
	

	

	return jobList1;

	

}