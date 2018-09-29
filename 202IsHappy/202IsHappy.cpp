#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> record;
		int oriNum;
		int resultNum = n;
		while (resultNum != 1) {
			/*将上一次计算结果放入表中*/
			record.insert(resultNum);
			/*以上一次计算结果作为这一次计算的原数字*/
			oriNum = resultNum;
			resultNum = 0;
			/*计算结果*/
			while (oriNum != 0) {
				resultNum += pow(oriNum % 10, 2);
				oriNum /= 10;
			}
			/*出现循环，则判定为非乐观数*/
			if (record.find(resultNum) != record.end())
				return false;
		}
		/*判定为乐观数*/
		return true;
	}
};