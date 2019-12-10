#include<stdio.h>
#include<iostream>
#include<string>
#include "job.h"


void Job::setjobID(int jobid) {
	this->jobID = jobid;
}

int Job::getjobID() {
	return this->jobID;
}

void Job::setjobProcesser(int jobprocesser)
{
	this->jobProcesser = jobprocesser;
}

int Job::getjobProcesser()
{
	return this->jobProcesser;
}

void Job::setuserType(string usertype)
{
	this->userType = usertype;
}


string Job::getuserType()
{
	return this->userType;
}

void Job::setjobType(string type) {
	this->jobType = type;
}



string Job::getjobType() {
	return this->jobType;
}


void Job::settimeCurrent(double timecurrent) {
	this->timeCurrent = timecurrent;
}

double Job::gettimeCurrent() {
	return this->timeCurrent;
}

void Job::settimeFinish(double timefinish) {
	this->timeFinish = timefinish;
}
double Job::gettimeFinish() {
	return this->timeFinish;
}

void Job::settimeGeneration(double timegeneration) {
	this->timeGeneration = timegeneration;
}

double Job::gettimeGeneration() {
	return this->timeGeneration;
}

void Job::settimeStart(double timestart) {
	this->timeStart = timestart;
}

double Job::gettimeStart() {
	return this->timeStart;
}

void Job::setjobTime(double jobtime) {
	this->jobTime = jobtime;
}
double Job::getjobTime() {
	return this->jobTime;
}

void Job::setwaitingTime(double waitingtime)
{
	this->waitingTime = waitingtime;
}

double Job::getwaitingTime()
{
	return this->waitingTime;
}


void Job::setuseGPU(string usegpu)
{
	this->useGPU = usegpu;
}

string Job::getuseGPU()
{
	return this->useGPU;
}
