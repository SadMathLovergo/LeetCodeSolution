#include <vector>
using namespace std;

//第162题 寻找峰值
//解题思路：要求使用logN复杂度的算法
//由于nums[-1]与nums[n]均可视为无穷小，因为必然存在一个峰值
//取中间节点mid，若nums[mid]不为峰值，则
//若nums[mid-1]>nums[mid]，[0,mid-1]之间必然存在一个峰值
//若nums[mid]<nums[mid+1]，[mid+1,n]之间必然存在一个峰值
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		//若只有一个元素
		if (nums.size() == 1)
			return 0;
		//考虑边界元素
		if (nums[0] > nums[1])
			return 0;
		//考虑边界元素
		if (nums[nums.size() - 1] > nums[nums.size() - 2])
			return nums.size() - 1;

		int indexL = 0;
		int indexR = nums.size() - 1;
		int mid = 0;

		while (indexL < indexR) {
			mid = indexL + (indexR - indexL) / 2;
			if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
				return mid;
			else if (nums[mid] < nums[mid - 1])
				indexR = mid - 1;
			else if (nums[mid] < nums[mid + 1])
				indexL = mid + 1;
		}
		return indexL;
	}
};