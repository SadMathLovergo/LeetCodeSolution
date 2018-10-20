#include <vector>
using namespace std;

//��153�⣺Ѱ����ת���������е���Сֵ
//����˼·����Ѱ����ת�����������ת�����˼·û������
class Solution {
public:
	int findMin(vector<int>& nums) {
		int leftIndex = 0;
		int rightIndex = nums.size() - 1;

		//������δ������ת����������ֻ��һ��Ԫ��
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