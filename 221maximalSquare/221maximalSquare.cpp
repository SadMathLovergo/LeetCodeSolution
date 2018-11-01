#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

//第221题 最大正方形
//解题思路：遍历每一条对角线的点，从最长的对角线开始遍历
class Solution {
private:
	int RowSize, ColSize;
	//找到以matrix[rowIndex][colIndex]为左上角顶点的只包含1的最大正方形的边长
	int findMaximalSquare(int rowIndex, int colIndex, vector<vector<char>>& matrix) {
		if (matrix[rowIndex][colIndex] == '0')
			return 0;
		int i = 1;
		for (; rowIndex + i < RowSize && colIndex + i < ColSize; i++) {
			bool isNormalSquare = true;
			for (int j = 0; j <= i; j++)
				if (matrix[rowIndex + i][colIndex + j] == '0' || matrix[rowIndex + j][colIndex + i] == '0') {
					isNormalSquare = false;
					break;
				}
			if (!isNormalSquare)
				break;
		}
		return i;
	}

public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		RowSize = matrix.size();
		ColSize = matrix[0].size();

		int Ret = 0;
		
		if (RowSize < ColSize) {
			//遍历ColSize-RowSize+1条最长的对角线，第i条对角线
			for (int i = 0; i <= ColSize - RowSize; i++) {
				//第i条对角线，第j个点
				for (int j = 0; j < RowSize; j++) {
					Ret = max(Ret, findMaximalSquare(j, i + j, matrix));
					if (Ret >= RowSize - j - 1)
						break;
				}
			}
			//遍历两边剩下的RowSize-1条对角线
			for (int i = 1; i < RowSize; i++) {
				for (int j = 0; j < RowSize - i; j++) {
					Ret = max(Ret, findMaximalSquare(i + j, j, matrix));
					Ret = max(Ret, findMaximalSquare(j, ColSize - RowSize + i + j, matrix));
					if (Ret >= RowSize - i - j - 1)
						break;
				}
			}

			return pow(Ret, 2);
		}
		else {
			//遍历RowSize-ColSize+1条最长的对角线，第i条对角线
			for (int i = 0; i <= RowSize - ColSize; i++) {
				//第i条对角线，第j个点
				for (int j = 0; j < ColSize; j++) {
					Ret = max(Ret, findMaximalSquare(i + j, j, matrix));
					if (Ret >= ColSize - j - 1)
						break;
				}
			}
			//遍历两边剩下的ColSize-1条对角线
			for (int i = 1; i < ColSize; i++) {
				for (int j = 0; j < ColSize - i; j++) {
					Ret = max(Ret, findMaximalSquare(j, i + j, matrix));
					Ret = max(Ret, findMaximalSquare(RowSize - ColSize + i + j, j, matrix));
					if (Ret >= ColSize - i - j - 1)
						break;
				}
			}

			return pow(Ret, 2);
		}
		
	}
};

int main() {
	vector<vector<char>> matrix;
	matrix.push_back(vector<char>{'1', '0', '1', '0', '0'});
	matrix.push_back(vector<char>{'1', '0', '1', '1', '1'});
	matrix.push_back(vector<char>{'1', '1', '1', '1', '1'});
	matrix.push_back(vector<char>{'1', '0', '0', '1', '0'});
	int ret = Solution().maximalSquare(matrix);
	cout << ret << endl;
	system("pause");
	return 0;
}