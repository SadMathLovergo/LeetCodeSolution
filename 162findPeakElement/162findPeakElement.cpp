#include <vector>
using namespace std;

//��162�� Ѱ�ҷ�ֵ
//����˼·��Ҫ��ʹ��logN���Ӷȵ��㷨
//����nums[-1]��nums[n]������Ϊ����С����Ϊ��Ȼ����һ����ֵ
//ȡ�м�ڵ�mid����nums[mid]��Ϊ��ֵ����
//��nums[mid-1]>nums[mid]��[0,mid-1]֮���Ȼ����һ����ֵ
//��nums[mid]<nums[mid+1]��[mid+1,n]֮���Ȼ����һ����ֵ
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		//��ֻ��һ��Ԫ��
		if (nums.size() == 1)
			return 0;
		//���Ǳ߽�Ԫ��
		if (nums[0] > nums[1])
			return 0;
		//���Ǳ߽�Ԫ��
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