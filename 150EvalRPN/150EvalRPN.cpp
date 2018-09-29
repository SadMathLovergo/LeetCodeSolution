#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> StackRecord;

		for (vector<string>::iterator iter = tokens.begin();
			iter != tokens.end(); iter++) {

			if (*iter == "+" || *iter == "-" || *iter == "*" || *iter == "/") {
				int num2 = StackRecord.top();
				StackRecord.pop();
				int num1 = StackRecord.top();
				StackRecord.pop();
				int result;
				if (*iter == "+") {
					result = num1 + num2;
				}
				else if (*iter == "-") {
					result = num1 - num2;
				}
				else if (*iter == "*") {
					result = num1 * num2;
				}
				else {
					result = num1 / num2;
				}
				StackRecord.push(result);
			}
			else {
				int num;
				str2int(num, *iter);
				StackRecord.push(num);
			}

		}

		return StackRecord.top();

	}

private:
	void str2int(int &int_temp, const string &string_temp) {
		stringstream stream(string_temp);
		stream >> int_temp;
	}
};