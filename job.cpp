#include<stdio.h>
#include<iostream>
#include<string>
#include "job.h"

void Job::setjobID(int jobid) {
	this->jobID = jobid;
}

int Job::getjobID() {
	return jobID;
}

void Job::setjobProcesser(int jobprocesser)
{
	this->jobProcesser = jobprocesser;
}

int Job::getjobProcesser()
{
	return jobProcesser;
}

void Job::setuserType(int usertype)
{
	this->userType = usertype;
}

int Job::getuserType()
{
	return userType;
}

void Job::setjobType(char type) {
	this->jobType = type;
}

char Job::getjobType() {
	return jobType;
}

void Job::setuserID(int userid) {
	this->userID = userid;
}

int Job::getuserID() {
	return userID;
}

void Job::settimeCurrent(double timecurrent) {
	this->timeCurrent = timecurrent;
}

double Job::gettimeCurrent() {
	return timeCurrent;
}

void Job::settimeFinish(double timefinish) {
	this->timeFinish = timefinish;
}
double Job::gettimeFinish() {
	return timeFinish;
}

void Job::settimeGeneration(double timegeneration) {
	this->timeGeneration = timegeneration;
}

double Job::gettimeGeneration() {
	return timeGeneration;
}

void Job::settimeStart(double timestart) {
	this->timeStart = timestart;
}

double Job::gettimeStart() {
	return timeStart;
}

void Job::setjobTime(double jobtime) {
	this->jobTime = jobtime;
}
double Job::getjobTime() {
	return jobTime;
}

void Job::setwaitingTime(double waitingtime)
{
	this->waitingTime = waitingtime;
}

double Job::getwaitingTime()
{
	return waitingTime;
}

void Job::setuseGPU(bool usegpu)
{
	this->useGPU = usegpu;
}

bool Job::getuseGPU()
{
	return useGPU;
}
