#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
	bool isPalindromic(string& s, int startIndex, int endIndex) {
		int i = startIndex;
		int j = endIndex;
		while (i < j) {
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}

	void partition(string& s, int charIndex, vector<string>& strVec, vector<vector<string>>& resVec) {
		if (charIndex == s.size()) {
			resVec.push_back(strVec);
			return;
		}
		for (int i = charIndex; i < s.size(); i++) {
			if (isPalindromic(s, charIndex, i)) {
				strVec.push_back(s.substr(charIndex, i - charIndex + 1));
				partition(s, i + 1, strVec, resVec);
				strVec.pop_back();
			}
		}
	}

public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> resVec;
		if (s.empty())
			return resVec;
		vector<string> strVec;
		partition(s, 0, strVec, resVec);
		return resVec;
	}
};