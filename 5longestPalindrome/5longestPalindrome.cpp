#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int num = s.length();
		if (num == 0)
			return s;

		//���ö�̬�滮�ķ������������Ĵ�
		//memo[i][j]����s[i]��s[j]�Ƿ�Ϊ���Ĵ�
		vector<vector<bool>> memo(num, vector<bool>(num, false));

		//ÿ���ַ�����Ϊ���Ĵ�
		for (int i = 0; i < num; i++)
			memo[i][i] = true;

		for (int i = 0; i < num - 1; i++)
			memo[i][i + 1] = s[i] == s[i + 1];

		//��ÿ������Ϊi+1���ַ������б���
		for (int i = 2; i < num; i++) {
			for (int j = 0; j < num - i; j++) {
				if (s[j] == s[j + i])
					memo[j][j + i] = memo[j + 1][j + i - 1];
			}
		}

		//�ҵ�����Ĵ�
		for (int i = num - 1; i >= 0; i--) {
			for (int j = 0; j < num - i; j++) {
				if (memo[j][j + i]) {
					return s.substr(j, i + 1);
				}
			}
		}
	}
};