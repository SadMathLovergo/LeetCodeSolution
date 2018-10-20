#include <vector>
using namespace std;

//第153题：寻找旋转排序数组中的最小值
//解题思路：和寻找旋转排序数组的旋转点解题思路没有区别
class Solution {
public:
	int findMin(vector<int>& nums) {
		int leftIndex = 0;
		int rightIndex = nums.size() - 1;

		//若数组未经过旋转，或者数组只有一个元素
		if (nums[leftIndex] <= nums[rightIndex])
			return nums[leftIndex];

		int curIndex = 0;
		while (leftIndex < rightIndex) {
			curIndex = leftIndex + (rightIndex - leftIndex) / 2;
			if (nums[leftIndex] < nums[curIndex])
				leftIndex = curIndex;
			else if (nums[curIndex] < nums[rightIndex])
				rightIndex = curIndex;
			else {
				curIndex = rightIndex;
				break;
			}
		}

		return nums[curIndex];
	}
};