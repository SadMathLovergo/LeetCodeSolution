#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
private:
	vector<pair<int, int>> fillRecord;	//��Ҫ��ı�����м�¼
	vector<vector<bool>> ColumnRecord;	//��¼ÿһ�е��������
	vector<vector<bool>> RowRecord;		//��¼ÿһ�е��������
	vector<vector<bool>> SudokuRecord;	//��¼ÿһ��С������������
	bool hasComplete = false;			//��¼�Ź����Ƿ��Ѿ�����

	void solveSudoku(vector<pair<int, int>> fillRecord, int index, vector<vector<char>>& board) {
		if (index == fillRecord.size()) {//���Ѿ����꣬�����hasComplete������
			hasComplete = true;
			return;
		}

		int RowIndex = fillRecord[index].first;
		int ColumnIndex = fillRecord[index].second;

		for (int i = 1; i <= 9; i++) {
			if (!RowRecord[RowIndex][i] && 
				!ColumnRecord[ColumnIndex][i] && 
				!SudokuRecord[(RowIndex / 3) * 3 + (ColumnIndex / 3)][i]) {//�ݹ����
				RowRecord[RowIndex][i] = true;
				ColumnRecord[ColumnIndex][i] = true;
				SudokuRecord[(RowIndex / 3) * 3 + (ColumnIndex / 3)][i] = true;

				board[RowIndex][ColumnIndex] = '0' + i;
				solveSudoku(fillRecord, index + 1, board);

				if (hasComplete)//���Ź����Ѿ���д�꣬�򷵻�
					return;

				RowRecord[RowIndex][i] = false;
				ColumnRecord[ColumnIndex][i] = false;
				SudokuRecord[(RowIndex / 3) * 3 + (ColumnIndex / 3)][i] = false;
			}
		}
	}

public:
	void solveSudoku(vector<vector<char>>& board) {
		//Ϊ�˷����¼����¼ÿһ��ÿһ��ÿ��С��������鳤��Ϊ10������Ϊ0~9,
		RowRecord = vector<vector<bool>>(9, vector<bool>(10, false));
		ColumnRecord = vector<vector<bool>>(9, vector<bool>(10, false));
		SudokuRecord = vector<vector<bool>>(9, vector<bool>(10, false));

		//�������������Ϣ���棬ͬʱ��δ��д���ֵ�λ����Ϣ�����
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