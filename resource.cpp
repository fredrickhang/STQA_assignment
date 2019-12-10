#include"resource.h"

void Resource::setUserType(char userType){
	this->userType = userType;
}

void Resource::setUserType(string userType)
{
	this->userType = userType;
}

char Resource::getUserType()
{
	return this->userType;
}

void Resource::setGroupResource(double groupResource)
{
	this->groupResource = groupResource;
}

double Resource::getGroupResource()
{
	return this->groupResource;
}

void Resource::setGroupType(string groupType)
{
	this->groupType = groupType;
}

void Resource::setGroupType(string groupType)
{
	this->groupType = groupType;
}

string Resource::getGroupType()
{
	return this->groupType;
}
