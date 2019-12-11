#include "InitializeResources.h"
#include<vector>
vector<Resource> initializeResources(Resource IT, Resource Lr, Resource Mr, Resource Sr, Resource Ls, Resource Ms, Resource Ss) {
	IT.setUserType("IT");
	IT.setGroupResource(2000.0);
	Lr.setUserType("Lr");
	Lr.setGroupResource(1000.0);
	Mr.setUserType("Mr");
	Mr.setGroupResource(500.0);
	Sr.setUserType("Sr");
	Sr.setGroupResource(400.0);
	Ls.setUserType("Ls");
	Ls.setGroupResource(500.0);
	Ms.setUserType("Ms");
	Ms.setGroupResource(300.0);
	Ss.setUserType("Ss");
	Sr.setGroupResource(200.0);
	vector<Resource> resourceList;
	resourceList.push_back(IT);
	resourceList.push_back(Lr);
	resourceList.push_back(Mr);
	resourceList.push_back(Sr);
	resourceList.push_back(Ls);
	resourceList.push_back(Ms);
	resourceList.push_back(Ss);
	return resourceList;
}