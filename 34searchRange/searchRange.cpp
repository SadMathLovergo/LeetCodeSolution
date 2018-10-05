#include <vector>
using namespace std;

/*��34�⣺�����������в���Ԫ�صĵ�һ�������һ��λ�ã�Ҫ��ʹ���㷨ʱ�临�Ӷ�ΪO(log n)����*/
/*����˼·���ҵ�target��ǰ������һ�������Լ���̵���һ������*/
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

		/*Ѱ��target��ǰ������һ������*/
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

		/*Ѱ��target�ĺ�̵���һ������*/
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