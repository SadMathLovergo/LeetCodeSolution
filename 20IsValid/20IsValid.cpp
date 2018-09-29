#include <string>
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> record;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				record.push(s[i]);
			else
			{
				char cmp;
				if (s[i] == ')')
					cmp = '(';
				else if (s[i] == ']') {
					cmp = '[';
				}
				else{
					assert(s[i] == '}');
					cmp = '{';
				}
				if ( record.empty() || record.top() != cmp) {
					return false;
				}
				record.pop();
			}
		}
		if (!record.empty())
			return false;
		return true;
	}
};