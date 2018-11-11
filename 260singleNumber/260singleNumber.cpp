#include <vector>
using namespace std;

//第260题：只出现一次的数字3
//解题思路：使用逻辑位运算，相同的两个数异或为0
//找到所有数异或结果二进制中第一个1所在的索引，该索引为只出现一次的两个数二进制不相同的第一位
//将所有的数根据该索引是否为1分为两类，则两个只出现一次的数必然可以分别在不同的两类，分别对两类数进行异或，最终可以得到这两个数
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> res;
		if (nums.empty())
			return res;

		//所有数的异或结果为只出现一次的两个数的异或结果
		int XorRes = 0;
		for (int i = 0; i < nums.size(); i++)
			XorRes ^= nums[i];

		int firstIndex = 0;
		//找到异或结果中第一个1所在的索引，该索引为只出现一次的两个数二进制不相同的第一位
		for (int i = 0; i < 8 * sizeof(int); i++) {
			if (XorRes & 1 != 0)
				break;
			XorRes = XorRes >> 1;
			firstIndex++;
		}

		//将所有的数根据该索引位是否为1分为两类，则两个只出现一次的数必然可以分别在不同的两类，分别对两类数进行异或，最终可以得到这两个数
		int firstNum = 0;
		int secondNum = 0;
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] >> firstIndex & 1)
				firstNum ^= nums[i];
			else
				secondNum ^= nums[i];

		res.push_back(firstNum);
		res.push_back(secondNum);
		return res;
	}
};