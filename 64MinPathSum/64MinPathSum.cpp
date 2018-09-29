#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;

		vector<int> memory(grid[0].size(), 0);
		memory[0] = grid[0][0];
		for (int i = 1; i < memory.size(); i++)
			memory[i] = memory[i - 1] + grid[0][i];

		for (int i = 1; i < grid.size(); i++) {
			memory[0] += grid[i][0];
			for (int j = 1; j < memory.size(); j++)
				memory[j] = min(memory[j - 1] + grid[i][j], memory[j] + grid[i][j]);
		}

		return memory[memory.size() - 1];

	}
};