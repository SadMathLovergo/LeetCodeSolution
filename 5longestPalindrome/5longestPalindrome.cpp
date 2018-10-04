#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int num = s.length();
		if (num == 0)
			return s;

		//利用动态规划的方法来求最大回文串
		//memo[i][j]保存s[i]到s[j]是否为回文串
		vector<vector<bool>> memo(num, vector<bool>(num, false));

		//每个字符本身都为回文串
		for (int i = 0; i < num; i++)
			memo[i][i] = true;

		for (int i = 0; i < num - 1; i++)
			memo[i][i + 1] = s[i] == s[i + 1];

		//对每个长度为i+1的字符串进行遍历
		for (int i = 2; i < num; i++) {
			for (int j = 0; j < num - i; j++) {
				if (s[j] == s[j + i])
					memo[j][j + i] = memo[j + 1][j + i - 1];
			}
		}

		//找到最长回文串
		for (int i = num - 1; i >= 0; i--) {
			for (int j = 0; j < num - i; j++) {
				if (memo[j][j + i]) {
					return s.substr(j, i + 1);
				}
			}
		}
	}
};