#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> record;

		/*求出每个字符串的根据字母升序排序的新字符串，并将原字符串根据新字符串放入record中对应的vector<string>里*/
		for (vector<string>::iterator iter = strs.begin();
			iter != strs.end(); iter++) {
			string SortedString = getSortedString(*iter);

			record[SortedString].push_back(*iter);
		}

		vector<vector<string>> result;
		/*将map中每个排序好的字符串对应的vector<string>压入result中*/
		for (map<string, vector<string>>::iterator iter = record.begin();
			iter != record.end(); iter++) {
			result.push_back(iter->second);
		}

		return result;
	}

private:
	/*求出按照字母升序排列的字符串*/
	string getSortedString(string& str) {
		map<char, int> record;
		for (string::iterator iter = str.begin();
			iter != str.end(); iter++) {
			record[*iter]++;
		}
		string res;
		char base = 'a';
		while (record.lower_bound(base) != record.end()) {
			map<char, int>::iterator newIter = record.lower_bound(base);
			char newChar = newIter->first;
			int count = newIter->second;
			for (int i = 0; i < count; i++)
				res += newChar;
			base = ++newChar;
		}
		return res;
	}
};