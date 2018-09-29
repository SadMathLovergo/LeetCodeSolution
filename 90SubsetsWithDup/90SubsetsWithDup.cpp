#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> resVec;
	vector<int> curVec;
	void findSubsetsWithDup(vector<int>& nums, int curIndex) {
		resVec.push_back(curVec);
		for (int i = curIndex; i < nums.size(); i++) {
			curVec.push_back(nums[i]);
			findSubsetsWithDup(nums, i + 1);
			curVec.pop_back();
			while (i < nums.size() - 1 && nums[i] == nums[i + 1])
				i++;
		}
	}
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		resVec.clear();
		curVec.clear();

		if (nums.empty())
			return resVec;

		sort(nums.begin(), nums.end());
		findSubsetsWithDup(nums, 0);

		return resVec;
	}
};