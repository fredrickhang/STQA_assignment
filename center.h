class Center {
private:
	int jobNumber;
	double jobHours;
	double averageWaitTime;
	double averageTime;
	double profit;
	double jobTimeCost;
	double timeCost; //sum the time when the center begin

public:
	void setJobNumber(int jobNumber);
	int getJobNumber();
	void setJobHours(double jobHours);
	double getJobHours();
	void setAverageWaitTime(double averageWaitTime);
	double getAverageWaitTime();
	void setAverageTime(double averageTime);
	double getAverageTime();
	void setTimeCost(double timeCost);
	double getTimeCost();
	void setProfit(double profit);
	double getProfit();
	void setJobTimeCost(double jobTimeCost);
	double getJobTimeCost();


};