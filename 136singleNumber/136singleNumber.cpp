#include <vector>
using namespace std;

//第136题 只出现一次的数字
//解题思路：利用逻辑运算符 异或
//任何两个相同的数进行异或运算得到的都是0
//任何数和0进行异或运算，得到的都是本身
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (auto num : nums)
			res ^= num;
		return res;
	}
};