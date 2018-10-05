#include <iostream>
#include <vector>
using namespace std;

/*第31题，下一个排列*/
/*解题思路：从右至左，寻找第一组相邻且非降序排列的数nums[i]和nums[i+1]*/
/*在nums[i]右边找到nums[i]的successor nums[k]，交换nums[i]和nums[k]*/
/*随后翻转nums[i]后的所有元素*/
/*若所有数都在正确位置上，则将数组反过来换成升序排列*/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		/*首先，从右至左寻找第一组非降序排列的数*/
		int firstIndex = nums.size() - 2;
		while (firstIndex >= 0 && nums[firstIndex] >= nums[firstIndex + 1])
			firstIndex--;

		/*如果整个数组都为降序排列，则将数组翻转*/
		if (firstIndex == -1) {
			int leftIndex = 0;
			int rightIndex = nums.size() - 1;

			while (leftIndex < rightIndex)
				swap(nums[leftIndex++], nums[rightIndex--]);

			return;
		}

		/*在nums[firstIndex]右边寻找nums[firstIndex]的successor，并交换*/
		int successor = firstIndex + 1;
		for (int i = firstIndex + 2;; i++) {
			if (i == nums.size() || nums[firstIndex] >= nums[i]) {
				successor = i - 1;
				break;
			}
		}

		swap(nums[firstIndex], nums[successor]);

		/*将nums[firstIndex]右边的元素翻转*/
		int leftIndex = firstIndex + 1;
		int rightIndex = nums.size() - 1;
		while (leftIndex < rightIndex)
			swap(nums[leftIndex++], nums[rightIndex--]);

		return;
	}
};

int main() {
	vector<int> nums{ 1,3,2 };
	Solution().nextPermutation(nums);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}