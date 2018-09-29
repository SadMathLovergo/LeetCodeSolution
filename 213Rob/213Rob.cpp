#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];

		int n = nums.size();
		vector<int> memo(n, -1);
		memo[0] = nums[0];
		memo[1] = max(nums[0], nums[1]);

		for (int i = 2; i < n; i++) {
			memo[i] = max(memo[i - 2] + nums[i], memo[i - 1]);
		}
		if (memo[n - 1] == memo[n - 2])//如果相等，意味着此最佳打劫方案没有抢劫最后一家房屋
			return memo[n - 1];
		//如果不相等，则意味着此打劫方案抢劫了最后一家房屋
		vector<int> memoWithoutFirst(n, -1);
		memoWithoutFirst[1] = nums[1];
		memoWithoutFirst[2] = max(nums[1], nums[2]);

		for (int i = 3; i < n; i++) {
			memoWithoutFirst[i] = max(memoWithoutFirst[i - 2] + nums[i], memoWithoutFirst[i - 1]);
		}
		if (memo[n - 1] == memoWithoutFirst[n - 1])//如果相等，则意味着此最佳打劫方案没有抢劫第一家房屋
			return memo[n - 1];
		//如果不相等，则意味着此最佳打劫方案抢劫了第一家房屋和最后一家房屋
		return max(memo[n - 2], memoWithoutFirst[n - 1]);
	}
};