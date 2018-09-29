#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s == "")
			return true;

		queue<char> QueueRecord;
		stack<char> StackRecord;
		for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
			if ((*iter >= 'a' && *iter <= 'z') || (*iter >= 'A' && *iter <= 'Z') || (*iter >= '0' && *iter <= '9') ) {
				QueueRecord.push(*iter);
				StackRecord.push(*iter);
			}
		}

		while (!QueueRecord.empty()) {
			int record = abs(QueueRecord.front() - StackRecord.top());

			if ((QueueRecord.front() >= '0' && QueueRecord.front() <= '9') || (StackRecord.top() >= '0' && StackRecord.top() <= '9')) {
				if (record != 0)
					return false;
			}
			else
			{
				if (record != 0 && record != 32)
					return false;
			}

			QueueRecord.pop();
			StackRecord.pop();
		}

		return true;
	}
};

int main() {
	string s = "A man, a plan, a canal: Panama";
	Solution solution;

	if (solution.isPalindrome(s))
		cout << "该字符串是回文串" << endl;
	else
		cout << "该字符串不是回文串" << endl;
	system("pause");
	return 0;
}