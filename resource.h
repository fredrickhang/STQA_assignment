#include<string>
using namespace std;

class Resource {
private:
	string userType;
	double groupResource;
	string groupType;
	
public:
	void setUserType(string userType);
	string getUserType();
	void setGroupResource(double groupResource);
	double getGroupResource();
	void setGroupType(string groupType);
	string getGroupType();


};
