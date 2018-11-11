#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//第264题：丑数2
//解题思路：每一个丑数必然是用更小的一个丑数乘2、3、5，最小的丑数为1，问题的关键在于如何保持丑数的有序性
//利用动态规划的方法来进行计算，每一个丑数乘2、3、5都可以得到一个新的丑数
//设定三个索引index2、index3、index5，index2为可以乘以2的第一个丑数，index3为可以乘以3的第一个丑数，index5为可以乘以5的第一个丑数
//第n个丑数为前n-1个丑数中的某三个丑数分别乘2、3、5得到的数的最小数
//每一次循环至少更新一个数
class Solution {
public:
	int nthUglyNumber(int n) {
		if (n == 0)
			return 0;

		vector<int> res;
		res.push_back(1);
		
		int index2 = 0;
		int index3 = 0;
		int index5 = 0;

		for (int i = 1; i < n; i++) {
			int num = min(res[index2] * 2, min(res[index3] * 3, res[index5] * 5));
			res.push_back(num);
			if (num == res[index2] * 2)
				index2++;
			if (num == res[index3] * 3)
				index3++;
			if (num == res[index5] * 5)
				index5++;
		}

		return res.back();
	}
};