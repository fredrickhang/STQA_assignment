#include "stringSplitTools.h"


vector<string>  split(const string& str, const string& delim) {
	vector<string> res;
	if ("" == str) return  res;

	string strs = str + delim;
	size_t pos;
	size_t size = strs.size();

	for (int k = 0; k < size; ++k) {
		pos = strs.find(delim, k);
		if (pos < size) {
			string s = strs.substr(k, pos - k);
			res.push_back(s);
			k = pos + delim.size() - 1;
		}

	}
	return res;
}