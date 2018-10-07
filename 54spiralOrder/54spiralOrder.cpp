#include <vector>
using namespace std;

/*第54题 螺旋矩阵*/
/*解题思路：一圈一圈遍历*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> resVec;
		if (matrix.empty())
			return resVec;

		int beginRow = 0;
		int endRow = matrix.size() - 1;
		int beginCol = 0;
		int endCol = matrix[0].size() - 1;

		while (beginRow < endRow && beginCol < endCol) {
			/*遍历上底*/
			for (int i = beginCol; i < endCol; i++)
				resVec.push_back(matrix[beginRow][i]);
			/*遍历右边*/
			for (int i = beginRow; i < endRow; i++)
				resVec.push_back(matrix[i][endCol]);
			/*遍历下底*/
			for (int i = endCol; i > beginCol; i--)
				resVec.push_back(matrix[endRow][i]);
			/*遍历左边*/
			for (int i = endRow; i > beginRow; i--)
				resVec.push_back(matrix[i][beginCol]);
			/*更新边界值*/
			beginRow++;
			endRow--;
			beginCol++;
			endCol--;
		}

		/*剩下一行未遍历*/
		if (beginRow == endRow) {
			for (int i = beginCol; i <= endCol; i++)
				resVec.push_back(matrix[beginRow][i]);
		}
		else if (beginCol == endCol) {/*剩下最后一列未遍历*/
			for (int i = beginRow; i <= endRow; i++)
				resVec.push_back(matrix[i][beginCol]);
		}

		return resVec;
	}
};