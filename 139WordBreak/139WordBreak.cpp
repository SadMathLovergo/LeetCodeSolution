#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		if (s.empty())
			return true;

		if (wordDict.empty())
			return false;

		//s.length()个背包，存储从[0,i]区间的字符串能否拆分为wordDict里的字符串
		vector<bool> memo(s.length(), false);

		for (int i = 0; i < s.length(); i++) {//遍历每个背包
			for (int j = 0; j < wordDict.size(); j++) {//遍历wordDict中的单词
				int startIndex = i - wordDict[j].length() + 1;
				if (startIndex == 0 || (startIndex > 0 && memo[startIndex - 1])) {
					//判断字符串是否相等
					bool isSameStr = true;
					for (int k = startIndex; k <= i; k++) {
						if (s[k] != wordDict[j][k - startIndex]) {
							isSameStr = false;
							break;
						}
					}
					//如果字符串相等，则该背包为true，wordDict中剩下的单词不需要继续遍历
					if (isSameStr) {
						memo[i] = true;
						break;
					}
				}
			}
		}

		return memo[s.length() - 1];
	}
};

int main() {
	string s = "applepenapple";
	vector<string> wordDict{ "apple","pen" };

	bool res = Solution().wordBreak(s, wordDict);
	if (res)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;

	system("pause");
	return 0;
}