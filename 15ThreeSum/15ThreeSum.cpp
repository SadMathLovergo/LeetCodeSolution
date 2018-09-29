#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size() < 3)
			return result;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 2; i++) {
			if (i >= 1 && nums[i] == nums[i - 1])
				continue;
			for (int m = i + 1, n = nums.size() - 1; m < n;) {
				int sum = nums[i] + nums[m] + nums[n];
				if (sum == 0) {
					result.push_back(vector<int>{nums[i], nums[m], nums[n]});
					m++;
					while (m + 1 < nums.size() && nums[m] == nums[m - 1])
						m++;
					n--;
					while (n - 1 > i && nums[n] == nums[n + 1])
						n--;
				}
				else if (sum > 0)
					n--;
				else
					m++;
			}
		}

		return result;
	}
};