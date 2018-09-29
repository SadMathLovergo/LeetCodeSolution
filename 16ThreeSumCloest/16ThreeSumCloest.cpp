#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
private:
	int absMin(int num1, int num2) {
		if (abs(num1) <= abs(num2))
			return num1;
		return num2;
	}

public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<int> memory;

		for (int i = 0; i < nums.size() - 2; i++) {
			int m = i + 1;
			int n = nums.size() - 1;
			int dif = nums[i] + nums[m] + nums[n] - target;
			int res = nums[i] + nums[m] + nums[n] - target;
			while(true) {
				if (res == 0)
					return target;
				else if (res < 0) {
					m++;
				}
				else
					n--;
				if (m >= n)
					break;
				res = nums[i] + nums[m] + nums[n] - target;
				dif = absMin(dif, res);
			}
			memory.push_back(dif);
		}

		int res = memory[0];
		for (int i = 1; i < memory.size(); i++)
			res = absMin(res, memory[i]);

		return target + res;
	}
};

int main() {
	vector<int> nums{ 4,0,5,-5,3,3,0,-4,-5 };
	int target = -2;
	int res = Solution().threeSumClosest(nums, target);
	cout << res << endl;
	system("pause");
	return 0;
}