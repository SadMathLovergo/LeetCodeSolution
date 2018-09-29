#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> resVec;//保存最终结果
	vector<bool> visited;//保存遍历状态
	void doPermute(vector<int>& nums, vector<int>& curVec) {
		if (curVec.size() == nums.size()) {//若已经遍历完，则将curVec保存至resVec中
			resVec.push_back(curVec);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (!visited[i]) {//若没有使用过
				//递归回溯
				curVec.push_back(nums[i]);
				visited[i] = true;
				doPermute(nums, curVec);
				curVec.pop_back();
				visited[i] = false;
				//判断下一个遍历的数字是否和此数字相同
				while ( i < nums.size() - 1 && nums[i] == nums[i + 1])
					i++;
			}
		}
	}

public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.empty())
			return resVec;

		sort(nums.begin(), nums.end());
		visited = vector<bool>(nums.size(), false);
		vector<int> curVec;
		doPermute(nums, curVec);
		return resVec;
	}
};