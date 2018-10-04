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

		//�ҵ���һ����Ϊ' '���ַ�����
		int curIndex = 0;
		while (curIndex < strLength && str[curIndex] == ' ')
			curIndex++;

		//��û�зǿ��ַ�
		if (curIndex == strLength)
			return 0;

		//����һλΪ'+'��'-'����ȡ����λ
		bool isPositive = true;
		if (str[curIndex] == '+' || str[curIndex] == '-')
			isPositive = str[curIndex++] == '+' ? true : false;

		queue<int> charMemo;

		//��ȡ��Ч�ַ�
		while (curIndex < strLength && str[curIndex] >= '0' && str[curIndex] <= '9')
			charMemo.push(str[curIndex++] - '0');

		//����ͷ���е�0����
		while (!charMemo.empty() && charMemo.front() == 0)
			charMemo.pop();

		//��û����Ч�ַ�
		if (charMemo.empty())
			return 0;

		//������10λ��
		if (charMemo.size() > 10)
			return isPositive ? INT_MAX : INT_MIN;

		stack<int> charStack;
		while (!charMemo.empty()) {
			charStack.push(charMemo.front());
			charMemo.pop();
		}

		//��������ս��
		long long res = 0;
		int i = 0;
		while (!charStack.empty()) {
			res += pow(10, i++)*charStack.top();
			charStack.pop();
		}

		//ȡ��Чֵ
		res = isPositive ? min(res, (long long)INT_MAX) : -min(res, (long long)INT_MAX + 1);
		return (int)res;
	}
};