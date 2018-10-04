#include <string>
#include <stack>
#include <vector>
using namespace std;

//����ת��������
//����˼·����ÿһλ�ϵ����ֱַ����ת����ÿһλ�ϵ�����ת��������ͬ��Ψһ��ͬ����ʹ�õ��������ֲ�ͬ
class Solution {
private:
	//ÿһλ�ϵ��������֣�����ǧλ�ϵ�����С��4�����ʹ��������ͬ����������
	vector<vector<char>> RomanChar{ 
		vector<char>{'I','V','X'},
		vector<char>{'X','L','C'},
		vector<char>{'C','D','M'},
		vector<char>{'M','M','M'} 
	};

	string formRoman(int num, vector<char> RomanChar) {
		string res;
		if (num < 4) {//numС��4
			while (num > 0) {
				res += RomanChar[0];
				num--;
			}
			return res;
		}
		else if (num == 4) {//numΪ4
			res += RomanChar[0];
			res += RomanChar[1];
			return res;
		}
		else if (num < 9) {//num����4С��9
			res += RomanChar[1];
			while (num > 5) {
				res += RomanChar[0];
				num--;
			}
			return res;
		}
		else {//numΪ9
			res += RomanChar[0];
			res += RomanChar[2];
			return res;
		}
	}

	

public:
	string intToRoman(int num) {
		string resStr;//�����������ֽ��

		stack<int> numRecord;//����ÿһλ���ֵĶ�ջ

		/*�����ִӵ�λ����λѹ���ջ��*/
		while (num != 0) {
			numRecord.push(num % 10);
			num /= 10;
		}

		/*��ÿһλ������ת��Ϊ��������*/
		while (!numRecord.empty()) {
			resStr += formRoman(numRecord.top(), RomanChar[numRecord.size()-1]);
			numRecord.pop();
		}

		return resStr;
	}
};