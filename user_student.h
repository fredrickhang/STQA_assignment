#include "user.h"

class User_student : public User {
private:
	char groupType;
public:
	void setGroupType(char groupType);
	int getGroupType();

};