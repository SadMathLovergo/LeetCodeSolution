#include <string>
#include <iostream>
using namespace std;

//��224�� ����������
//����˼·�����õݹ�ķ�ʽ����
//�κ�һ�����Ż���һ������֮������ŵ�һ����һ���������
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
	//��֪һ�����ŵ�����������������������ڵļ���ֵ��beginIndexΪ�����ŵ�����ֵ
	//���ص�struct�У�valueΪ�����ڵļ���ֵ��indexΪ�����ŵ�����ֵ
	IndexValue * calculate(int beginIndex, string& s) {
		int sum = 0;
		int i = beginIndex + 1;
		Symbol lastSymbol = Symbol::plus;
		//ֱ���ҵ�������
		while (s.at(i) != ')') {
			//�Ƴ����ո�
			while (s.at(i) == ' ')
				i++;
			//��Ϊ�����ţ������
			if (s.at(i) == ')')
				break;
			else if (s.at(i) == '(') {//��Ϊ�����ţ���ݹ����
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
			else if (s.at(i) >= '0' && s.at(i) <= '9') {//��Ϊ���֣�����ȡ������
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
			//�Ƴ����ո�
			while (s.at(i) == ' ')
				i++;
			//��Ϊ�����ţ������
			if (s.at(i) == ')')
				break;
			//����Ϊ�����ţ����Ϊ�������
			if (s.at(i) == '+')//��Ϊ�Ӻ�
				lastSymbol = Symbol::plus;
			else//��Ϊ����
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
			//�Ƴ����ո�
			while (s.at(i) == ' ')
				i++;
			//���Ѿ�����
			if (i >= s.size())
				break;
			//��Ϊ������
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
			//��Ϊ����
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
			//���Ѿ�����
			if (i >= s.size())
				break;
			//�Ƴ����ո�
			while (i < s.length() && s.at(i) == ' ')
				i++;
			//���Ѷ���
			if (i >= s.size())
				break;
			//��δ���꣬���Ϊ�������
			if (s.at(i) == '+')//�Ӻ�
				lastSymbol = Symbol::plus;
			else//����
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
