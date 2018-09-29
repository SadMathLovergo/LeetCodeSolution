#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> record;
		int oriNum;
		int resultNum = n;
		while (resultNum != 1) {
			/*����һ�μ������������*/
			record.insert(resultNum);
			/*����һ�μ�������Ϊ��һ�μ����ԭ����*/
			oriNum = resultNum;
			resultNum = 0;
			/*������*/
			while (oriNum != 0) {
				resultNum += pow(oriNum % 10, 2);
				oriNum /= 10;
			}
			/*����ѭ�������ж�Ϊ���ֹ���*/
			if (record.find(resultNum) != record.end())
				return false;
		}
		/*�ж�Ϊ�ֹ���*/
		return true;
	}
};