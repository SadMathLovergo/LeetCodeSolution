#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		vector<int> memory(n + 1, -1);
		memory[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i - 1; j++) {
				memory[i] = max(memory[i], max(j*(i - j), j*memory[i - j]));
			}
		}
		return memory[n];
	}
};