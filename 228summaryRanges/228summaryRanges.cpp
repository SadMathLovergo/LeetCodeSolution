#include <string>
#include <vector>
using namespace std;

//第228题 汇总区间
//解题思路：
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> memo;
		int i = 0;
		while (i < nums.size()) {
			int j = i + 1;
			while (j < nums.size() && nums[j] - nums[j - 1] == 1)
				j++;
			//若只有一个数
			if (j - 1 == i)
				memo.push_back(to_string(nums[i]));
			else//若有多个数
				memo.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
			i = j;
		}
		return memo;
	}
};