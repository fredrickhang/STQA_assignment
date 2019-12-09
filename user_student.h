#include "user.h"

class user_student : public user {
private:
	char groupType;
public:
	void setGroupType(char groupType);
	int getGroupType();

};