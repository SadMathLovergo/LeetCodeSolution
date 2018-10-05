#include <iostream>
#include <vector>
using namespace std;

/*��31�⣬��һ������*/
/*����˼·����������Ѱ�ҵ�һ�������ҷǽ������е���nums[i]��nums[i+1]*/
/*��nums[i]�ұ��ҵ�nums[i]��successor nums[k]������nums[i]��nums[k]*/
/*���תnums[i]�������Ԫ��*/
/*��������������ȷλ���ϣ������鷴����������������*/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		/*���ȣ���������Ѱ�ҵ�һ��ǽ������е���*/
		int firstIndex = nums.size() - 2;
		while (firstIndex >= 0 && nums[firstIndex] >= nums[firstIndex + 1])
			firstIndex--;

		/*����������鶼Ϊ�������У������鷭ת*/
		if (firstIndex == -1) {
			int leftIndex = 0;
			int rightIndex = nums.size() - 1;

			while (leftIndex < rightIndex)
				swap(nums[leftIndex++], nums[rightIndex--]);

			return;
		}

		/*��nums[firstIndex]�ұ�Ѱ��nums[firstIndex]��successor��������*/
		int successor = firstIndex + 1;
		for (int i = firstIndex + 2;; i++) {
			if (i == nums.size() || nums[firstIndex] >= nums[i]) {
				successor = i - 1;
				break;
			}
		}

		swap(nums[firstIndex], nums[successor]);

		/*��nums[firstIndex]�ұߵ�Ԫ�ط�ת*/
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