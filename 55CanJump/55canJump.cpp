#include <vector>
using namespace std;

/*第55题 跳跃游戏*/
/*解题思路：典型的动态规划问题*/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.empty())
			return true;

		vector<bool> memo(nums.size(), false);
		memo[0] = true;

		for(int i = 0; i < nums.size(); i++)
			if (memo[i]) {
				int jumpSize = nums[i];
				for (int j = 1; j <= jumpSize && (i + j) < nums.size(); j++)
					memo[i + j] = true;
			}

		return memo.back();
	}
};