#include "user.h"

	 void user::setUserID(int userID) {
		this->userID = userID;
	}
	int user::getUserID() {
	return this->userID;
	}
	void user::setResource(double resource) {
		this->resource = resource;
	}
	double user::getResource() {
		return this->resource;
	}
	void user::setTimeCost(double timeCost) {
		this->timeCost = timeCost;
	}
	double user::getTimeCost() {
		return this->timeCost;
	}
	void user::setPriceCost(double priceCost) {
		this->priceCost = priceCost;
	}
	double user::getPriceCost() {
		return this->priceCost;
	}
	void user::setJobNumber(int jobNumber) {
		this->jobNumber = jobNumber;
	}
	int user::getJobNumber() {
		return this->jobNumber;
	}
	void user::setNodeNumber(int nodeNumber) {
		this->nodeNumber = nodeNumber;
	}
	int user::getNodeNumber() {
		return this->nodeNumber;
	}
	void user::setNodeHours(double nodeHours) {
		this->nodeHours = nodeHours;
	}
	double user::getNodeHours() {
		return this->nodeHours;
	}

