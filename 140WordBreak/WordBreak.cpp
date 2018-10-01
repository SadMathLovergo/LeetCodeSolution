#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	vector<string> resVec;
	//利用递归回溯的方法，根据记录组成拆分后的字符串
	void splitString(string s, int curIndex, vector<int>& record, vector<vector<int>>& memo) {
		//若已经获得一种完整的拆分方式
		if (curIndex < 0) {
			//当前拆分总共拆分为多少个子字符串
			int strNum = record.size();

			if (strNum == 1)//如果只拆分为一个字符串
				resVec.push_back(s);
			else {//如果拆分为多个字符串
				int lastIndex = record[strNum-1];
				string newStr;
				for (int i = strNum - 2; i >= 0; i--) {
					int newIndex = record[i];
					newStr += s.substr(lastIndex, newIndex - lastIndex);
					newStr += " ";
					lastIndex = newIndex;
				}
				//加上最后一段字符串
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

		//保存从0到当前位置的字符串拆分时，若可以成功拆分，最后一个单词的首字母可以在在什么位置
		vector<vector<int>> splitMemo(s.length(), vector<int>());

		for (int i = 0; i < s.length(); i++) {//遍历每个背包
			for (int j = 0; j < wordDict.size(); j++) {//遍历wordDict中的单词
				int startIndex = i - wordDict[j].length() + 1;
				if (startIndex == 0 || (startIndex > 0 && !splitMemo[startIndex - 1].empty())) {
					//判断字符串是否相等
					bool isSameStr = true;
					for(int k = startIndex; k <= i; k++)
						if (s[k] != wordDict[j][k - startIndex]) {
							isSameStr = false;
							break;
						}
					//如果字符串相等，则将结果存入该背包中，继续遍历wordDict中剩下的单词
					if (isSameStr)
						splitMemo[i].push_back(startIndex);
				}
			}
		}

		//若无法拆分
		if (splitMemo[s.length() - 1].empty())
			return resVec;

		//采用递归回溯法，根据拆分结果，获取拆分后的新字符串
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