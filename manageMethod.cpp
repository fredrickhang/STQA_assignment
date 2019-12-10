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
	Job *Swork = new Job[num];//small job queue
	Job *Mwork = new Job[num];//medium job queue
	Job *Lwork = new Job[num];//large job queue
	Job *Finish = new Job[num];//finish job queue

	//calculate waiting time of each jobs
	for (int i = 0; i < num; i++) {
		works[i] = joblist.front();
		joblist.pop();
	}
	for (int i = num; i >0; i--) {
		double time = 0;
		for (int j = 0; j < i; j++) {
			time = works[j].getwaitingTime()+time;
			
		}
		works[i].setwaitingTime(time);
	}
	//group job
	int Snum = 0;
	int Mnum = 0;
	int Lnum = 0;
	for (int i = 0; i < num; i++) {
		//all short jobs
		if (works[i].getjobType() == "short") {
			Swork[Snum] = works[i];
			Snum++;
		}
		//all medium jobs
		else if (works[i].getjobType() == "medium") {
			Mwork[Mnum] = works[i];
			Mnum++;
		}
		//all large jobs
		else if (works[i].getjobType() == "large") {
			Lwork[Lnum] = works[i];
			Lnum++;
		}
	}
	//calculate processer
	smallProcesser = machine.getcurrentProcesser() /10;
	mediumProcesser = machine.getcurrentProcesser() * 4/10;
	largeProcesser = machine.getcurrentProcesser() * 5/10;
	


	//main method
	int Sorder = 0;
	int Morder = 0;
	int Lorder = 0;
	while (finishNum<num) {
	
		//input short job to mechine
			while (Swork[Sorder].getjobProcesser() < smallProcesser&&Swork[Sorder].getwaitingTime()<=0) {
				smallProcesser = smallProcesser - Swork[Sorder].getjobProcesser();
				Swork[Sorder].settimeStart(timecost);
				workingjob = workingjob + 1;
				working[workingjob - 1] = Swork[Sorder];
				Sorder = Sorder + 1;
			}
		
		//input merdium jobs to mechine
			while (Mwork[Morder].getjobProcesser() < mediumProcesser && Mwork[Morder].getwaitingTime() <= 0) {
				mediumProcesser = mediumProcesser - Mwork[Morder].getjobProcesser();
				Mwork[Morder].settimeStart(timecost);
				workingjob = workingjob + 1;
				working[workingjob - 1] = Mwork[Morder];
				Morder = Morder + 1;

			}
		
		//input large jobs to mechine
			while (Lwork[Lorder].getjobProcesser() < largeProcesser&&Lwork[Lorder].getwaitingTime()<=0) {
				largeProcesser = largeProcesser - Lwork[Lorder].getjobProcesser();
				Lwork[Lorder].settimeStart ( timecost);
				workingjob = workingjob + 1;
				working[workingjob - 1] = Lwork[Lorder];
				Lorder = Lorder + 1;
			}
		



		for (int i = 0; i < workingjob; i++) {
			if (working[i].gettimeCurrent() > 0) {
				working[i].settimeCurrent( working[i].gettimeCurrent() - 1.0);

			}
			else if (working[i].gettimeCurrent() == 0)
			{
				if (working[i].getjobType() == "short") {
					
						smallProcesser = smallProcesser + working[i].getjobProcesser();
						working[i].settimeCurrent(-1);
						working[i].settimeFinish( timecost);
						Finish[finishNum] = working[i];
						finishNum = finishNum + 1;
					
				}
				else if (working[i].getjobType() == "medium") {
					
						mediumProcesser = mediumProcesser + working[i].getjobProcesser();
						working[i].settimeCurrent(-1);
						working[i].settimeFinish(timecost);
						Finish[finishNum] = working[i];
						finishNum = finishNum + 1;
				}
				else if (working[i].getjobType() == "large") {
					
						largeProcesser = largeProcesser + working[i].getjobProcesser();
						working[i].settimeCurrent(-1);
						working[i].settimeFinish(timecost);
						Finish[finishNum] = working[i];
						finishNum = finishNum + 1;
					
				}
			}

		}
		//judge time waiting
		for (int i = 0; i < Snum; i++) {
			double time;
			if (Swork[i].getwaitingTime() == 0) {
				Swork[i].settimeGeneration(timecost);
			}
			time = Swork[i].getwaitingTime() - 1;
			Swork[i].setwaitingTime(time);
		}
		
		for (int i = 0; i < Mnum; i++) {
			double time;
			if (Mwork[i].getwaitingTime() == 0) {
				Mwork[i].settimeGeneration(timecost);
			}
			time = Mwork[i].getwaitingTime() - 1;
			Mwork[i].setwaitingTime(time);
		}

		for (int i = 0; i < Lnum; i++) {
			double time;
			if (Lwork[i].getwaitingTime() == 0) {
				Lwork[i].settimeGeneration(timecost);
			}
			time = Lwork[i].getwaitingTime() - 1;
			Lwork[i].setwaitingTime(time);
		}

		

		timecost = timecost + 1;

	}

	machine.setJobNumber(finishNum);
	machine.setTimeCost(timecost);
	//calculate totally job running time
	double jobtime = 0;
	double avejobtime = 0;
	for (int i = 0; i < finishNum; i++) {
		jobtime = jobtime + (Finish[i].gettimeFinish() - Finish[i].gettimeStart());
	}
	avejobtime = jobtime / finishNum;
	machine.setJobTimeCost(jobtime);
	machine.setAverageTime(avejobtime);

	//calculate average waiting time
	double waitingTime = 0;
	double aveWaiting = 0;
	for (int i = 0; i < finishNum; i++) {
		waitingTime = waitingTime + (Finish[i].gettimeStart() - Finish[i].gettimeGeneration());
	}
	aveWaiting = waitingTime / finishNum;
	machine.setAverageWaitTime(aveWaiting);

	return machine;
	//
}