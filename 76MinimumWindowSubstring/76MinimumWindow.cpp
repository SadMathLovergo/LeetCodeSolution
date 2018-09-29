#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		int sFreq[256] = { 0 };
		int tFreq[256] = { 0 };
		int indexL = 0;		/*判断[indexL,indexR]区间的字符串*/
		int indexR = t.size() - 1;
		vector<int> tChar;
		bool hasString = true;	/*当前区间的字符串是否包含所有字母*/
		string res;

		for (int i = 0; i < t.size(); i++) {
			tFreq[t[i]]++;
		}

		for (int i = 0; i < t.size(); i++) {
			sFreq[s[i]]++;
		}
		/*储存t中拥有的字符，在后面的检测中，只需要遍历t中拥有的字符的数量，不需要遍历整个tFreq数组和sFreq，缩短运行时间*/
		for (int i = 0; i < 256; i++) {
			if (tFreq[i] > 0)
				tChar.push_back(i);
		}

		while (indexR < s.size()) {
			hasString = true;
			/*若没有包含所有字母，则hasString为false*/
			for (int i = 0; i < tChar.size(); i++) {
				if (sFreq[tChar[i]] < tFreq[tChar[i]])
				{
					hasString = false;
					break;
				}
			}
			/*如果包含所有字母，则滑动窗口左端缩减，否则，向右扩增*/
			if (hasString) {
				if (res.size() == 0 || (indexR - indexL + 1) < res.size())
					res = s.substr(indexL, indexR - indexL + 1);
				sFreq[s[indexL++]]--;
			}
			else
				sFreq[s[++indexR]]++;

		}

		return res;
	}
};

int main() {
	Solution solution;
	string s = "ADOBECODEBANC";
	string t = "ABC";
	string res = solution.minWindow(s, t);
	cout << res;
	system("pause");
	return 0;
}