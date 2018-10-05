#include <vector>
using namespace std;

/*��36�� ��Ч������*/
/*����˼·����ÿ��Ԫ�ؽ��б������ɣ��鿴ÿһ�С�ÿһ�С�ÿһ��С�����Ƿ�����ظ�������*/
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<vector<bool>> RowMemo(9, vector<bool>(10, false));
		vector<vector<bool>> ColumnMemo(9, vector<bool>(10, false));
		vector<vector<bool>> BlockMemo(9, vector<bool>(10, false));

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] != '.')
					if (RowMemo[i][board[i][j] - '0'] || ColumnMemo[j][board[i][j] - '0'] || BlockMemo[i / 3 * 3 + j / 3][board[i][j] - '0'])
						return false;
					else {
						RowMemo[i][board[i][j] - '0'] = true;
						ColumnMemo[j][board[i][j] - '0'] = true;
						BlockMemo[i / 3 * 3 + j / 3][board[i][j] - '0'] = true;
					}
			}
		}

		return true;
	}
};