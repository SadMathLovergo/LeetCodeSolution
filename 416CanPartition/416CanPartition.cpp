#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		if (nums.size() == 1)
			return false;

		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];
		if (sum % 2 != 0)
			return false;

		sum /= 2;

		vector<bool> memo(sum + 1, false);

		for (int i = 0; i <= sum; i++)
			memo[i] = (nums[0] == i);

		for (int i = 1; i < nums.size(); i++)
			for (int j = sum; j > nums[i]; j--)
				memo[j] = memo[j] || memo[j - nums[i]];

		return memo[sum];
	}
};