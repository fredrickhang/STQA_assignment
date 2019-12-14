#include<iostream>
#include<stdio.h>
#include<string>
#include"center.h"
#include<queue>
#include"job.h"
#include"manageMethod.h"
#include"resource.h"
#include <fstream>
using namespace std;

void manageMethod(queue<Job> joblist,Center machine,Resource IT,Resource Lr,Resource Mr,Resource Sr,Resource Ls,Resource Ms,Resource Ss) {
	//cout << joblist.size();
	
	int num;
	int workingjob=0;
	int GPUworking=0;
	int jobnum=0;
	int smallProcesser;
	int mediumProcesser;
	int largeProcesser;
	int GPUProcesser;
	int finishNum=0;
	int timecost=0;
	int passNum = 0;

	num = joblist.size();
	Job *works=new Job[num];
	Job *working = new Job[num];
	Job* gpuworking = new Job[num];
	Job *Finish = new Job[num];//finish job queue

	//calculate waiting time of each jobs
	for (int i = 0; i < num; i++) {
		works[i] = joblist.front();
		joblist.pop();
	}
	for (int i = num; i >=0; i--) {
		double time = 0;
		for (int j = 0; j < i; j++) {
			time = works[j].getwaitingTime()+time;
			
		}
		works[i].setwaitingTime(time);
		works[i].settimeGeneration(time);
	}
	//group job
	int Snum = 0;
	int Mnum = 0;
	int Lnum = 0;
	int GPUnum = 0;
	for (int i = 0; i < num; i++) {
		//all short jobs
		if (works[i].getjobType() == "short" && works[i].getuseGPU() == "n") {
			
			Snum++;
		}
		//all medium jobs
		else if (works[i].getjobType() == "medium" && works[i].getuseGPU() == "n") {
			
			Mnum++;
		}
		//all large jobs
		else if (works[i].getjobType() == "large" && works[i].getuseGPU() == "n") {
			
			Lnum++;
		}
		else if (works[i].getuseGPU() == "y") {
			
			GPUnum++;
		}
	}
	
	Job* Swork = new Job[Snum];//small job queue
	Job* Mwork = new Job[Mnum];//medium job queue
	Job* Lwork = new Job[Lnum];//large job queue
	Job* GPUwork = new Job[GPUnum];//job that need GPU
	
	Snum = 0;
	Mnum = 0;
	Lnum = 0;
	GPUnum = 0;
	for (int i = 0; i < num; i++) {
		//all short jobs
		if (works[i].getjobType() == "short"&&works[i].getuseGPU()=="n") {
			Swork[Snum] = works[i];
			Snum++;
		}
		//all medium jobs
		else if (works[i].getjobType() == "medium" && works[i].getuseGPU() == "n") {
			Mwork[Mnum] = works[i];
			Mnum++;
		}
		//all large jobs
		else if (works[i].getjobType() == "large" && works[i].getuseGPU() == "n") {
			Lwork[Lnum] = works[i];
			Lnum++;
		}
		else if (works[i].getuseGPU() == "y") {
			GPUwork[GPUnum] = works[i];
			GPUnum++;
		}
	}

	delete[]works;

	//calculate processer
	smallProcesser = machine.getcurrentProcesser() /10;
	mediumProcesser = machine.getcurrentProcesser() * 4/10;
	largeProcesser = machine.getcurrentProcesser() * 5/10;
	GPUProcesser = 8 * 2 * 16;

	


	//main method
	int Sorder = 0;
	int Morder = 0;
	int Lorder = 0;
	int GPUorder = 0;

	while (passNum<num-1) {
		//input GPU job to machine
		while ((GPUwork[GPUorder].getjobProcesser() )< GPUProcesser && GPUwork[GPUorder].getwaitingTime() <= 0&& GPUorder < GPUnum) {
			if (GPUwork[GPUorder].getuserType() == "IT") {

				if (IT.getGroupResource() >= GPUwork[GPUorder].getResource())
				{
					GPUProcesser = GPUProcesser - GPUwork[GPUorder].getjobProcesser();
					GPUwork[GPUorder].settimeStart(timecost);
					GPUworking = GPUworking + 1;
					gpuworking[GPUworking-1] = GPUwork[GPUorder];


					IT.setGroupResource(IT.getGroupResource() - GPUwork[GPUorder].getResource());
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
				if (IT.getGroupResource() >= GPUwork[GPUorder].getResource())
				{
					GPUProcesser = GPUProcesser - GPUwork[GPUorder].getjobProcesser();
					GPUwork[GPUorder].settimeStart(timecost);
					GPUworking = GPUworking + 1;
					gpuworking[GPUworking - 1] = GPUwork[GPUorder];


					Lr.setGroupResource(Lr.getGroupResource() - GPUwork[GPUorder].getResource());
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
				if (Mr.getGroupResource() >= GPUwork[GPUorder].getResource())
				{
					GPUProcesser = GPUProcesser - GPUwork[GPUorder].getjobProcesser();
					GPUwork[GPUorder].settimeStart(timecost);
					GPUworking = GPUworking + 1;
					gpuworking[GPUworking - 1] = GPUwork[GPUorder];


					Mr.setGroupResource(Mr.getGroupResource() - GPUwork[GPUorder].getResource());
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
				if (Sr.getGroupResource() >= GPUwork[GPUorder].getResource())
				{
					GPUProcesser = GPUProcesser - GPUwork[GPUorder].getjobProcesser();
					GPUwork[GPUorder].settimeStart(timecost);
					GPUworking = GPUworking + 1;
					gpuworking[GPUworking - 1] = GPUwork[GPUorder];


					Sr.setGroupResource(Sr.getGroupResource() - GPUwork[GPUorder].getResource());
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
				if (Ls.getGroupResource() >= GPUwork[GPUorder].getResource())
				{
					GPUProcesser = GPUProcesser - GPUwork[GPUorder].getjobProcesser();
					GPUwork[GPUorder].settimeStart(timecost);
					GPUworking = GPUworking + 1;
					gpuworking[GPUworking - 1] = GPUwork[GPUorder];


					Ls.setGroupResource(Ls.getGroupResource() - GPUwork[GPUorder].getResource());
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
				if (Ms.getGroupResource() >= GPUwork[GPUorder].getResource())
				{
					GPUProcesser = GPUProcesser - GPUwork[GPUorder].getjobProcesser();
					GPUwork[GPUorder].settimeStart(timecost);
					GPUworking = GPUworking + 1;
					gpuworking[GPUworking - 1] = GPUwork[GPUorder];


					Ms.setGroupResource(Ms.getGroupResource() - GPUwork[GPUorder].getResource());
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
				if (Ss.getGroupResource() >= GPUwork[GPUorder].getResource())
				{
					GPUProcesser = GPUProcesser - GPUwork[GPUorder].getjobProcesser();
					GPUwork[GPUorder].settimeStart(timecost);
					GPUworking = GPUworking + 1;
					gpuworking[GPUworking - 1] = GPUwork[GPUorder];


					Ss.setGroupResource(Ss.getGroupResource() - GPUwork[GPUorder].getResource());
					GPUorder = GPUorder + 1;
				}
				else {
					cout << "SS group have no resource" << endl;
					GPUorder = GPUorder + 1;
					passNum++;
				}
			}
		}

	
		//input short job to mechine
			while (Swork[Sorder].getjobProcesser() < smallProcesser&&Swork[Sorder].getwaitingTime()<=0&&Sorder<Snum) {
				if (Swork[Sorder].getuserType()=="IT") {

					if (IT.getGroupResource() >= Swork[Sorder].getResource()) 
					{
						smallProcesser = smallProcesser - Swork[Sorder].getjobProcesser();
						Swork[Sorder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Swork[Sorder];
						

						IT.setGroupResource(IT.getGroupResource() - Swork[Sorder].getResource());
						Sorder = Sorder + 1;
					}
					else {
						cout <<"IT group have no resource" << endl;
						Sorder = Sorder + 1;
						passNum++;
					}
				}
				else if (Swork[Sorder].getuserType() == "Lr") 
				{
					if (Lr.getGroupResource() >= Swork[Sorder].getResource()) {
						smallProcesser = smallProcesser - Swork[Sorder].getjobProcesser();
						Swork[Sorder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Swork[Sorder];
					

						Lr.setGroupResource(Lr.getGroupResource() - Swork[Sorder].getResource());
						Sorder = Sorder + 1;
					}
					else {
						cout << "Lr group have no resource" << endl;
						Sorder = Sorder + 1;
						passNum++;
					}
				}
				else if (Swork[Sorder].getuserType() == "Mr")
				{
					if (Mr.getGroupResource() >= Swork[Sorder].getResource()) {
						smallProcesser = smallProcesser - Swork[Sorder].getjobProcesser();
						Swork[Sorder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Swork[Sorder];
						

						Mr.setGroupResource(Mr.getGroupResource() - Swork[Sorder].getResource());
						Sorder = Sorder + 1;
					}
					else {
						cout << "Mr group have no resource" << endl;
						Sorder = Sorder + 1;
						passNum++;
					}
				}
				else if (Swork[Sorder].getuserType() == "Sr")
				{
					if (Sr.getGroupResource() >= Swork[Sorder].getResource()) 
					{
						smallProcesser = smallProcesser - Swork[Sorder].getjobProcesser();
						Swork[Sorder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Swork[Sorder];
						

						Sr.setGroupResource(Sr.getGroupResource() - Swork[Sorder].getResource());
						Sorder = Sorder + 1;
					}
					else {
						cout << "Sr group have no resource" << endl;
						Sorder = Sorder + 1;
						passNum++;
					}
				}
				else if (Swork[Sorder].getuserType() == "Ls")
				{
					if (Ls.getGroupResource() >= Swork[Sorder].getResource()) {
						smallProcesser = smallProcesser - Swork[Sorder].getjobProcesser();
						Swork[Sorder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Swork[Sorder];
						

						Ls.setGroupResource(Ls.getGroupResource() - Swork[Sorder].getResource());
						Sorder = Sorder + 1;
					}
					else {
						cout << "Ls group have no resource" << endl;
						Sorder = Sorder + 1;
						passNum++;
					}
				}
				else if (Swork[Sorder].getuserType() == "Ms")
				{
					if (Ms.getGroupResource() >= Swork[Sorder].getResource()) {
						smallProcesser = smallProcesser - Swork[Sorder].getjobProcesser();
						Swork[Sorder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Swork[Sorder];
						

						Ms.setGroupResource(Ms.getGroupResource() - Swork[Sorder].getResource());
						Sorder = Sorder + 1;
					}
					else {
						cout << "Ms group have no resource" << endl;
						Sorder = Sorder + 1;
						passNum++;
					}
				}
				else if (Swork[Sorder].getuserType() == "Ss")
				{
					if (Ss.getGroupResource() >= Swork[Sorder].getResource()) {
						smallProcesser = smallProcesser - Swork[Sorder].getjobProcesser();
						Swork[Sorder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Swork[Sorder];
						

						Ss.setGroupResource(Ss.getGroupResource() - Swork[Sorder].getResource());
						Sorder = Sorder + 1;
					}
					else {
						cout << "Ss group have no resource" << endl;
						Sorder = Sorder + 1;
						passNum++;
					}
				}
			}
		


		//input merdium jobs to mechine
			while (Mwork[Morder].getjobProcesser() < mediumProcesser && Mwork[Morder].getwaitingTime() <= 0&&Morder<Mnum) {
				if (Mwork[Morder].getuserType() == "IT") {
					if (IT.getGroupResource() >= Mwork[Morder].getResource()) {
						mediumProcesser = mediumProcesser - Mwork[Morder].getjobProcesser();
						Mwork[Morder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Mwork[Morder];
						

						IT.setGroupResource(IT.getGroupResource() - Mwork[Morder].getResource());
						Morder = Morder + 1;
					}
					else {
						cout << "IT group have no resource" << endl;
						Morder = Morder + 1;
						passNum++;
					}
				}
				else if (Mwork[Morder].getuserType() == "Lr") 
				{
					if (Lr.getGroupResource() >= Mwork[Morder].getResource()) {
						mediumProcesser = mediumProcesser - Mwork[Morder].getjobProcesser();
						Mwork[Morder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Mwork[Morder];
						

						Lr.setGroupResource(Lr.getGroupResource() - Mwork[Morder].getResource());
						Morder = Morder + 1;
					}
					else {
						cout << "Lr group have no resource" << endl;
						Morder = Morder + 1;
						passNum++;
					}
				}
				else if (Mwork[Morder].getuserType() == "Mr") 
				{
					if (Mr.getGroupResource() >= Mwork[Morder].getResource()) {
						mediumProcesser = mediumProcesser - Mwork[Morder].getjobProcesser();
						Mwork[Morder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Mwork[Morder];
					

						Mr.setGroupResource(Mr.getGroupResource() - Mwork[Morder].getResource());
						Morder = Morder + 1;
					}
					else {
						cout << "Mr group have no resource" << endl;
						Morder = Morder + 1;
						passNum++;
					}
				
				}
				else if (Mwork[Morder].getuserType() == "Sr") {

					if (Sr.getGroupResource() >= Mwork[Morder].getResource()) {
						mediumProcesser = mediumProcesser - Mwork[Morder].getjobProcesser();
						Mwork[Morder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Mwork[Morder];
					

						Sr.setGroupResource(Sr.getGroupResource() - Mwork[Morder].getResource());
						Morder = Morder + 1;
					}
					else {
						cout << "Sr group have no resource" << endl;
						Morder = Morder + 1;
						passNum++;
					}
				}
				else if (Mwork[Morder].getuserType() == "Ls") 
				{
					if (Ls.getGroupResource() >= Mwork[Morder].getResource()) {
						mediumProcesser = mediumProcesser - Mwork[Morder].getjobProcesser();
						Mwork[Morder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Mwork[Morder];
						

						Ls.setGroupResource(Ls.getGroupResource() - Mwork[Morder].getResource());
						Morder = Morder + 1;
					}
					else {
						cout << "Ls group have no resource" << endl;
						Morder = Morder + 1;
						passNum++;
					}
				}
				else if (Mwork[Morder].getuserType() == "Ms") 
				{
					if (Ms.getGroupResource() >= Mwork[Morder].getResource()) {
						mediumProcesser = mediumProcesser - Mwork[Morder].getjobProcesser();
						Mwork[Morder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Mwork[Morder];
					

						Ms.setGroupResource(Ms.getGroupResource() - Mwork[Morder].getResource());
						Morder = Morder + 1;
					}
					else {
						cout << "Ms group have no resource" << endl;
						Morder = Morder + 1;
						passNum++;
					}
				
				}
				else if (Mwork[Morder].getuserType() == "Ss") {
					if (Ss.getGroupResource() >= Mwork[Morder].getResource()) {
						mediumProcesser = mediumProcesser - Mwork[Morder].getjobProcesser();
						Mwork[Morder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Mwork[Morder];
					

						Ss.setGroupResource(Ss.getGroupResource() - Mwork[Morder].getResource());
						Morder = Morder + 1;
					}
					else {
						cout << "Ss group have no resource" << endl;
						Morder = Morder + 1;
						passNum++;
					}
				}
				

			}
		
		//input large jobs to mechine
			while (Lwork[Lorder].getjobProcesser() < largeProcesser&&Lwork[Lorder].getwaitingTime()<=0&&Lorder<Lnum) {
				if (Lwork[Lorder].getuserType() == "IT") {
					if (IT.getGroupResource() >= Lwork[Lorder].getResource()) {
						largeProcesser = largeProcesser - Lwork[Lorder].getjobProcesser();
						Lwork[Lorder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Lwork[Lorder];

						IT.setGroupResource(IT.getGroupResource() - Lwork[Lorder].getResource());
						Lorder = Lorder + 1;
					}
					else {
						cout << "IT group have no resource" << endl;
						Lorder = Lorder + 1;
						passNum++;
					}
				}
				else if (Lwork[Lorder].getuserType() == "Lr") {
					if (Lr.getGroupResource() >= Lwork[Lorder].getResource()) {
						largeProcesser = largeProcesser - Lwork[Lorder].getjobProcesser();
						Lwork[Lorder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Lwork[Lorder];
						Lr.setGroupResource(Lr.getGroupResource() - Lwork[Lorder].getResource());
						Lorder = Lorder + 1;
					}
					else {
						cout << "Lr group have no resource" << endl;
						Lorder = Lorder + 1;
						passNum++;
					}
				}
				else if (Lwork[Lorder].getuserType() == "Mr") {
					if (Mr.getGroupResource() >= Lwork[Lorder].getResource()) {
						largeProcesser = largeProcesser - Lwork[Lorder].getjobProcesser();
						Lwork[Lorder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Lwork[Lorder];
						Mr.setGroupResource(Mr.getGroupResource() - Lwork[Lorder].getResource());
						Lorder = Lorder + 1;
					}
					else {
						cout << "Mr group have no resource" << endl;
						Lorder = Lorder + 1;
						passNum++;
					}
				}
				else if (Lwork[Lorder].getuserType() == "Sr")
				{
					if (Sr.getGroupResource() >= Lwork[Lorder].getResource()) {
						largeProcesser = largeProcesser - Lwork[Lorder].getjobProcesser();
						Lwork[Lorder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Lwork[Lorder];
						Sr.setGroupResource(Sr.getGroupResource() - Lwork[Lorder].getResource());
						Lorder = Lorder + 1;
					}
					else {
						cout << "Sr group have no resource" << endl;
						Lorder = Lorder + 1;
						passNum++;
					}
				}
				else if (Lwork[Lorder].getuserType() == "Ls")
				{
					if (Ls.getGroupResource() >= Lwork[Lorder].getResource()) {
						largeProcesser = largeProcesser - Lwork[Lorder].getjobProcesser();
						Lwork[Lorder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Lwork[Lorder];
						Ls.setGroupResource(Ls.getGroupResource() - Lwork[Lorder].getResource());
						Lorder = Lorder + 1;
					}
					else {
						cout << "Ls group have no resource" << endl;
						Lorder = Lorder + 1;
						passNum++;
					}
				}
				else if (Lwork[Lorder].getuserType() == "Ms")
				{
					if (Ms.getGroupResource() >= Lwork[Lorder].getResource()) {
						largeProcesser = largeProcesser - Lwork[Lorder].getjobProcesser();
						Lwork[Lorder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Lwork[Lorder];
						Ms.setGroupResource(Ms.getGroupResource() - Lwork[Lorder].getResource());
						Lorder = Lorder + 1;
					}
					else {
						cout << "Ms group have no resource" << endl;
						Lorder = Lorder + 1;
						passNum++;
					}
				
				}
				else if (Lwork[Lorder].getuserType() == "Ss") {
					if (Ss.getGroupResource() >= Lwork[Lorder].getResource()) {
						largeProcesser = largeProcesser - Lwork[Lorder].getjobProcesser();
						Lwork[Lorder].settimeStart(timecost);
						workingjob = workingjob + 1;
						working[workingjob - 1] = Lwork[Lorder];
						Ss.setGroupResource(Ss.getGroupResource() - Lwork[Lorder].getResource());
						Lorder = Lorder + 1;
					}
					else {
						cout << "Ss group have no resource" << endl;
						Lorder = Lorder + 1;
						passNum++;
					}
				}
				
				
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
						passNum++;
					
				}
				else if (working[i].getjobType() == "medium") {
					
						mediumProcesser = mediumProcesser + working[i].getjobProcesser();
						working[i].settimeCurrent(-1);
						working[i].settimeFinish(timecost);
						Finish[finishNum] = working[i];
						finishNum = finishNum + 1;
						passNum++;
				}
				else if (working[i].getjobType() == "large") {
					
						largeProcesser = largeProcesser + working[i].getjobProcesser();
						working[i].settimeCurrent(-1);
						working[i].settimeFinish(timecost);
						Finish[finishNum] = working[i];
						finishNum = finishNum + 1;
						passNum++;
					
				}
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
		for (int i = 0; i < GPUnum; i++) {
			double time;
			if (GPUwork[i].getwaitingTime() == 0) {
				GPUwork[i].settimeGeneration(timecost);
			}
			time = GPUwork[i].getwaitingTime() - 1;
			GPUwork[i].setwaitingTime(time);
		}
		
		if (timecost < 6240) {
			timecost = timecost + 1;
		}
		else {
			break;
		}
		

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

	//calculate average turnaround time;
	double  aveAround = 0;
	double turnaround = 0;
	for (int i = 0; i < finishNum; i++) {
		turnaround =turnaround + (Finish[i].gettimeFinish() - Finish[i].gettimeGeneration());
	}
	aveAround = turnaround / jobtime;



	//output
	ofstream oFile;
	oFile.open("ouput.csv");


	//cout << "the number of the jobs: " << finishNum << endl;
	oFile << "the number of the jobs: " <<","<< finishNum << endl;

	Snum = 0;
	Mnum = 0;
	Lnum = 0;
	GPUnum = 0;
	for (int i = 0; i <= finishNum; i++) {
		
		if (Finish[i].getjobType() == "short" && Finish[i].getuseGPU() == "n") {
			
			Snum++;
		}
		
		else if (Finish[i].getjobType() == "medium" && Finish[i].getuseGPU() == "n") {
			
			Mnum++;
		}
		
		else if (Finish[i].getjobType() == "large" && Finish[i].getuseGPU() == "n") {
			
			Lnum++;
		}
		else if (Finish[i].getuseGPU() == "y") {
			
			GPUnum++;
		}
	}
	//cout << "the number of finished short job:" << Snum << endl;
	//cout << "the number of finished medium job:" << Mnum << endl;
	//cout << "the number of finished large job:" << Lnum << endl;
	//cout << "the number of finished GPU job:" << GPUnum << endl;

	oFile << "the number of finished short job:" << "," << Snum << endl;
	oFile << "the number of finished medium job:" << "," << Mnum << endl;
	oFile << "the number of finished large job:" << "," << Lnum << endl;
	oFile << "the number of finished GPU job:" << "," << GPUnum << endl;


	for (int i = 0; i < finishNum; i++) {
		//cout <<"job id:"<< Finish[i].getjobID() << "job type"<<Finish[i].getjobType()<< endl;
		//cout << Finish[i].gettimeGeneration() << endl;
	}
	
	//cout << "average waiting time :" << aveWaiting << endl;
	oFile << "average waiting time :" << "," << aveWaiting << endl;
	//cout << "average job time: " << avejobtime << endl;
	oFile << "average job time: " << "," << avejobtime << endl;
	//cout << "average turnaround time: " << aveAround << endl;
	oFile<<"average turnaround time: " <<","<< aveAround << endl;
	//cout << "timecost : " << timecost << endl;
	oFile<<"timecost : "<<","<< timecost << endl;
	
	//cout << "earn money:" << finishNum * avejobtime * 2 * 2 << endl;
	oFile<<"earn money:"<<","<< finishNum * avejobtime * 2 * 2 << endl;
	//cout << "cost money:" << timecost * 120 * 1 << endl;
	oFile << "cost money:" <<","<< timecost * 120 * 1 << endl;

	if ((finishNum * avejobtime * 2 * 2) > (timecost * 120 * 1)) {
		//cout << "profit" << endl;
		oFile << "profit" << endl;
	}
	else {
		//cout << "loss" << endl;
		oFile << "loss" << endl;
	}

	oFile.close();
}