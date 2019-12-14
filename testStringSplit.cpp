#include <string>
#include <vector>
#include "stringSplitTools.h"
#include <iostream>
using namespace std;
void testStringSplit() {
	vector<string> b;
	string a = "test1,test2,test3";
	b.push_back(a);
	b = split(a, ",");
	for (int i = 0; i < b.size(); i++) {
		cout << b[i]<<endl;
	}




}