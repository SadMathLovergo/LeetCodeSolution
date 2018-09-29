#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}
		if (S > sum || S + sum < 0)
			return 0;

		vector<vector<int>> memory(2, vector<int>(2 * sum + 1, 0));
		memory[0][0] = 1;
		memory[1][0] = 1;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j <= 2 * sum; j++) {
				if (memory[0][j])
					memory[1][j + nums[i] * 2] += memory[0][j];
			}

			for (int k = 0; k <= 2 * sum; k++)
				memory[0][k] = memory[1][k];
		}

		return memory[0][S + sum];
	}
};

int main() {
	vector<int> nums{ 1,1,1,1,1 };
	int S = 3;
	int res = Solution().findTargetSumWays(nums, S);
	cout << res << endl;

	system("pause");
	return 0;
}