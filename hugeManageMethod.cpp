#include<iostream>
#include<stdio.h>
#include<string>
#include"center.h"
#include<queue>
#include"job.h"
#include"hugeManageMethod.h"
#include"resource.h"
using namespace std;

void hugeManageMethod(queue<Job> joblist, Center machine, Resource IT, Resource Lr, Resource Mr, Resource Sr, Resource Ls, Resource Ms, Resource Ss) {

	int num;
	int workingjob = 0;
	int GPUworking = 0;
	int jobnum = 0;
	int nomalProcesser;
	int GPUProcesser;
	int finishNum = 0;
	int timecost = 0;
	int passNum = 0;

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
	for (int i = num; i > 0; i--) {
		double time = 0;
		for (int j = 0; j < i; j++) {
			time = works[j].getwaitingTime() + time;

		}
		works[i].setwaitingTime(time-6240);
	}
	int Hnum = 0;
	int GPUnum = 0;
	for (int i = 0; i < num; i++) {
		//all short jobs
		if (works[i].getjobType() == "huge" && works[i].getuseGPU() == "n") {
			Hnum++;
		}
		else if (works[i].getjobType() == "huge" && works[i].getuseGPU() == "y") {
			GPUnum++;
		}
	}
	
	Job* GPUwork = new Job[GPUnum];
	Job* Hwork = new Job[Hnum];

	GPUnum = 0;
	Hnum = 0;
	for (int i = 0; i < num; i++) {
		if (works[i].getjobType() == "huge" && works[i].getuseGPU() == "n") {
			Hwork[Hnum] = works[i];
			Hnum++;
		}
		else if (works[i].getjobType() == "huge" && works[i].getuseGPU() == "y") {
			GPUwork[GPUnum] = works[i];
			GPUnum++;
		}
	}
	delete[]works;

	int GPUorder = 0;
	int Horder = 0;

	nomalProcesser = 120 * 16;
	GPUProcesser = 8 * 2 * 16;
	
	while (passNum < num) {
		//Gpu work
		while (1.5 * (GPUwork[GPUorder].getjobProcesser()) < GPUProcesser && GPUwork[GPUorder].getwaitingTime() <= 0 && GPUorder < GPUnum) {
			if (GPUwork[GPUorder].getuserType() == "IT") {

				if (IT.getGroupResource() >= 1.5 * GPUwork[GPUorder].getResource())
				{
					GPUProcesser = GPUProcesser - GPUwork[GPUorder].getjobProcesser();
					GPUwork[GPUorder].settimeStart(timecost);
					GPUworking = GPUworking + 1;
					gpuworking[GPUworking - 1] = GPUwork[GPUorder];


					IT.setGroupResource(IT.getGroupResource() - 1.5 * GPUwork[GPUorder].getResource());
					GPUorder = GPUorder + 1;
				}
				else {
					cout << "IT group have no resource" << endl;
					GPUorder = GPUorder + 1;
					passNum++;
				}
			}
			else if (GPUwork[GPUorder].getuserType() == "Lr")
			{
				if (IT.getGroupResource() >= 1.5 * GPUwork[GPUorder].getResource())
				{
					GPUProcesser = GPUProcesser - GPUwork[GPUorder].getjobProcesser();
					GPUwork[GPUorder].settimeStart(timecost);
					GPUworking = GPUworking + 1;
					gpuworking[GPUworking - 1] = GPUwork[GPUorder];


					Lr.setGroupResource(Lr.getGroupResource() - 1.5 * GPUwork[GPUorder].getResource());
					GPUorder = GPUorder + 1;

				}
				else {
					cout << "LR group have no resource" << endl;
					GPUorder = GPUorder + 1;
					passNum++;
				}
			}
			else if (GPUwork[GPUorder].getuserType() == "Mr")
			{
				if (Mr.getGroupResource() >= 1.5 * GPUwork[GPUorder].getResource())
				{
					GPUProcesser = GPUProcesser - GPUwork[GPUorder].getjobProcesser();
					GPUwork[GPUorder].settimeStart(timecost);
					GPUworking = GPUworking + 1;
					gpuworking[GPUworking - 1] = GPUwork[GPUorder];


					Mr.setGroupResource(Mr.getGroupResource() - 1.5 * GPUwork[GPUorder].getResource());
					GPUorder = GPUorder + 1;
				}
				else {
					cout << "MR group have no resource" << endl;
					GPUorder = GPUorder + 1;
					passNum++;
				}
			}
			else if (GPUwork[GPUorder].getuserType() == "Sr")
			{
				if (Sr.getGroupResource() >= 1.5 * GPUwork[GPUorder].getResource())
				{
					GPUProcesser = GPUProcesser - GPUwork[GPUorder].getjobProcesser();
					GPUwork[GPUorder].settimeStart(timecost);
					GPUworking = GPUworking + 1;
					gpuworking[GPUworking - 1] = GPUwork[GPUorder];


					Sr.setGroupResource(Sr.getGroupResource() - 1.5 * GPUwork[GPUorder].getResource());
					GPUorder = GPUorder + 1;
				}
				else {
					cout << "SR group have no resource" << endl;
					GPUorder = GPUorder + 1;
					passNum++;
				}
			}
			else if (GPUwork[GPUorder].getuserType() == "Ls")
			{
				if (Ls.getGroupResource() >= 1.5 * GPUwork[GPUorder].getResource())
				{
					GPUProcesser = GPUProcesser - GPUwork[GPUorder].getjobProcesser();
					GPUwork[GPUorder].settimeStart(timecost);
					GPUworking = GPUworking + 1;
					gpuworking[GPUworking - 1] = GPUwork[GPUorder];


					Ls.setGroupResource(Ls.getGroupResource() - 1.5 * GPUwork[GPUorder].getResource());
					GPUorder = GPUorder + 1;
				}
				else {
					cout << "LS group have no resource" << endl;
					GPUorder = GPUorder + 1;
					passNum++;
				}
			}
			else if (GPUwork[GPUorder].getuserType() == "Ms")
			{
				if (Ms.getGroupResource() >= 1.5 * GPUwork[GPUorder].getResource())
				{
					GPUProcesser = GPUProcesser - GPUwork[GPUorder].getjobProcesser();
					GPUwork[GPUorder].settimeStart(timecost);
					GPUworking = GPUworking + 1;
					gpuworking[GPUworking - 1] = GPUwork[GPUorder];


					Ms.setGroupResource(Ms.getGroupResource() - 1.5 * GPUwork[GPUorder].getResource());
					GPUorder = GPUorder + 1;
				}
				else {
					cout << "MS group have no resource" << endl;
					GPUorder = GPUorder + 1;
					passNum++;
				}
			}
			else if (GPUwork[GPUorder].getuserType() == "Ss")
			{
				if (Ss.getGroupResource() >= 1.5 * GPUwork[GPUorder].getResource())
				{
					GPUProcesser = GPUProcesser - GPUwork[GPUorder].getjobProcesser();
					GPUwork[GPUorder].settimeStart(timecost);
					GPUworking = GPUworking + 1;
					gpuworking[GPUworking - 1] = GPUwork[GPUorder];


					Ss.setGroupResource(Ss.getGroupResource() - 1.5 * GPUwork[GPUorder].getResource());
					GPUorder = GPUorder + 1;
				}
				else {
					cout << "SS group have no resource" << endl;
					GPUorder = GPUorder + 1;
					passNum++;
				}
			}
		}
		while (Hwork[Horder].getjobProcesser() < nomalProcesser && Hwork[Horder].getwaitingTime() <= 0 && Horder < Hnum) {
			if (Hwork[Horder].getuserType() == "IT") {

				if (IT.getGroupResource() >= Hwork[Horder].getResource())
				{
					nomalProcesser = nomalProcesser - Hwork[Horder].getjobProcesser();
					Hwork[Horder].settimeStart(timecost);
					workingjob = workingjob + 1;
					working[workingjob - 1] = Hwork[Horder];


					IT.setGroupResource(IT.getGroupResource() - Hwork[Horder].getResource());
					Horder = Horder + 1;
				}
				else {
					cout << "IT group have no resource" << endl;
					Horder = Horder + 1;
					passNum++;
				}
			}
			else if (Hwork[Horder].getuserType() == "Lr")
			{
				if (Lr.getGroupResource() >= Hwork[Horder].getResource()) {
					nomalProcesser = nomalProcesser - Hwork[Horder].getjobProcesser();
					Hwork[Horder].settimeStart(timecost);
					workingjob = workingjob + 1;
					working[workingjob - 1] = Hwork[Horder];


					Lr.setGroupResource(Lr.getGroupResource() - Hwork[Horder].getResource());
					Horder = Horder + 1;
				}
				else {
					cout << "Lr group have no resource" << endl;
					Horder = Horder + 1;
					passNum++;
				}
			}
			else if (Hwork[Horder].getuserType() == "Mr")
			{
				if (Mr.getGroupResource() >= Hwork[Horder].getResource()) {
					nomalProcesser = nomalProcesser - Hwork[Horder].getjobProcesser();
					Hwork[Horder].settimeStart(timecost);
					workingjob = workingjob + 1;
					working[workingjob - 1] = Hwork[Horder];


					Mr.setGroupResource(Mr.getGroupResource() - Hwork[Horder].getResource());
					Horder = Horder + 1;
				}
				else {
					cout << "Mr group have no resource" << endl;
					Horder = Horder + 1;
					passNum++;
				}
			}
			else if (Hwork[Horder].getuserType() == "Sr")
			{
				if (Sr.getGroupResource() >= Hwork[Horder].getResource())
				{
					nomalProcesser = nomalProcesser - Hwork[Horder].getjobProcesser();
					Hwork[Horder].settimeStart(timecost);
					workingjob = workingjob + 1;
					working[workingjob - 1] = Hwork[Horder];


					Sr.setGroupResource(Sr.getGroupResource() - Hwork[Horder].getResource());
					Horder = Horder + 1;
				}
				else {
					cout << "Sr group have no resource" << endl;
					Horder = Horder + 1;
					passNum++;
				}
			}
			else if (Hwork[Horder].getuserType() == "Ls")
			{
				if (Ls.getGroupResource() >= Hwork[Horder].getResource()) {
					nomalProcesser = nomalProcesser - Hwork[Horder].getjobProcesser();
					Hwork[Horder].settimeStart(timecost);
					workingjob = workingjob + 1;
					working[workingjob - 1] = Hwork[Horder];


					Ls.setGroupResource(Ls.getGroupResource() - Hwork[Horder].getResource());
					Horder = Horder + 1;
				}
				else {
					cout << "Ls group have no resource" << endl;
					Horder = Horder + 1;
					passNum++;
				}
			}
			else if (Hwork[Horder].getuserType() == "Ms")
			{
				if (Ms.getGroupResource() >= Hwork[Horder].getResource()) {
					nomalProcesser = nomalProcesser - Hwork[Horder].getjobProcesser();
					Hwork[Horder].settimeStart(timecost);
					workingjob = workingjob + 1;
					working[workingjob - 1] = Hwork[Horder];


					Ms.setGroupResource(Ms.getGroupResource() - Hwork[Horder].getResource());
					Horder = Horder + 1;
				}
				else {
					cout << "Ms group have no resource" << endl;
					Horder = Horder + 1;
					passNum++;
				}
			}
			else if (Hwork[Horder].getuserType() == "Ss")
			{
				if (Ss.getGroupResource() >= Hwork[Horder].getResource()) {
					nomalProcesser = nomalProcesser - Hwork[Horder].getjobProcesser();
					Hwork[Horder].settimeStart(timecost);
					workingjob = workingjob + 1;
					working[workingjob - 1] = Hwork[Horder];


					Ss.setGroupResource(Ss.getGroupResource() - Hwork[Horder].getResource());
					Horder = Horder + 1;
				}
				else {
					cout << "Ss group have no resource" << endl;
					Horder = Horder + 1;
					passNum++;
				}
			}
		}

		for (int i = 0; i < workingjob; i++) {
			if (working[i].gettimeCurrent() > 0) {
				working[i].settimeCurrent(working[i].gettimeCurrent() - 1.0);

			}
			else if (working[i].gettimeCurrent() == 0)
			{
				

					nomalProcesser = nomalProcesser + working[i].getjobProcesser();
					working[i].settimeCurrent(-1);
					working[i].settimeFinish(timecost);
					Finish[finishNum] = working[i];
					finishNum = finishNum + 1;
					passNum++;

				
				
			}

		}

		for (int i = 0; i < GPUworking; i++) {
			if (gpuworking[i].gettimeCurrent() > 0) {
				gpuworking[i].settimeCurrent(working[i].gettimeCurrent() - 1.0);

			}
			else if (working[i].gettimeCurrent() == 0)
			{


				GPUProcesser = GPUProcesser + working[i].getjobProcesser();
				gpuworking[i].settimeCurrent(-1);
				gpuworking[i].settimeFinish(timecost);
				Finish[finishNum] = gpuworking[i];
				finishNum = finishNum + 1;
				passNum++;


			}

		}

		if (timecost < 3720) {
			timecost = timecost + 1;
		}
		else {
			break;
		}
		

	}
	cout<<"huge work"<<endl;
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

	for (int i = 0; i < finishNum; i++) {
		cout << "job id:" << Finish[i].getjobID() << "job type" << Finish[i].getjobType() << endl;
	}


}