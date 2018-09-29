#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	vector<bool> Column;
	vector<bool> Diagonal;
	vector<bool> ClinoDiagonal;

	vector<vector<string>> Result;

	void findNQueens(int RowIndex, int n, vector<string>& VecStr) {
		if (RowIndex == n) {
			Result.push_back(VecStr);
			return;
		}

		for (int ColumnIndex = 0; ColumnIndex < n; ColumnIndex++) {

			if (!Column[ColumnIndex] && !Diagonal[RowIndex - ColumnIndex + n - 1] && !ClinoDiagonal[RowIndex + ColumnIndex]) {

				Column[ColumnIndex] = true;
				Diagonal[RowIndex - ColumnIndex + n - 1] = true;
				ClinoDiagonal[RowIndex + ColumnIndex] = true;

				string str = "";
				for (int i = 0; i < n; i++) {
					if (i == ColumnIndex)
						str += 'Q';
					else
						str += '.';
				}
				VecStr.push_back(str);

				findNQueens(RowIndex + 1, n, VecStr);

				Column[ColumnIndex] = false;
				Diagonal[RowIndex - ColumnIndex + n - 1] = false;
				ClinoDiagonal[RowIndex + ColumnIndex] = false;
				VecStr.pop_back();
			}


		}
	}

public:
	vector<vector<string>> solveNQueens(int n) {
		if (n == 0)
			return Result;
		Result.clear();

		Column = vector<bool>(n, false);
		Diagonal = vector<bool>(2 * n - 1, false);
		ClinoDiagonal = vector<bool>(2 * n - 1, false);

		vector<string> VecStr;
		findNQueens(0, n, VecStr);
		
		return Result;
	}
};

int main() {

	vector<vector<string>> Result = Solution().solveNQueens(8);

	for (int i = 0; i < Result.size(); i++) {
		for (int j = 0; j < Result[i].size(); j++) {
			cout << Result[i][j] << endl;
		}
		cout << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}