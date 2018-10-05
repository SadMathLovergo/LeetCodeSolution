#include <vector>
#include <queue>
using namespace std;

/*第48题，旋转图像*/
/*解题思路：从外向内，一层一层进行顺时针旋转*/
/*对第i层进行旋转时，每次旋转一格，总共旋转(n - 2*i + 1)次*/
/*每次遍历时，逆时针方向对元素进行遍历*/
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;

		int n = matrix.size();
		/*nxn的矩阵，总共有n/2层，只有一个元素的最内层不算*/
		int circleNum = n / 2;

		/*对第i层进行遍历，每一层的每一条边有(n - 2*i + 2)个元素*/
		for (int i = 1; i <= circleNum; i++) {
			/*对每一层进行第j次旋转*/
			for (int j = 0; j < (n - 2 * i + 1); j++) {
				/*保存每一层的左上角元素*/
				int temp = matrix[i - 1][i - 1];
				/*对左边进行旋转*/
				for (int k = i - 1; k < n - i; k++)
					matrix[k][i - 1] = matrix[k + 1][i - 1];
				/*对下边进行旋转*/
				for (int k = i - 1; k < n - i; k++)
					matrix[n - i][k] = matrix[n - i][k + 1];
				/*对右边进行旋转*/
				for (int k = n - i; k > i - 1; k--)
					matrix[k][n - i] = matrix[k - 1][n - i];
				/*对上边进行旋转*/
				for (int k = n - i; k > i - 1; k--)
					matrix[i - 1][k] = matrix[i - 1][k - 1];
				/*更新最后一个元素*/
				matrix[i - 1][i] = temp;
			}
		}

	}
};