#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		vector<int> indexRecord;
		int i = 0;

		for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
			if (*iter == 'a' || 
				*iter == 'e' || 
				*iter == 'i' || 
				*iter == 'o' || 
				*iter == 'u' || 
				*iter == 'A' || 
				*iter == 'E' || 
				*iter == 'I' || 
				*iter == 'O' || 
				*iter == 'U') {
				indexRecord.push_back(i);
			}
			i++;
		}

		int indexL = 0;
		int indexR = indexRecord.size() - 1;
		while (indexL < indexR) {
			swap(s[indexRecord[indexL]], s[indexRecord[indexR]]);
			indexL++;
			indexR--;
		}

		return s;
	}
};