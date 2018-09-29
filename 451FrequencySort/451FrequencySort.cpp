#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	string frequencySort(string s) {
		map<char, int> record;
		string resultString;

		for (string::iterator iter = s.begin(); 
			iter != s.end(); iter++) {
			record[*iter]++;
		}

		int maxNum = 0;
		for (map<char, int>::iterator iter = record.begin(); 
			iter != record.end(); iter++) {
			if (iter->second > maxNum)
				maxNum = iter->second;
		}

		int curNum = maxNum;
		while (curNum != 0) {
			for (map<char, int>::iterator iter = record.begin();
				iter != record.end(); iter++) {
				if (iter->second == curNum) {
					for (int i = 0; i < curNum; i++)
						resultString += iter->first;
				}
			}
			curNum--;
		}

		return resultString;
	}
};