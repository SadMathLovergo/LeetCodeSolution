#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;

		if (nums.size() < 4)
			return result;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 3; i++) {
			for (int j = i + 1; j < nums.size() - 2; j++) {
				for (int m = j + 1, n = nums.size() - 1; m < n;) {

					int sum = nums[i] + nums[j] + nums[m] + nums[n];
					if (sum == target) {
						result.push_back(vector<int>{nums[i], nums[j], nums[m], nums[n]});
						while (m < nums.size() && nums[m] == nums[m + 1])
							m++;
						m++;
						while (n > j && nums[n] == nums[n - 1])
							n--;
						n--;
					}
					else if (sum < target)
						m++;
					else
						n--;
				}
				while (j < nums.size() - 2 && nums[j] == nums[j + 1])
					j++;
			}
			while (i < nums.size() - 3 && nums[i] == nums[i + 1])
				i++;
		}

		return result;
	}
};

int main() {
	vector<int> nums{ -3,-2,-1,0,0,1,2,3 };
	int target = 0;
	vector<vector<int>> result = Solution().fourSum(nums, target);
	for (int i = 0; i < result.size(); i++) {
		cout << "[";
		for (int j = 0; j < result[i].size() - 1; j++)
			cout << result[i][j]<<",";
		cout << result[i][result[i].size() - 1];
		cout << "]";
		cout << endl;
	}

	system("pause");
	return 0;
}