#include <string>
#include <iostream>
using namespace std;

//第224题 基本计算器
//解题思路：采用递归的方式计算
//任何一组括号或者一个数字之后紧跟着的一定是一个运算符号
struct IndexValue
{
	int value;
	int index;
	IndexValue(int _value, int _index):value(_value),index(_index){}
};

enum Symbol
{
	plus = 0,
	substract
};

class Solution {
private:
	//已知一组括号的左括号索引，求出此括号内的计算值，beginIndex为左括号的索引值
	//返回的struct中，value为括号内的计算值，index为右括号的索引值
	IndexValue * calculate(int beginIndex, string& s) {
		int sum = 0;
		int i = beginIndex + 1;
		Symbol lastSymbol = Symbol::plus;
		//直到找到右括号
		while (s.at(i) != ')') {
			//移除掉空格
			while (s.at(i) == ' ')
				i++;
			//若为右括号，则结束
			if (s.at(i) == ')')
				break;
			else if (s.at(i) == '(') {//若为左括号，则递归调用
				IndexValue* infor = calculate(i, s);
				switch (lastSymbol)
				{
				case Symbol::plus:
					sum += infor->value;
					i = infor->index + 1;
					delete infor;
					break;
				case Symbol::substract:
					sum -= infor->value;
					i = infor->index + 1;
					delete infor;
					break;
				default:
					break;
				}
				if (s.at(i) == ')')
					break;
			}
			else if (s.at(i) >= '0' && s.at(i) <= '9') {//若为数字，则提取出数字
				int startIndex = i;
				while (s.at(i) >= '0' && s.at(i) <= '9')
					i++;
				int num = stoi(s.substr(startIndex, i - startIndex));
				switch (lastSymbol)
				{
				case Symbol::plus:
					sum += num;
					break;
				case Symbol::substract:
					sum -= num;
					break;
				default:
					break;
				}
			}
			//移除掉空格
			while (s.at(i) == ' ')
				i++;
			//若为右括号，则结束
			if (s.at(i) == ')')
				break;
			//若不为右括号，则必为运算符号
			if (s.at(i) == '+')//若为加号
				lastSymbol = Symbol::plus;
			else//若为减号
				lastSymbol = Symbol::substract;
			i++;
		}
		return new IndexValue(sum, i);
	}

public:
	int calculate(string s) {
		int i = 0;
		int sum = 0;
		Symbol lastSymbol = Symbol::plus;
		while (i < s.size()) {
			//移除掉空格
			while (s.at(i) == ' ')
				i++;
			//若已经读完
			if (i >= s.size())
				break;
			//若为左括号
			else if (s.at(i) == '(') {
				IndexValue* infor = calculate(i, s);
				switch (lastSymbol)
				{
				case Symbol::plus:
					sum += infor->value;
					i = infor->index + 1;
					delete infor;
					break;
				case Symbol::substract:
					sum -= infor->value;
					i = infor->index + 1;
					delete infor;
					break;
				default:
					break;
				}
				if (i >= s.size())
					break;
			}
			//若为数字
			else if (s.at(i) >= '0' && s.at(i) <= '9') {
				int startIndex = i;
				while (i < s.length() && s.at(i) >= '0' && s.at(i) <= '9')
					i++;
				int num = stoi(s.substr(startIndex, i - startIndex));
				switch (lastSymbol)
				{
				case Symbol::plus:
					sum += num;
					break;
				case Symbol::substract:
					sum -= num;
					break;
				default:
					break;
				}
			}
			//若已经读完
			if (i >= s.size())
				break;
			//移除掉空格
			while (i < s.length() && s.at(i) == ' ')
				i++;
			//若已读完
			if (i >= s.size())
				break;
			//若未读完，则必为运算符号
			if (s.at(i) == '+')//加号
				lastSymbol = Symbol::plus;
			else//减号
				lastSymbol = Symbol::substract;
			i++;
		}
		return sum;
	}
};

int main(){
	string s = "(1+(4+5+2)-3)+(6+8)";
	int num = Solution().calculate(s);
	cout << num << endl;
	system("pause");
	return 0;
}
