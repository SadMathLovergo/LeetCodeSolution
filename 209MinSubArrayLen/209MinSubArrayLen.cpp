#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int indexL = 0, indexR = -1;
		int sum = 0;
		int res = nums.size() + 1;
		while (indexL < nums.size())
		{
			if (indexR < (nums.size() - 1) && sum < s)
				sum += nums[++indexR];
			else
				sum -= nums[indexL++];
			if (sum >= s)
				res = min(res, indexR - indexL + 1);
		}
		if (res == nums.size() + 1)
			return 0;
		return res;
	}
};

int main() {
	Solution solution;
	vector<int> testArr{ 2,3,1,2,4,3 };
	int s = 7;
	int res = solution.minSubArrayLen(s, testArr);
	cout << res;
	system("pause");
	return 0;
}