#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int curIndex = m + n - 1;
		int mIndex = m - 1;
		int nIndex = n - 1;

		while (mIndex >= 0 && nIndex >= 0) {
			if (nums1[mIndex] > nums2[nIndex]) {
				nums1[curIndex] = nums1[mIndex];
				mIndex--;
				curIndex--;
			}
			else
			{
				nums1[curIndex] = nums2[nIndex];
				nIndex--;
				curIndex--;
			}
		}

		while (mIndex >= 0) {
			nums1[curIndex] = nums1[mIndex];
			curIndex--;
			mIndex--;
		}

		while (nIndex >= 0) {
			nums1[curIndex] = nums2[nIndex];
			curIndex--;
			nIndex--;
		}
	}
};

int main() {
	vector<int> nums1 = { 1,2,3,4,0,0,0 };
	vector<int> nums2 = { 5,6,7 };
	Solution solution;
	solution.merge(nums1, 4, nums2, 3);
	for (vector<int>::iterator iter = nums1.begin(); iter != nums1.end(); iter++) {
		cout << *iter << " ";
	}

	system("pause");
	return 0;
}