#include<iostream>
#include<stdio.h>
#include<string>
#include"center.h"
#include<queue>
#include"job.h"
using namespace std;

Center manageMethod(queue<Job> joblist,Center machine) {
	int num;
	int workingjob;
	int jobnum=0;
	int smallProcesser;
	int mediumProcesser;
	int largeProcesser;
	int finishNum=0;
	int timecost=0;
	int i;
	num = joblist.size();
	Job *works=new Job[num];
	Job *working = new Job[num];

	for (int i = 0; i < num; i++) {
		works[i] = joblist.pop();
	}
	for (int i = num; i >0; i--) {
		int time = 0;
		for (int j = 0; j < i; j++) {
			time = time + works[j].getwaitingTime;
			works[i].setwaitingTime(time);
		}
	}
	//calculate processer
	smallProcesser = machine.getcurrentProcesser * 0.1;
	mediumProcesser = machine.getcurrentProcesser * 0.4;
	largeProcesser = machine.getcurrentProcesser * 0.5;
	

	while (finishNum<num) {
	
		if (works[jobnum].getjobType=='short'&&works[jobnum].getwaitingTime==0) {
			if (works[jobnum].getjobProcesser < smallProcesser) {
				smallProcesser = smallProcesser - works[jobnum].getjobProcesser;
				works[jobnum].settimeStart = timecost;
				workingjob = workingjob + 1;
				working[workingjob - 1] = works[jobnum];
				jobnum = jobnum + 1;
			}
		}
		else if(works[jobnum].getjobType=='medium'&&works[jobnum].getwaitingTime == 0){
			if (works[jobnum].getjobProcesser < mediumProcesser) {
				mediumProcesser = mediumProcesser - works[jobnum].getjobProcesser;
				works[jobnum].settimeStart = timecost;
				workingjob = workingjob + 1;
				working[workingjob - 1] = works[jobnum];
				jobnum = jobnum + 1;

			}
		}
		else if (works[jobnum].getjobType=='large' && works[jobnum].getwaitingTime == 0) {
			if (works[jobnum].getjobProcesser < largeProcesser) {
				largeProcesser = largeProcesser - works[jobnum].getjobProcesser;
				works[jobnum].settimeStart = timecost;
				workingjob = workingjob + 1;
				working[workingjob - 1] = works[jobnum];
				jobnum = jobnum + 1;
			}
		}



		for (int i = 0; i < workingjob; i++) {
			if (working[i].gettimeCurrent > 0) {
				working[i].gettimeCurrent = working[i].gettimeCurrent - 1;

			}
			else if (working[i].gettimeCurrent = 0) {
				if (working[i].getjobType == 'short') {
					
						smallProcesser = smallProcesser + working[i].getjobProcesser;
						working[i].settimeCurrent(-1);
						working[i].settimeFinish = timecost;
						finishNum = finishNum + 1;
					
				}
				else if (working[i].getjobType == 'medium') {
					
						mediumProcesser = mediumProcesser + working[i].getjobProcesser;
						working[i].settimeCurrent(-1);
						working[i].settimeFinish = timecost;
						finishNum = finishNum + 1;
				}
				else if (working[i].getjobType == 'large') {
					
						largeProcesser = largeProcesser + working[i].getjobProcesser;
						working[i].settimeCurrent(-1);
						working[i].settimeFinish = timecost;
						finishNum = finishNum + 1;
					
				}
			}

		}
		for (int i = 0; i < num; i++) {
			double time = 0;
			time = works[i].getwaitingTime - 1;
			works[i].setwaitingTime(time);
		}
		timecost = timecost + 1;

	
	}



}