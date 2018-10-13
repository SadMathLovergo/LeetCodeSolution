#include <vector>
using namespace std;

/*第74题 探索二维矩阵*/
/*解题思路：*/
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int RowSize = matrix.size();
		if (RowSize == 0)
			return false;
		int ColSize = matrix[0].size();
		if (ColSize == 0)
			return false;

		if (target < matrix[0][0] || target > matrix[RowSize - 1][ColSize - 1])
			return false;

		int leftIndex = 0;
		int rightIndex = RowSize - 1;
		int curRow = leftIndex + (rightIndex - leftIndex) / 2;

		/*找到target所在行,target所在行的第一个元素小于等于target，下一行的元素大于target*/
		while (leftIndex < rightIndex) {
			curRow = leftIndex + (rightIndex - leftIndex) / 2;
			if (target < matrix[curRow][0])
				rightIndex = curRow - 1;
			else if (target > matrix[curRow][0]) {
				if (target >= matrix[curRow + 1][0])
					leftIndex = curRow + 1;
				else {
					leftIndex = curRow;
					break;
				}
			}
			else
				return true;
		}

		curRow = leftIndex;

		leftIndex = 0;
		rightIndex = ColSize - 1;
		int curCol = leftIndex + (rightIndex - leftIndex) / 2;

		/*target在此行是否存在*/
		while (leftIndex <= rightIndex) {
			curCol = leftIndex + (rightIndex - leftIndex) / 2;
			if (target < matrix[curRow][curCol])
				rightIndex = curCol - 1;
			else if (target > matrix[curRow][curCol])
				leftIndex = curCol + 1;
			else
				return true;
		}

		return false;
	}
};