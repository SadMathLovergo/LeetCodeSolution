#include <vector>
#include <algorithm>
using namespace std;

/*第81题 搜索旋转排序数组2*/
/*由于数组中存在重复元素，因此这道题目需要分情况讨论*/
class Solution {
private:
	//采用递归的方法寻找旋转点，当nums[indexL] = nums[indexR]时
	int findRotate(int indexL, int indexR, vector<int>& nums) {
		if (indexL >= indexR - 1)
			return -1;
		int indexM = indexL + (indexR - indexL) / 2;

		//若中间元素与两个边界元素相等
		if (nums[indexL] == nums[indexM])
			return max(findRotate(indexL, indexM, nums), findRotate(indexM, indexR, nums));

		//若不相等，则在[indexL,indexR]中必然存在旋转点，寻找此旋转点
		while (indexL < indexR) {
			if (nums[indexM] >= nums[indexL] && nums[indexM + 1] <= nums[indexR])
				return indexM;
			if (nums[indexM] >= nums[indexL])
				indexL = indexM;
			else
				indexR = indexM;
			indexM = indexL + (indexR - indexL) / 2;
		}
		return indexM;
	}
public:
	bool search(vector<int>& nums, int target) {
		int n = nums.size();

		if (n == 0)
			return false;
		if (n == 1)
			return nums[0] == target;

		int leftIndex = 0;
		int rightIndex = n - 1;
		int curIndex = leftIndex + (rightIndex - leftIndex) / 2;

		/*若数组未经过旋转，由于可能存在重复元素，所以只能<不能<=，否则无法判断是否未经过旋转*/
		/*使用二分查找法搜索target*/
		if (nums[0] < nums[n - 1]) {
			while (leftIndex <= rightIndex) {
				if (target < nums[curIndex])
					rightIndex = curIndex - 1;
				else if (target > nums[curIndex])
					leftIndex = curIndex + 1;
				else
					return true;
				curIndex = leftIndex + (rightIndex - leftIndex) / 2;
			}
			return false;
		}
		else if(nums[0] > nums[n - 1]){//若nums[0] > nums[n-1]，则数组一定发生了旋转；
			/*若target在(nums[n-1],nums[0])之间，则数组中不存在target*/
			if (target < nums[0] && target > nums[n - 1])
				return false;

			/*找到旋转数组的旋转点*/
			while (!(nums[curIndex] >= nums[0] && nums[curIndex + 1] <= nums[n - 1])) {
				if (nums[curIndex] >= nums[0])
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
					return true;
				else if (nums[curIndex] < target)
					leftIndex = curIndex + 1;
				else
					rightIndex = curIndex - 1;
				curIndex = leftIndex + (rightIndex - leftIndex) / 2;
			}
			return false;
		}
		else {//若nums[0] = nums[n-1]，由于数组中存在重复元素，因此有两种情况：1.数组在重复元素处发生了旋转 2.整个数组所有元素都相同
			/*使用递归方式找到旋转数组的旋转点*/
			curIndex = findRotate(0, n - 1, nums);
			//若整个数组所有元素都相等，则判断是否为target
			if (curIndex == -1)
				return nums[leftIndex] == target;
			
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
					return true;
				else if (nums[curIndex] < target)
					leftIndex = curIndex + 1;
				else
					rightIndex = curIndex - 1;
				curIndex = leftIndex + (rightIndex - leftIndex) / 2;
			}
			return false;
		}
	}
};