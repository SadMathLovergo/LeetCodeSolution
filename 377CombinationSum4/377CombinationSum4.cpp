#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> memory(target + 1, 0);
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] <= target)
				memory[nums[i]] = 1;

		for (int i = 0; i <= target; i++) {
			if (memory[i] != 0) {
				for (int j = 0; j < nums.size(); j++) {
					if (i + nums[j] <= target)
						memory[i + nums[j]]+=memory[i];
				}
			}
		}
		return memory[target];
	}
};

int main() {
	vector<int> nums{ 1,2,3 };
	int target = 4;
	int res = Solution().combinationSum4(nums, target);
	cout << res << endl;
	system("pause");
	return 0;
}