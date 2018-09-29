#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> VecRes;
	void doCombine(int n, int k, int index, vector<int>& vec) {
		if (vec.size() == k) {
			VecRes.push_back(vec);
			return;
		}
		for (int i = index; i <= n; i++) {
			vec.push_back(i);
			doCombine(n, k, i + 1, vec);
			vec.pop_back();
		}
	}

public:
	vector<vector<int>> combine(int n, int k) {
		VecRes.clear();
		if (k > n || n == 0)
			return VecRes;

		vector<int> vec;
		doCombine(n, k, 1, vec);
		return VecRes;
	}
};