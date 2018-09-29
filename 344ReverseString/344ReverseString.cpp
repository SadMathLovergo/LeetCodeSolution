#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	string reverseString(string s) {
		stack<char> StackRecord;
		for (string::iterator iter = s.begin(); iter != s.end(); iter++)
			StackRecord.push(*iter);

		string result;
		while (!StackRecord.empty()) {
			result.push_back(StackRecord.top());
			StackRecord.pop();
		}

		return result;
	}
};