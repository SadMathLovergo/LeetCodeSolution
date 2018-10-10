#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> memo(n, vector<int>(n, 0));
		int num = 1;

		int StartRow = 0;
		int EndRow = n - 1;
		int StartCol = 0;
		int EndCol = n - 1;

		while (StartRow < EndRow) {
			/*±éÀúÉÏµ×*/
			for (int i = StartCol; i < EndCol; i++)
				memo[StartRow][i] = num++;
			/*±éÀúÓÒ±ß*/
			for (int i = StartRow; i < EndRow; i++)
				memo[i][EndCol] = num++;
			/*±éÀúÏÂµ×*/
			for (int i = EndCol; i > StartCol; i--)
				memo[EndRow][i] = num++;
			/*±éÀú×ó±ß*/
			for (int i = EndRow; i > StartRow; i--)
				memo[i][StartCol] = num++;

			StartRow++;
			EndRow--;
			StartCol++;
			EndCol--;
		}

		if (StartRow == EndRow)
			memo[StartRow][StartCol] = num;

		return memo;
	}
};