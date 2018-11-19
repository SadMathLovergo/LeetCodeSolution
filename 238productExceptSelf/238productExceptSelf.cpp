#include <vector>
using namespace std;

//第238题 除自身以外数组的乘积
//解题思路：需要使用O(N)时间复杂度的算法
//对数组进行两次遍历
//第一次遍历：从nums[0]到nums[n-1]进行遍历，output[i]中存储从nums[0]到nums[i-1]的乘积，这样一来，每次计算可以基于上一次的计算结果，减小时间复杂度
//第二次遍历：从nums[n-1]到nums[0]进行遍历，output[i]中存储最终的结果
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> output(nums.size(), 0);
		output[0] = 1;

		//第一轮遍历
		for (int i = 1; i < output.size(); i++)
			output[i] = output[i - 1] * nums[i - 1];

		//第二轮遍历
		for (int i = output.size() - 2, temp = nums[i + 1]; i >= 0; i--) {
			output[i] *= temp;
			temp *= nums[i];
		}

		return output;
	}
};

int main() {
	vector<int> nums{ 1,2,3 };
	Solution().productExceptSelf(nums);

	system("pause");
	return 0;
}