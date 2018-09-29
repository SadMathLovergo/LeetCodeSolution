#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m == 0 || n == 0)
			return 0;
		vector<int> memory(n, 1);
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				memory[j] = memory[j] + memory[j - 1];
			}
		}
		return memory[n - 1];
	}
};