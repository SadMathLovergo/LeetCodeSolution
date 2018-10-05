#include <vector>
using namespace std;

/*��33�� ������ת��������*/
/*Ҫ��ʹ��log n������㷨�����Ե�һ��Ӧʹ�ö��ֲ��ҷ�*/
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

		/*������δ��ת��Ϊ�������飬���ö��ֲ��ҷ�*/
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
		
		/*�������������ת�����*/
		/*��target��(nums[0],nums[n-1])֮�䣬�������в�����target*/
		if (target < nums[leftIndex] && target > nums[rightIndex])
			return -1;
		/*�ҵ���ת�������ת��*/
		while (!(nums[curIndex] >= nums[0] && nums[curIndex + 1] <= nums[n - 1])) {
			if (nums[curIndex] > nums[0])
				leftIndex = curIndex;
			else
				rightIndex = curIndex;
			curIndex = leftIndex + (rightIndex - leftIndex) / 2;
		}

		/*�ж�target����ת�������벿�֣������Ұ벿��*/
		if (target >= nums[0]) {
			leftIndex = 0;
			rightIndex = curIndex;
		}
		else {//target <= nums[n-1]
			leftIndex = curIndex + 1;
			rightIndex = n - 1;
		}

		/*���ö��ֲ��ҷ�������Ӧ���ֲ���target*/
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