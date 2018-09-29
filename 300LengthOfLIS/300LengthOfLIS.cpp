#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;

		vector<int> result(nums.size(), 1);

		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j])
					result[i] = max(result[i], result[j] + 1);
			}
		}

		int temp = result[0];
		for (int i = 1; i < result.size(); i++)
			temp = max(temp, result[i]);

		return temp;
	}
};