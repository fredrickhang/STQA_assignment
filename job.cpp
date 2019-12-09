#include<stdio.h>
#include<iostream>
#include<string>
#include "job.h"

void job::setjobID(int jobid) {
	this->jobID = jobid;
}

int job::getjobID() {
	return jobID;
}

void job::getjobType(char type) {
	this->getjobType = type;
}

char job::getjobType() {
	return jobType;
}

void job::setuserID(int userid) {
	this->userID = userid;
}

int job::getuserID() {
	return userID;
}

void job::settimeCurrent(double timecurrent) {
	this->timeCurrent = timecurrent;
}

double job::gettimeCurrent() {
	return timeCurrent;
}

void job::settimeFinish(double timefinish) {
	this->timeFinish = timefinish;
}
double job::gettimeFinish() {
	return timeFinish;
}

void job::settimeGeneration(double timegeneration) {
	this->timeGeneration = timegeneration;
}

double job::gettimeGeneration() {
	return timeGeneration;
}

void job::settimeStart(double timestart) {
	this->timeStart = timestart;
}

double job::gettimeStart() {
	return timeStart;
}