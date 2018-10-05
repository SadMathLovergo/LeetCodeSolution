#include <vector>
using namespace std;

/*第34题：在排序数组中查找元素的第一个和最后一个位置，要求使用算法时间复杂度为O(log n)级别*/
/*解题思路：找到target的前驱的下一个索引以及后继的上一个索引*/
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> resVec{ -1,-1 };

		int n = nums.size();

		if (n == 0 || target < nums[0] || target > nums[n - 1])
			return resVec;

		int leftIndex = 0;
		int rightIndex = n - 1;
		int curIndex = 0;

		/*寻找target的前驱的下一个索引*/
		while (leftIndex <= rightIndex) {
			curIndex = leftIndex + (rightIndex - leftIndex) / 2;
			if (nums[curIndex] <= target - 1)
				leftIndex = curIndex + 1;
			else
				rightIndex = curIndex - 1;
		}
		resVec[0] = nums[curIndex] < target ? (curIndex + 1) : curIndex;

		leftIndex = curIndex;
		rightIndex = n - 1;

		/*寻找target的后继的上一个索引*/
		while (leftIndex <= rightIndex) {
			curIndex = leftIndex + (rightIndex - leftIndex) / 2;
			if (nums[curIndex] < target + 1)
				leftIndex = curIndex + 1;
			else
				rightIndex = curIndex - 1;
		}
		resVec[1] = nums[curIndex] > target ? (curIndex - 1) : curIndex;

		if (resVec[0] > resVec[1])
			return vector<int>{-1, -1};
		return resVec;
	}
};