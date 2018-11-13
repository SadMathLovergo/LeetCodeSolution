#include <vector>
#include <algorithm>
using namespace std;

//第152题 乘积最大子序列
//解题思路：动态规划
//累乘的最大值乘以一个整数会变的更大，累乘的最小值（负数）乘以一个负数也会变成一个很大的数
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int maxNum = nums[0];	//包含当前位在内的乘积最大值
		int minNum = nums[0];	//包含当前位在内的乘积最小值
		int ans = nums[0];		//当前最大值

		for (int i = 1; i < nums.size(); i++) {
			int a = maxNum * nums[i];
			int b = minNum * nums[i];
			maxNum = max(max(a, b), nums[i]);
			minNum = min(min(a, b), nums[i]);
			ans = max(ans, maxNum);
		}

		return ans;

	}
};