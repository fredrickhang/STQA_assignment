#include<stdio.h>
#include<iostream>
#include<string>


class job {

private:
	int jobID;
	int userID;
	char jobType;
	double jobTime;
	double timeGeneration;
	double timeStart;
	double timeFinish;
	double timeCurrent;
public:
	void setjobID(int jobid);
	int getjobID();

	void setuserID(int userid);
	int getuserID();

	void setjobType(char type);
	char getjobType();

	void settimeGeneration(double timegeneration);
	double gettimeGeneration();

	void settimeStart(double timestart);
	double gettimeStart();

	void settimeFinish(double timefinish);
	double gettimeFinish();

	void settimeCurrent(double timecurrent);
	double gettimeCurrent();

	void setjobTime(double jobtime);
	double getjobTime();
};