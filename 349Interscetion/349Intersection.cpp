#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> numset1;
		for (int i = 0; i < nums1.size(); i++)
			numset1.insert(nums1[i]);

		set<int> numset2;
		for (int i = 0; i < nums2.size(); i++)
			if (numset1.find(nums2[i]) != numset1.end())
				numset2.insert(nums2[i]);

		vector<int> result;
		for (set<int>::iterator iter = numset2.begin(); iter != numset2.end(); iter++)
			result.push_back(*iter);

		return result;
	}
};

int main() {
	Solution solution;
	vector<int> nums1{ 1,2,2,1 };
	vector<int> nums2{ 2,2 };
	vector<int> nums3 = solution.intersection(nums1, nums2);
	for (vector<int>::iterator iter = nums3.begin(); iter != nums3.end(); iter++)
		cout << *iter << " ";

	system("pause");
	return 0;
}