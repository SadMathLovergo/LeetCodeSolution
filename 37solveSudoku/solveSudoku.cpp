#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
private:
	vector<pair<int, int>> fillRecord;	//需要填的表格序列记录
	vector<vector<bool>> ColumnRecord;	//记录每一行的数字情况
	vector<vector<bool>> RowRecord;		//记录每一列的数字情况
	vector<vector<bool>> SudokuRecord;	//记录每一个小方格的数字情况
	bool hasComplete = false;			//记录九宫格是否已经填完

	void solveSudoku(vector<pair<int, int>> fillRecord, int index, vector<vector<char>>& board) {
		if (index == fillRecord.size()) {//若已经填完，则更新hasComplete，返回
			hasComplete = true;
			return;
		}

		int RowIndex = fillRecord[index].first;
		int ColumnIndex = fillRecord[index].second;

		for (int i = 1; i <= 9; i++) {
			if (!RowRecord[RowIndex][i] && 
				!ColumnRecord[ColumnIndex][i] && 
				!SudokuRecord[(RowIndex / 3) * 3 + (ColumnIndex / 3)][i]) {//递归回溯
				RowRecord[RowIndex][i] = true;
				ColumnRecord[ColumnIndex][i] = true;
				SudokuRecord[(RowIndex / 3) * 3 + (ColumnIndex / 3)][i] = true;

				board[RowIndex][ColumnIndex] = '0' + i;
				solveSudoku(fillRecord, index + 1, board);

				if (hasComplete)//若九宫格已经填写完，则返回
					return;

				RowRecord[RowIndex][i] = false;
				ColumnRecord[ColumnIndex][i] = false;
				SudokuRecord[(RowIndex / 3) * 3 + (ColumnIndex / 3)][i] = false;
			}
		}
	}

public:
	void solveSudoku(vector<vector<char>>& board) {
		//为了方便记录，记录每一行每一列每个小方格的数组长度为10，索引为0~9,
		RowRecord = vector<vector<bool>>(9, vector<bool>(10, false));
		ColumnRecord = vector<vector<bool>>(9, vector<bool>(10, false));
		SudokuRecord = vector<vector<bool>>(9, vector<bool>(10, false));

		//将已填好数字信息保存，同时将未填写数字的位置信息保存好
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.')
					fillRecord.push_back(make_pair(i, j));
				else {
					int num = board[i][j] - '0';
					RowRecord[i][num] = true;
					ColumnRecord[j][num] = true;
					SudokuRecord[(i / 3) * 3 + (j / 3)][num] = true;
				}
			}
		}

		solveSudoku(fillRecord, 0, board);
	}
};

int main() {
	vector<vector<char>> board;
	vector<string> strVec{
		"53..7....",
		"6..195...",
		".98....6.",
		"8...6...3",
		"4..8.3..1",
		"7...2...6",
		".6....28.",
		"...419..5",
		"....8..79"
	};

	for (int i = 0; i < strVec.size(); i++) {
		vector<char> charVec;
		for (int j = 0; j < 9; j++)
			charVec.push_back(strVec[i][j]);
		board.push_back(charVec);
	}

	Solution().solveSudoku(board);
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j];
		cout << endl;
	}

	system("pause");
	return 0;
}