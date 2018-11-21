#pragma once
#include <vector>
using namespace std;

//第303题：区域和检索-数组不可变
class NumArray {
private:
	vector<int> memo;

public:
	NumArray(vector<int> nums) {
		if (nums.empty())
			return;
		memo = vector<int>(nums.size(), 0);
		memo[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
			memo[i] = memo[i - 1] + nums[i];
	}

	int sumRange(int i, int j) {
		if (i == 0)
			return memo[j];
		return memo[j] - memo[i - 1];
	}
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i,j);
*/