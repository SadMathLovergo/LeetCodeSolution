#pragma once
#include <vector>
using namespace std;

//第304题 二维区域和检索-检索不可变
//解题思路：动态规划
class NumMatrix {
private:
	vector<vector<int>> memo;

public:
	NumMatrix(vector<vector<int>> matrix) {
		if (matrix.empty() || matrix[0].empty())
			return;

		memo = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
		memo[0][0] = matrix[0][0];

		for (size_t i = 1; i < matrix[0].size(); i++)
			memo[0][i] = memo[0][i - 1] + matrix[0][i];
		for (size_t i = 1; i < matrix.size(); i++)
			memo[i][0] = memo[i - 1][0] + matrix[i][0];

		for (size_t i = 1; i < matrix.size(); i++)
			for (size_t j = 1; j < matrix[0].size(); j++)
				memo[i][j] = memo[i][j - 1] + memo[i - 1][j] + matrix[i][j] - memo[i - 1][j - 1];
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (row1 == 0 && col1 == 0)
			return memo[row2][col2];
		if (row1 == 0)
			return memo[row2][col2] - memo[row2][col1 - 1];
		if (col1 == 0)
			return memo[row2][col2] - memo[row1 - 1][col2];
		return memo[row2][col2] - memo[row2][col1 - 1] - memo[row1 - 1][col2] + memo[row1 - 1][col1 - 1];
	}
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* int param_1 = obj.sumRegion(row1,col1,row2,col2);
*/