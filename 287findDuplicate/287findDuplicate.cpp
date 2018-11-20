#pragma once
#include <vector>
using namespace std;

//第287题：寻找重复数
//解题思路：利用二分查找法
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int begin = 1;
		int end = nums.size() - 1;
		int medium = 0;

		while (begin < end) {
			medium = begin + (end - begin) / 2;

			int CountNumber = 0;

			for (auto num : nums)
				if (num <= medium)
					CountNumber++;

			if (CountNumber > medium)
				end = medium;
			else
				begin = medium + 1;
		}

		return begin;
	}
};