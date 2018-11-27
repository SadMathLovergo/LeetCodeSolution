#pragma once
#include <algorithm>
using namespace std;

//第319题 灯泡开关
//解题思路：每个数的因子的个数为转换次数
//因子个数为奇数的数，会转换奇数次状态，最后为亮着的状态
//除了平方数，任何数的因子数都为偶数
//因此，只有完全平方数最后是亮着的状态
class Solution {
public:
	int bulbSwitch(int n) {
		return (int)sqrt(n);
	}
};