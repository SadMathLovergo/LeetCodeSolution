#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> record;

		/*���ÿ���ַ����ĸ�����ĸ������������ַ���������ԭ�ַ����������ַ�������record�ж�Ӧ��vector<string>��*/
		for (vector<string>::iterator iter = strs.begin();
			iter != strs.end(); iter++) {
			string SortedString = getSortedString(*iter);

			record[SortedString].push_back(*iter);
		}

		vector<vector<string>> result;
		/*��map��ÿ������õ��ַ�����Ӧ��vector<string>ѹ��result��*/
		for (map<string, vector<string>>::iterator iter = record.begin();
			iter != record.end(); iter++) {
			result.push_back(iter->second);
		}

		return result;
	}

private:
	/*���������ĸ�������е��ַ���*/
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