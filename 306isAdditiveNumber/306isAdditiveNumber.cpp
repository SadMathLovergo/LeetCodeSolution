#pragma once
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//��306�� �ۼ���
//�ؼ�����ȷ��ǰ�������֣�ֻҪȷ����ǰ��������
//�����ֻ��Ҫһ·�ж���ȥ����
//ʹ�õݹ���ݷ�
class Solution {
private:
	//�������ۼ���������true
	//���򷵻�false
	bool isAdditive(string& num, int index1, int length1, int index2, int length2) {
		//��ȡ��ǰ���������ַ���
		string str1 = num.substr(index1, length1);
		reverse(str1.begin(), str1.end());
		string str2 = num.substr(index2, length2);
		reverse(str2.begin(), str2.end());

		//�õ��ۼӵ��ַ���
		string addiStr;
		int accu = 0;
		int i = 0;
		for (; i < min(str1.size(), str2.size()); i++) {
			accu += (str1[i] - '0') + (str2[i] - '0');
			addiStr += (accu % 10) + '0';
			accu /= 10;
		}
		if (str1.size() < str2.size()) {
			for (; i < str2.size(); i++) {
				accu += (str2[i] - '0');
				addiStr += (accu % 10) + '0';
				accu /= 10;
			}
		}
		else {
			for (; i < str1.size(); i++) {
				accu += (str1[i] - '0');
				addiStr += (accu % 10) + '0';
				accu /= 10;
			}
		}
		if (accu != 0)
			addiStr += ('0' + accu);
		reverse(addiStr.begin(), addiStr.end());

		//�Ƚ��ַ���
		if (index2 + length2 + addiStr.length() > num.length())
			return false;
		for (int i = 0; i < addiStr.length(); i++)
			if (addiStr[i] != num[index2 + length2 + i])
				return false;
		if (index2 + length2 + addiStr.length() == num.length())
			return true;
		return isAdditive(num, index2, length2, index2 + length2, addiStr.length());
	}

	//length1Ϊ��һ�����ֵĳ���
	//length2Ϊ�ڶ������ֵĳ���
	bool isAdditiveNumber(string& num, int length1, int length2) {
		if (isAdditive(num, 0, length1, length1, length2))
			return true;
		else if (length1 < num.length() / 2)
			if (num[length1] != '0' && length2 < num.length() / 2) {
				length2++;
				return isAdditiveNumber(num, length1, length2);
			}
			else {
				length1++;
				length2 = 1;
				return isAdditiveNumber(num, length1, length2);
			}
		else
			return false;
	}

public:
	bool isAdditiveNumber(string num) {
		int length1 = 1;
		int length2 = 1;
		return isAdditiveNumber(num, length1, length2);
	}
};

int main() {
	string result = Solution().isAdditiveNumber("101") ? "�����ۼ���" : "�������ۼ���";
	cout << result << endl;
	system("pause");
	return 0;
}