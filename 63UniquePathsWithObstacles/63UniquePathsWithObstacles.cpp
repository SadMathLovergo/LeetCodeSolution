#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty())
			return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> memory(m, vector<int>(n, 0));

		if (obstacleGrid[0][0] == 1)
			return 0;

		int k = 0;
		for(int i = 0 ; i < n ; i++)
			if (obstacleGrid[0][i] == 1) {
				k = i;
				break;
			}
		if (k != 0) {
			for (int i = 0; i < k; i++)
				memory[0][i] = 1;
			for (int i = k; i < n; i++)
				memory[0][i] = 0;
		}
		else
			memory[0] = vector<int>(n, 1);

		k = 0;
		for (int i = 0; i < m; i++)
			if (obstacleGrid[i][0] == 1) {
				k = i;
				break;
			}
		if (k != 0) {
			for (int i = 0; i < k; i++)
				memory[i][0] = 1;
			for (int i = k; i < m; i++)
				memory[i][0] = 0;
		}
		else {
			for (int i = 0; i < m; i++)
				memory[i][0] = 1;
		}

		for(int i = 1; i < m ; i++)
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 0)
					memory[i][j] = memory[i][j - 1] + memory[i - 1][j];
			}

		return memory[m - 1][n - 1];
	}
};