#include <string>
#include <stack>
using namespace std;

//��151�� ��ת�ַ�����ĵ���
//����˼·��Ŀǰû�뵽ʲô�ر�Ľ���˼·��������Ҫ�Ż�
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