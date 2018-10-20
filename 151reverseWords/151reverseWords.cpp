#include <string>
#include <stack>
using namespace std;

//第151题 翻转字符串里的单词
//解题思路：目前没想到什么特别的解题思路，后续需要优化
class Solution {
public:
	void reverseWords(string &s) {
		if (s.empty())
			return;

		int beginIndex = 0;
		int endIndex = 0;
		stack<string> memo;

		while (endIndex < s.length()) {
			int charPointer = endIndex;

			while (charPointer < s.length() && s[charPointer] == ' ')
				charPointer++;

			if (charPointer >= s.length())
				break;

			beginIndex = charPointer;

			while (charPointer < s.length() && s[charPointer] != ' ')
				charPointer++;

			endIndex = charPointer;

			memo.push(s.substr(beginIndex, endIndex - beginIndex));
		}

		s.clear();
		if (memo.empty())
			return;
		s += memo.top();
		memo.pop();
		while (!memo.empty()) {
			s += ' ';
			s += memo.top();
			memo.pop();
		}
	}
};