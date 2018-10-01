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

		//s.length()���������洢��[0,i]������ַ����ܷ���ΪwordDict����ַ���
		vector<bool> memo(s.length(), false);

		for (int i = 0; i < s.length(); i++) {//����ÿ������
			for (int j = 0; j < wordDict.size(); j++) {//����wordDict�еĵ���
				int startIndex = i - wordDict[j].length() + 1;
				if (startIndex == 0 || (startIndex > 0 && memo[startIndex - 1])) {
					//�ж��ַ����Ƿ����
					bool isSameStr = true;
					for (int k = startIndex; k <= i; k++) {
						if (s[k] != wordDict[j][k - startIndex]) {
							isSameStr = false;
							break;
						}
					}
					//����ַ�����ȣ���ñ���Ϊtrue��wordDict��ʣ�µĵ��ʲ���Ҫ��������
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