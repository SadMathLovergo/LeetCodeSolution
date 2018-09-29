#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> record;

		for (string::iterator iter = s.begin(); 
			iter != s.end(); iter++) {
			record[*iter]++;
		}

		for (string::iterator iter = t.begin(); 
			iter != t.end(); iter++) {
			record[*iter]--;
		}

		for (unordered_map<char, int>::iterator iter = record.begin();
			iter != record.end(); iter++) {
			if (iter->second != 0)
				return false;
		}

		return true;
	}
};