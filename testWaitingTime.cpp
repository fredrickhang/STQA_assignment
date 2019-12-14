#include<iostream>
#include<stdio.h>
#include<string>
#include"center.h"
#include<queue>
#include"job.h"
#include"testWaitingTime.h"

void testWaitingTime(queue<Job> joblist, Center machine) {
	int num;

	num = joblist.size();
	Job* works = new Job[num];
	Job* working = new Job[num];
	Job* gpuworking = new Job[num];
	Job* Finish = new Job[num];//finish job queue

	//calculate waiting time of each jobs
	for (int i = 0; i < num; i++) {
		works[i] = joblist.front();
		joblist.pop();
	}
	for (int i = num; i >= 0; i--) {
		double time = 0;
		for (int j = 0; j < i; j++) {
			time = works[j].getwaitingTime() + time;

		}
		works[i].setwaitingTime(time);
		works[i].settimeGeneration(time);
		cout << "job id: " << works[i].getjobID() << "  job waiting time: " << works[i].getwaitingTime()<< endl;
	}


}