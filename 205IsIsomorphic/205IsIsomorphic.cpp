#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		string::iterator sIter = s.begin();
		string::iterator tIter = t.begin();
		unordered_map<char, char> record;
		while (sIter != s.end()) {
			/*如果表中不能找到此键*/
			if (record.find(*sIter) == record.end()) {
				/*查看此值在其它键中是否已经存在*/
				for (unordered_map<char, char>::iterator iter = record.begin(); 
					iter != record.end(); iter++) {
					/*若此值在其它键中存在，则返回false*/
					if (iter->second == *tIter)
						return false;
				}
				/*若不存在，则新建此键值对*/
				record[*sIter] = *tIter;
			}
			/*如果能找到此键*/
			else
			{
				if (record[*sIter] != *tIter)
					return false;
			}

			sIter++;
			tIter++;
		}
		return true;
	}
};