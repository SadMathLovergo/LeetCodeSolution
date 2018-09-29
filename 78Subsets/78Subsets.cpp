#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
	vector<vector<int>> resVec;
	vector<int> curVec;
	void findSubsets(vector<int>& nums, int curIndex) {
		resVec.push_back(curVec);
		for (int i = curIndex; i < nums.size(); i++) {
			curVec.push_back(nums[i]);
			findSubsets(nums, i + 1);
			curVec.pop_back();
		}
	}

public:
	vector<vector<int>> subsets(vector<int>& nums) {
		resVec.clear();
		curVec.clear();

		if (nums.empty())
			return resVec;

		findSubsets(nums, 0);
		return resVec;
	}
};