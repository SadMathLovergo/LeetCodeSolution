#include <vector>
using namespace std;

/*第33题 搜索旋转排序数组*/
/*要求使用log n级别的算法，所以第一反应使用二分查找法*/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();

		if (n == 0)
			return -1;

		if (n == 1)
			return nums[0] == target ? 0 : -1;

		int leftIndex = 0;
		int rightIndex = n - 1;
		int curIndex = leftIndex + (rightIndex - leftIndex) / 2;

		/*若数组未旋转，为升序数组，利用二分查找法*/
		if (nums[0] < nums[n - 1]) {
			while (leftIndex <= rightIndex) {
				if (nums[curIndex] == target)
					return curIndex;
				else if (nums[curIndex] < target)
					leftIndex = curIndex + 1;
				else
					rightIndex = curIndex - 1;
				curIndex = leftIndex + (rightIndex - leftIndex) / 2;
			}
			return -1;
		}
		
		/*若数组出现了旋转的情况*/
		/*若target在(nums[0],nums[n-1])之间，则数组中不存在target*/
		if (target < nums[leftIndex] && target > nums[rightIndex])
			return -1;
		/*找到旋转数组的旋转点*/
		while (!(nums[curIndex] >= nums[0] && nums[curIndex + 1] <= nums[n - 1])) {
			if (nums[curIndex] > nums[0])
				leftIndex = curIndex;
			else
				rightIndex = curIndex;
			curIndex = leftIndex + (rightIndex - leftIndex) / 2;
		}

		/*判断target在旋转数组的左半部分，还是右半部分*/
		if (target >= nums[0]) {
			leftIndex = 0;
			rightIndex = curIndex;
		}
		else {//target <= nums[n-1]
			leftIndex = curIndex + 1;
			rightIndex = n - 1;
		}

		/*利用二分查找法，在相应部分查找target*/
		curIndex = leftIndex + (rightIndex - leftIndex) / 2;
		while (leftIndex <= rightIndex) {
			if (nums[curIndex] == target)
				return curIndex;
			else if (nums[curIndex] < target)
				leftIndex = curIndex + 1;
			else
				rightIndex = curIndex - 1;
			curIndex = leftIndex + (rightIndex - leftIndex) / 2;
		}
		return -1;
	}
};