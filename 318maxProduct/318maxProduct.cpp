#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//第318题 最大单词长度乘积
//解题的关键在于，如何判断两个字符串是否有公共字母
class Solution {
public:
	int maxProduct(vector<string>& words) {
		vector<int> record(words.size(), 0);
		int res = 0;

		for (int i = 0; i < words.size(); i++)
			for (auto ch : words[i])
				record[i] |= 1 << (ch - 'a');


		for(int i = 0; i < words.size(); i++)
			for (int j = i + 1; j < words.size(); j++) {
				if (!(record[i] & record[j]))
					res = max(res, (int)(words[i].length() * words[j].length()));
			}

		return res;
	}
};