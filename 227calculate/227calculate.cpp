#include <string>
#include <vector>
using namespace std;

//��227�� ����������2
//����˼·���ȼ���˳����ټ���Ӽ�
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
		//�ȼ������еĳ˷��ͳ���
		while (i < s.length()) {
			//�ҵ���һ�����ֵ���ʼλ��
			while (i < s.length() && s.at(i) == ' ')
				i++;
			if (i >= s.length())//���ַ����Ѿ�����
				break;
			int beginIndex = i;
			//�ҵ����ֵ���ֹλ��
			while (i < s.length() && s.at(i) >= '0' && s.at(i) <= '9')
				i++;
			//���ַ���ת��Ϊ����
			int num = stoi(s.substr(beginIndex, i - beginIndex));

			//������һ��������ľ��������������ѹ�������л���ֱ�Ӽ������
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

			//�ҵ���һ���������������lastSymbol
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