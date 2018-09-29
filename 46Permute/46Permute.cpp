#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> VecRes;
	vector<bool> visited;
	void doPermute(vector<int>& nums, int index,vector<int> vec) {
		if (index == nums.size()) {
			VecRes.push_back(vec);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (!visited[i]) {
				visited[i] = true;
				vec.push_back(nums[i]);
				doPermute(nums, index + 1, vec);
				vec.pop_back();
				visited[i] = false;
			}
		}
	}

public:
	vector<vector<int>> permute(vector<int>& nums) {
		VecRes.clear();
		if (nums.empty())
			return VecRes;
		visited = vector<bool>(nums.size(), false);
		vector<int> vec;
		doPermute(nums, 0, vec);
		return VecRes;
	}
};