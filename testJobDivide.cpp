#include<iostream>
#include<stdio.h>
#include<string>
#include"center.h"
#include<queue>
#include"job.h"
#include"testJobDivide.h"

using namespace std;

void divideJob(queue<Job> joblist, Center machine) {
	int num;
	num = joblist.size();
	Job* works = new Job[num];

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
		if (works[i].getjobType() == "short" && works[i].getuseGPU() == "n") {
			Swork[Snum] = works[i];
			cout <<"short work id: "<< Swork[Snum].getjobID() << "  work type:"<<Swork[Snum].getjobType()<<endl;
			Snum++;
		}
		//all medium jobs
		else if (works[i].getjobType() == "medium" && works[i].getuseGPU() == "n") {
			Mwork[Mnum] = works[i];
			cout << "medium work id: " << Mwork[Mnum].getjobID() << "  work type:" << Mwork[Mnum].getjobType() << endl;
			Mnum++;
		}
		//all large jobs
		else if (works[i].getjobType() == "large" && works[i].getuseGPU() == "n") {
			Lwork[Lnum] = works[i];
			cout << "large work id: " << Lwork[Lnum].getjobID() << "  work type:" << Lwork[Lnum].getjobType() << endl;
			Lnum++;
		}
		else if (works[i].getuseGPU() == "y") {
			GPUwork[GPUnum] = works[i];
			cout << "gpu work id: " << GPUwork[GPUnum].getjobID() << "  gpu use:" << GPUwork[GPUnum].getuseGPU() << endl;
			GPUnum++;
		}
	}


}