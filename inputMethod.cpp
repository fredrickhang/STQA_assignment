#include <queue>
#include"job.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include"stringSplitTools.cpp"


/*queue<Job>*/ void inputMethod() {
	ifstream inFile("inputdata.csv", ios::in);
	if (!inFile) {
		cout << "can not find file, please create a file named inputdata.csv";
	
	}
	vector<string> line;
	vector<vector<string>> joblist;
	vector<string> res1;
	int i = 0;
	string line1;
	string field;
	while (getline(inFile, line1)) {
		istringstream sin(line1);
		getline(sin, field, ',');
		res1 = split(field,",");
		for (vector<string>::iterator it = res1.begin();
			it != res1.end(); ++it) {
			line.push_back(*it);
			
			cout << *it << endl;
		}
		joblist.push_back(line);

	
	}
	


	 

}