#include <string>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int strLength = str.length();

		if (strLength == 0)
			return 0;

		//找到第一个不为' '的字符索引
		int curIndex = 0;
		while (curIndex < strLength && str[curIndex] == ' ')
			curIndex++;

		//若没有非空字符
		if (curIndex == strLength)
			return 0;

		//若第一位为'+'或'-'，提取符号位
		bool isPositive = true;
		if (str[curIndex] == '+' || str[curIndex] == '-')
			isPositive = str[curIndex++] == '+' ? true : false;

		queue<int> charMemo;

		//提取有效字符
		while (curIndex < strLength && str[curIndex] >= '0' && str[curIndex] <= '9')
			charMemo.push(str[curIndex++] - '0');

		//将开头所有的0弹出
		while (!charMemo.empty() && charMemo.front() == 0)
			charMemo.pop();

		//若没有有效字符
		if (charMemo.empty())
			return 0;

		//若超过10位数
		if (charMemo.size() > 10)
			return isPositive ? INT_MAX : INT_MIN;

		stack<int> charStack;
		while (!charMemo.empty()) {
			charStack.push(charMemo.front());
			charMemo.pop();
		}

		//计算出最终结果
		long long res = 0;
		int i = 0;
		while (!charStack.empty()) {
			res += pow(10, i++)*charStack.top();
			charStack.pop();
		}

		//取有效值
		res = isPositive ? min(res, (long long)INT_MAX) : -min(res, (long long)INT_MAX + 1);
		return (int)res;
	}
};