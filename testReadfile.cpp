#include<ostream>
#include<fstream>
#include"testReadfile.h"
#include <iostream>
#include<vector>
#include<cstdlib>
#include<sstream>
using namespace std;
void testReadfile() {
	ifstream inFile("datainput.csv", ios::in);
	if (!inFile) {
		cout << "can not find file, please create a file named inputdata.csv";

	}
	vector<string> res1;
	int i = 0;
	string line1;
	string field;
	while (getline(inFile, line1)) {
		string field;
		istringstream sin(line1);
		while (getline(sin, field)) {

			res1.push_back(field);
		}
		if (i > 50) {
			break;
		}
		//cout << res1[i]<< endl;
		i++;
	}
	for (int k = 0; k < res1.size() - 1; k++) {
		string re = res1[k + 1];
		cout << re << endl;
	
	}
}