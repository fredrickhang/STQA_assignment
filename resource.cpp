#include"resource.h"

void Resource::setUserType(char userType){
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

void Resource::setGroupType(char groupType)
{
	this->groupType = groupType;
}

char Resource::getGroupType()
{
	return this->groupType;
}
