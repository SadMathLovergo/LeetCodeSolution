#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
	//判断这两个单词是否只差一个字母
	bool isSimilarWord(string word1, string word2) {
		int difNum = 0;
		for (int i = 0; i < word1.size(); i++)
			if (word1[i] != word2[i]) {
				difNum++;
				if (difNum > 1)
					return false;
			}
		if (difNum == 1)
			return true;
		return false;
	}
	//采用广度优先遍历的方法寻找最短路径
	int BFS(int startIndex, int endIndex, vector<vector<bool>>& simWordRecord) {
		queue<pair<int, int>> pathMemory;//(位置，当前步数)
		pathMemory.push(make_pair(startIndex, 1));

		while (!pathMemory.empty()) {
			int curIndex = pathMemory.front().first;
			int curLength = pathMemory.front().second;
			pathMemory.pop();
			for (int i = 0; i < simWordRecord.size(); i++)
				if (simWordRecord[curIndex][i]) {
					if (i == endIndex)
						return curLength + 1;
					pathMemory.push(make_pair(i, curLength + 1));
					simWordRecord[curIndex][i] = false;
					simWordRecord[i][curIndex] = false;
				}
		}

		return 0;
	}

public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (wordList.empty())
			return 0;

		//判断wordList中是否有endWord，并找出endWord的索引
		int endWordIndex = -1;
		for (int i = 0; i < wordList.size(); i++)
			if (endWord == wordList[i]) {
				endWordIndex = i;
				break;
			}
		if (endWordIndex == -1)
			return 0;

		//将beginWord压入wordList中
		wordList.push_back(beginWord);
		int n = wordList.size();
		//用于记录每两个单词是否可以转化
		vector<vector<bool>> simWordRecord(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (isSimilarWord(wordList[i], wordList[j])) {
					simWordRecord[i][j] = true;
					simWordRecord[j][i] = true;
				}
			}
		}
		//采用广度优先遍历的方式，寻找最短路径
		return BFS(n - 1, endWordIndex, simWordRecord);
	}
};