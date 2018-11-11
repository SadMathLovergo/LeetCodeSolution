#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//第187题 重复的DNA序列
//解题思路：位运算的妙用，利用位运算来区分字符串
//用"00"带代表A，用"01"带代表C，用"10"带代表G，用"11"带代表T
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<char, int> temp{ {'A',0},{ 'C',1 },{ 'G',2 },{ 'T',3 } };
		//记录已经存在的字符串对应的位运算结果
		unordered_set<int> memo;
		//保存重复的DNA序列字符串
		unordered_set<string> res;

		int num = 0;
		int i = 0;
		for (; i < 9; i++)//先将前9位的转换结果保存下来
			num = num << 2 | temp[s[i]];

		while (i < s.size()) {
			//每次计算新的字符串转换结果，只需把前2位去掉，把后18位左移两位，然后将下一个字符对应的数值添加至末尾即可
			num = ((num & 0x3ffff) << 2) | temp[s[i++]];
			if (memo.find(num) == memo.end())
				memo.insert(num);
			else
				res.insert(s.substr(i - 10, 10));
		}

		return vector<string>(res.begin(), res.end());
	}
};