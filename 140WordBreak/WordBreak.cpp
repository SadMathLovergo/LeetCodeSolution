#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	vector<string> resVec;
	//���õݹ���ݵķ��������ݼ�¼��ɲ�ֺ���ַ���
	void splitString(string s, int curIndex, vector<int>& record, vector<vector<int>>& memo) {
		//���Ѿ����һ�������Ĳ�ַ�ʽ
		if (curIndex < 0) {
			//��ǰ����ܹ����Ϊ���ٸ����ַ���
			int strNum = record.size();

			if (strNum == 1)//���ֻ���Ϊһ���ַ���
				resVec.push_back(s);
			else {//������Ϊ����ַ���
				int lastIndex = record[strNum-1];
				string newStr;
				for (int i = strNum - 2; i >= 0; i--) {
					int newIndex = record[i];
					newStr += s.substr(lastIndex, newIndex - lastIndex);
					newStr += " ";
					lastIndex = newIndex;
				}
				//�������һ���ַ���
				newStr += s.substr(lastIndex, s.length() - lastIndex);
				resVec.push_back(newStr);
			}

			return;
		}

		for (int i = 0; i < memo[curIndex].size(); i++) {
			record.push_back(memo[curIndex][i]);
			splitString(s, memo[curIndex][i] - 1, record, memo);
			record.pop_back();
		}
	}

public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		resVec.clear();

		if (s.empty() || wordDict.empty())
			return resVec;

		//�����0����ǰλ�õ��ַ������ʱ�������Գɹ���֣����һ�����ʵ�����ĸ��������ʲôλ��
		vector<vector<int>> splitMemo(s.length(), vector<int>());

		for (int i = 0; i < s.length(); i++) {//����ÿ������
			for (int j = 0; j < wordDict.size(); j++) {//����wordDict�еĵ���
				int startIndex = i - wordDict[j].length() + 1;
				if (startIndex == 0 || (startIndex > 0 && !splitMemo[startIndex - 1].empty())) {
					//�ж��ַ����Ƿ����
					bool isSameStr = true;
					for(int k = startIndex; k <= i; k++)
						if (s[k] != wordDict[j][k - startIndex]) {
							isSameStr = false;
							break;
						}
					//����ַ�����ȣ��򽫽������ñ����У���������wordDict��ʣ�µĵ���
					if (isSameStr)
						splitMemo[i].push_back(startIndex);
				}
			}
		}

		//���޷����
		if (splitMemo[s.length() - 1].empty())
			return resVec;

		//���õݹ���ݷ������ݲ�ֽ������ȡ��ֺ�����ַ���
		vector<int> record;
		splitString(s, s.length() - 1, record, splitMemo);

		return resVec;
	}
};

int main() {
	string s = "pineapplepenapple";
	vector<string> wordDict{ "apple","pen","applepen","pine","pineapple" };
	
	vector<string> resVec = Solution().wordBreak(s, wordDict);
	
	for (int i = 0; i < resVec.size(); i++) {
		cout << resVec[i] << endl;
	}

	system("pause");
	return 0;
}