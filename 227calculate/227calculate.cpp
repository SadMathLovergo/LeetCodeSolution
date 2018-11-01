#include <string>
#include <vector>
using namespace std;

//第227题 基本计算器2
//解题思路：先计算乘除，再计算加减
class Solution {
public:
	enum symbol {
		plus = 0,
		substract,
		multiply,
		divide
	};

	int calculate(string s) {
		vector<int> memo;
		symbol lastSymbol = symbol::plus;

		int i = 0;
		//先计算所有的乘法和除法
		while (i < s.length()) {
			//找到下一个数字的起始位置
			while (i < s.length() && s.at(i) == ' ')
				i++;
			if (i >= s.length())//若字符串已经读完
				break;
			int beginIndex = i;
			//找到数字的终止位置
			while (i < s.length() && s.at(i) >= '0' && s.at(i) <= '9')
				i++;
			//将字符串转化为数字
			int num = stoi(s.substr(beginIndex, i - beginIndex));

			//根据上一个运算符的具体情况，将数字压入数组中或者直接计算出来
			switch (lastSymbol)
			{
			case symbol::plus:
				memo.push_back(num);
				break;
			case symbol::substract:
				memo.push_back(-num);
				break;
			case symbol::multiply:
				memo.back() *= num;
				break;
			case symbol::divide:
				memo.back() = memo.back() < 0 ? -((-memo.back()) / num) : memo.back() / num;
				break;
			default:
				break;
			}

			//找到下一个运算符，并更新lastSymbol
			while (i < s.length() && s.at(i) == ' ')
				i++;
			if (i >= s.length())
				break;
			switch (s.at(i))
			{
			case '+':
				lastSymbol = symbol::plus;
				break;
			case '-':
				lastSymbol = symbol::substract;
				break;
			case '*':
				lastSymbol = symbol::multiply;
				break;
			case '/':
				lastSymbol = symbol::divide;
				break;
			default:
				break;
			}

			i++;
		}

		int sum = 0;
		for (int i = 0; i < memo.size(); i++)
			sum += memo[i];
		return sum;
	}
};