#include <string>
using namespace std;

//��43�� �ַ������
class Solution {
private:
	//��������ת����ַ�����ӣ�����δ��ת��ȥ���ַ���
	string addition(string num1, string num2) {
		string& shortStr = num1.size() < num2.size() ? num1 : num2;
		string& longStr = num1.size() < num2.size() ? num2 : num1;

		int i = 0;
		int accu = 0;

		for (; i < shortStr.size(); i++) {
			accu += (shortStr[i] - '0') + (longStr[i] - '0');
			longStr[i] = accu % 10 + '0';
			accu /= 10;
		}

		for (; i < longStr.size(); i++) {
			accu += (longStr[i] - '0');
			longStr[i] = accu % 10 + '0';
			accu /= 10;
		}

		if (accu != 0)
			longStr += accu % 10 + '0';

		return longStr;
	}

	//����ת����ַ����뵥��������ˣ�����δ��ת��ȥ�Ľ���ַ���
	string singleMultiply(string num, char multiplier) {
		int accu = 0;
		string result;
		for (int i = 0; i < num.length(); i++) {
			accu += (num[i] - '0') * (multiplier - '0');
			result += accu % 10 + '0';
			accu /= 10;
		}
		if (accu != 0)
			result += accu % 10 + '0';
		return result;
	}

public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		string result;

		for (int i = 0; i < num2.size(); i++) {
			string multiplyRes = singleMultiply(num1, num2[i]);
			for (int j = 0; j < i; j++)
				multiplyRes = '0' + multiplyRes;
			result = addition(result, multiplyRes);
		}

		reverse(result.begin(), result.end());
		return result;
	}
};