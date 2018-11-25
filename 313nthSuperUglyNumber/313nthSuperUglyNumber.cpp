#pragma once
#include <vector>
#include <algorithm>
using namespace std;

//第313题 超级丑数
//解题思路：与第264题基本一致
class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		if (n == 0)
			return 0;

		vector<int> res;
		res.push_back(1);

		vector<int> indexRecord(primes.size(), 0);
		for (int i = 1; i < n; i++) {
			int temp = INT_MAX;
			for (int j = 0; j < primes.size(); j++)
				temp = min(temp, res[indexRecord[j]] * primes[j]);
			for (int j = 0; j < primes.size(); j++)
				if (temp == res[indexRecord[j]] * primes[j])
					indexRecord[j]++;
			res.push_back(temp);
		}

		return res.back();
	}
};