#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<char, string> record;
		string::iterator patIter = pattern.begin();
		string::iterator strIter = str.begin();

		while (patIter != pattern.end() && strIter != str.end()) {
			/*从字符串中将下一个子字符串分离出来*/
			string newStr;
			while ( strIter != str.end() && *strIter != ' ') {
				newStr += *strIter;
				strIter++;
			}
			/*查询该键值是否符合模式*/
			if (record.find(*patIter) == record.end()) {/*若查询不到此键*/
				/*若其它键对应的值为此子字符串，则不符合模式*/
				for (unordered_map<char, string>::iterator iter = record.begin(); iter != record.end(); iter++) {
					if (iter->second == newStr)
						return false;
				}
				/*若不存在此键-值对，则将此键-值对加入字典中*/
				record[*patIter] = newStr;

			}
			else {
				/*如果查询到此键，则查看此值是否符合模式*/
				if (record[*patIter] != newStr)
					return false;
			}

			patIter++;
			if (strIter != str.end())
				strIter++;
		}

		if (patIter != pattern.end() || strIter != str.end())
			return false;

		return true;
	}
};

int main() {
	Solution solution;
	string pattern = "abba";
	string str = "dog cat cat dog";
	if (solution.wordPattern(pattern, str))
		cout << "符合单词模式" << endl;
	else
		cout << "不符合单词模式" << endl;

	system("pause");
	return 0;
}