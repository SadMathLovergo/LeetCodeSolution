#include <vector>
#include <algorithm>
using namespace std;

/*��81�� ������ת��������2*/
/*���������д����ظ�Ԫ�أ���������Ŀ��Ҫ���������*/
class Solution {
private:
	//���õݹ�ķ���Ѱ����ת�㣬��nums[indexL] = nums[indexR]ʱ
	int findRotate(int indexL, int indexR, vector<int>& nums) {
		if (indexL >= indexR - 1)
			return -1;
		int indexM = indexL + (indexR - indexL) / 2;

		//���м�Ԫ���������߽�Ԫ�����
		if (nums[indexL] == nums[indexM])
			return max(findRotate(indexL, indexM, nums), findRotate(indexM, indexR, nums));

		//������ȣ�����[indexL,indexR]�б�Ȼ������ת�㣬Ѱ�Ҵ���ת��
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

		/*������δ������ת�����ڿ��ܴ����ظ�Ԫ�أ�����ֻ��<����<=�������޷��ж��Ƿ�δ������ת*/
		/*ʹ�ö��ֲ��ҷ�����target*/
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
		else if(nums[0] > nums[n - 1]){//��nums[0] > nums[n-1]��������һ����������ת��
			/*��target��(nums[n-1],nums[0])֮�䣬�������в�����target*/
			if (target < nums[0] && target > nums[n - 1])
				return false;

			/*�ҵ���ת�������ת��*/
			while (!(nums[curIndex] >= nums[0] && nums[curIndex + 1] <= nums[n - 1])) {
				if (nums[curIndex] >= nums[0])
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
					return true;
				else if (nums[curIndex] < target)
					leftIndex = curIndex + 1;
				else
					rightIndex = curIndex - 1;
				curIndex = leftIndex + (rightIndex - leftIndex) / 2;
			}
			return false;
		}
		else {//��nums[0] = nums[n-1]�����������д����ظ�Ԫ�أ���������������1.�������ظ�Ԫ�ش���������ת 2.������������Ԫ�ض���ͬ
			/*ʹ�õݹ鷽ʽ�ҵ���ת�������ת��*/
			curIndex = findRotate(0, n - 1, nums);
			//��������������Ԫ�ض���ȣ����ж��Ƿ�Ϊtarget
			if (curIndex == -1)
				return nums[leftIndex] == target;
			
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