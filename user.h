class User {
private:
	int userID;
	double resource;
	double timeCost;
	double priceCost;
	int jobNumber;
	int nodeNumber;
	double nodeHours;


public:
	void setUserID(int userID);
	int getUserID();
	void setResource(double resuorce);
	double getResource();
	void setTimeCost(double timeCost);
	double getTimeCost();
	void setPriceCost(double priceCost);
	double getPriceCost();
	void setJobNumber(int jobNumber);
	int getJobNumber();
	void setNodeNumber(int nodeNumber);
	int getNodeNumber();
	void setNodeHours(double nodeHours);
	double getNodeHours();

};
