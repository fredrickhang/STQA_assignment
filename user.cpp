#include "user.h"

	 void User::setUserID(int userID) {
		this->userID = userID;
	}
	int User::getUserID() {
	return this->userID;
	}
	void User::setResource(double resource) {
		this->resource = resource;
	}
	double User::getResource() {
		return this->resource;
	}
	void User::setTimeCost(double timeCost) {
		this->timeCost = timeCost;
	}
	double User::getTimeCost() {
		return this->timeCost;
	}
	void User::setPriceCost(double priceCost) {
		this->priceCost = priceCost;
	}
	double User::getPriceCost() {
		return this->priceCost;
	}
	void User::setJobNumber(int jobNumber) {
		this->jobNumber = jobNumber;
	}
	int User::getJobNumber() {
		return this->jobNumber;
	}
	void User::setNodeNumber(int nodeNumber) {
		this->nodeNumber = nodeNumber;
	}
	int User::getNodeNumber() {
		return this->nodeNumber;
	}
	void User::setNodeHours(double nodeHours) {
		this->nodeHours = nodeHours;
	}
	double User::getNodeHours() {
		return this->nodeHours;
	}

