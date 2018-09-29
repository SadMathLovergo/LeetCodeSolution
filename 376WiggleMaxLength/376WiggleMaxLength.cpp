#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.empty())
			return 0;

		vector<int> LenRecord(nums.size(), 1);	//记录[0,i]的，包含当前元素的，最长摆动子序列的长度
		vector<int> SymRecord(nums.size(), 0);	//记录[0,i]的最长摆动子序列中，当前元素相比于前一个元素的大小，若为1则比前一个元素大，若为-1则比前一个元素小，若为0，则当前元素为序列中第一个元素

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