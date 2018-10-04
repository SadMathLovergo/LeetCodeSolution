#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;

		vector<string> memo(numRows, "");

		int circle = numRows * 2 - 2;
		int circleNum = s.length() / circle;//总循环次数
		int surplusNum = s.length() % circle;//剩余次数
		int curChar = 0;//记录当前字符位置
						//先进行完整的循环
		for (int i = 0; i < circleNum; i++) {
			for (int j = 0; j < numRows; j++)
				memo[j].push_back(s[curChar++]);
			for (int j = numRows - 2; j > 0; j--)
				memo[j].push_back(s[curChar++]);
		}

		//进行不完整的循环遍历
		for (int i = 0; i < min(surplusNum, numRows); i++)
			memo[i].push_back(s[curChar++]);
		for (int i = 0; i < (surplusNum > numRows ? (surplusNum - numRows) : 0); i++)
			memo[numRows - 2 - i].push_back(s[curChar++]);

		string resStr;

		for (int i = 0; i < numRows; i++)
			resStr += memo[i];

		return resStr;
	}
};