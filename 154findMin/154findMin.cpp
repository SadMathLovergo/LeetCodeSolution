#include <vector>
#include <algorithm>
using namespace std;

//第154题：寻找旋转排序数组中的最小值2
//解题思路：和寻找旋转排序数组的旋转点解题思路没有区别
class Solution {
private:
	int findMin(vector<int>& nums, int indexL, int indexR) {
		if (nums[indexL] < nums[indexR] || indexL == indexR)
			return nums[indexL];
		if (indexL == indexR - 1)
			return min(nums[indexL], nums[indexR]);

		int curIndex = indexL + (indexR - indexL) / 2;
		if (nums[curIndex] == nums[indexL] && nums[curIndex] == nums[indexR])
			return min(findMin(nums, indexL, curIndex), findMin(nums, curIndex, indexR));
		else if (nums[indexL] <= nums[curIndex])
			return findMin(nums, curIndex + 1, indexR);
		else//nums[curIndex] <= nums[indexR]
			return findMin(nums, indexL, curIndex);
	}

public:
	int findMin(vector<int>& nums) {
		int leftIndex = 0;
		int rightIndex = nums.size() - 1;

		return findMin(nums, leftIndex, rightIndex);
	}
};