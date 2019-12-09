#include "center.h"

void center::setJobNumber(int jobNumber)
{
	this->jobNumber = jobNumber;
}

int center::getJobNumber()
{
	return this->jobNumber;
}

void center::setJobHours(double jobHours)
{
	this->jobHours = jobHours;
}

double center::getJobHours()
{
	return this->jobHours;
}

void center::setAverageWaitTime(double averageWaitTime)
{
	this->averageWaitTime = averageWaitTime;
}

double center::getAverageWaitTime()
{
	return this->averageWaitTime;
}

void center::setAverageTime(double averageTime)
{
	this->averageTime = averageTime;
}

double center::getAverageTime()
{
	return this->averageTime;
}

void center::setTimeCost(double timeCost)
{
	this->timeCost = timeCost;
}

double center::getTimeCost()
{
	return timeCost;
}

void center::setProfit(double profit)
{
	this->profit = profit;
}

double center::getProfit()
{
	return this->profit;
}

void center::setJobTimeCost(double jobTimeCost)
{
	this->jobTimeCost = jobTimeCost;
}

double center::getJobTimeCost()
{
	return this->jobTimeCost;
}
