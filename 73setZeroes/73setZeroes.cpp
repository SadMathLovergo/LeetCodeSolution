#include <vector>
using namespace std;

/*第73题 矩阵置零*/
class Solution {
private:
	/*将指定行置零*/
	void setRowZero(vector<vector<int>>& matrix, int Row) {
		for (int i = 0; i < matrix[0].size(); i++)
			matrix[Row][i] = 0;
	}

	/*将指定列置零*/
	void setColZero(vector<vector<int>>& matrix, int Col) {
		for (int i = 0; i < matrix.size(); i++)
			matrix[i][Col] = 0;
	}

public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;

		int m = matrix.size();
		int n = matrix[0].size();

		vector<bool> RowMemo(m, false);//记录行是否要被置为0，true为是，false为否
		vector<bool> ColMemo(n, false);//记录列是否要被置为0，true为是，false为否

		for(int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					RowMemo[i] = true;
					ColMemo[j] = true;
				}
			}

		for (int i = 0; i < m; i++)
			if (RowMemo[i])
				setRowZero(matrix, i);

		for (int i = 0; i < n; i++)
			if (ColMemo[i])
				setColZero(matrix, i);


	}
};