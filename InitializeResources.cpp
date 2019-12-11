#include "InitializeResources.h"
#include"resource.h"
void initializeResources(Resource IT, Resource Lr, Resource Mr, Resource Sr, Resource Ls, Resource Ms, Resource Ss) {
	IT.setUserType("IT");
	IT.setGroupResource(2000);
	Lr.setUserType("Lr");
	Lr.setGroupResource(1000);
	Mr.setUserType("Mr");
	Mr.setGroupResource(500);
	Sr.setUserType("Sr");
	Sr.setGroupResource(400);
	Ls.setUserType("Ls");
	Ls.setGroupResource(500);
	Ms.setUserType("Ms");
	Ms.setGroupResource(300);
	Ss.setUserType("Ss");
	Sr.setGroupResource(200);

}