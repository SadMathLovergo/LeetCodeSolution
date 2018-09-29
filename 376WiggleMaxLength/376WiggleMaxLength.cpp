#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.empty())
			return 0;

		vector<int> LenRecord(nums.size(), 1);	//��¼[0,i]�ģ�������ǰԪ�صģ���ڶ������еĳ���
		vector<int> SymRecord(nums.size(), 0);	//��¼[0,i]����ڶ��������У���ǰԪ�������ǰһ��Ԫ�صĴ�С����Ϊ1���ǰһ��Ԫ�ش���Ϊ-1���ǰһ��Ԫ��С����Ϊ0����ǰԪ��Ϊ�����е�һ��Ԫ��

		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (SymRecord[j] == -1) {
					if (nums[i] > nums[j]) {
						if (LenRecord[i] <= LenRecord[j]) {
							LenRecord[i] = LenRecord[j] + 1;
							SymRecord[i] = 1;
						}
					}
				}
				else if (SymRecord[j] == 1) {
					if (nums[i] < nums[j]) {
						if (LenRecord[i] <= LenRecord[j]) {
							LenRecord[i] = LenRecord[j] + 1;
							SymRecord[i] = -1;
						}
					}
				}
				else {//SymRecord[j] == 0
					if (nums[i] > nums[j]) {
						if (LenRecord[i] <= LenRecord[j]) {
							LenRecord[i] = LenRecord[j] + 1;
							SymRecord[i] = 1;
						}
					}
					else if(nums[i] < nums[j]) {
						if (LenRecord[i] <= LenRecord[j]) {
							LenRecord[i] = LenRecord[j] + 1;
							SymRecord[i] = -1;
						}
					}
				}
			}
		}

		int temp = LenRecord[0];
		for (int i = 1; i < nums.size(); i++)
			temp = max(temp, LenRecord[i]);
		return temp;
	}
};