#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//第179题 最大数
//解题思路：先排序，按照排序结果构建字符串
bool compare(int num1, int num2) {
	string str1 = to_string(num1);
	string str2 = to_string(num2);
	int index1 = 0;
	int index2 = 0;
	while (str1[index1] == str2[index2]) {
		index1++;
		index2++;
		//若都已经读完，则表示两个字符串相等，
		if (index1 == str1.length() && index2 == str2.length())
			return true;
		//若字符串str1已经读完，则从头开始
		else if (index1 == str1.length())
			index1 = 0;
		//若字符串str2已经读完，则从头开始
		else if (index2 == str2.length())
			index2 = 0;
	}
	return str1[index1] >= str2[index2];
}

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector<int> zeroNums;
		vector<int> nonZeroNums;

		for (int i = 0; i < nums.size(); i++)
			if (nums[i] == 0)
				zeroNums.push_back(nums[i]);
			else
				nonZeroNums.push_back(nums[i]);

		if (nonZeroNums.empty())
			return "0";

		sort(nonZeroNums.begin(), nonZeroNums.end(), compare);
		string res;

		for (int i = 0; i < nonZeroNums.size(); i++)
			res += to_string(nonZeroNums[i]);
		for (int i = 0; i < zeroNums.size(); i++)
			res += to_string(zeroNums[i]);

		return res;
	}
};

int main() {
	vector<int> vec{ 
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 
	};
	string ret = Solution().largestNumber(vec);
	cout << ret << endl;
	system("pause");
	return 0;
}