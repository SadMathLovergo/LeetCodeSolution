#include <vector>
#include <iostream>
using namespace std;

//第137题 只出现一次的数字2
//解题思路：利用逻辑位运算的思路
//统计每一位上1出现的次数
//若只出现依次的数字在这一位是1，则这一位上1出现的次数对3取余会余1
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int> bitMemo(32, 0);
		int res = 0;

		for (auto num : nums) //遍历每一个数
			for (int i = 0; i < 32; i++) //从低位到高位
				bitMemo[i] = (bitMemo[i] + ((num >> i) & 1)) % 3;

		for (int i = 0; i < 32; i++)
			res = res | (bitMemo[i] << i);

		return res;
	}
};

int main() {
	vector<int> nums{ 2,2,3,2 };
	int res = Solution().singleNumber(nums);
	cout << res << endl;
	system("pause");
	return 0;
}