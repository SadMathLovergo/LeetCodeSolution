#include <vector>
#include <iostream>
using namespace std;

/************************************
思路：
只有边界上的'O'，以及与边界上的'O'相连的'O'，不会被'X'围绕
因此，找出所有不在边界上，并且不与边界上的'O'相连的'O'，即可
采用floodfill算法，对边界上的'O'进行遍历，找到所有与边界上的'O'相连的'O'，剩下的'O'为被环绕的'O'
************************************/
class Solution {
private:
	int RowSize;//矩阵行数
	int ColumnSize;//矩阵列数
	vector<vector<bool>> isSurrounded;//保存环绕信息，被环绕的'O'为true，其它为false
	vector<vector<int>> direction{ vector<int>{-1,0},vector<int>{0,1}, vector<int>{1,0}, vector<int>{0,-1} };
	//判定索引是否合法
	bool inArea(int i, int j) {
		return i >= 0 && i < RowSize && j >= 0 && j < ColumnSize;
	}
	//找到所有与当前'O'节点相连的'O'，并更新isSurrounded信息
	void floodfill(int iIndex, int jIndex) {
		//若为非法索引，或者为'X'，或者为已经遍历过的'O'
		if (!inArea(iIndex, jIndex) || !isSurrounded[iIndex][jIndex])
			return;
		isSurrounded[iIndex][jIndex] = false;
		for (int i = 0; i < 4; i++)
			floodfill(iIndex + direction[i][0], jIndex + direction[i][1]);
	}

public:
	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;

		RowSize = board.size();
		ColumnSize = board[0].size();

		isSurrounded = vector<vector<bool>>(RowSize, vector<bool>(ColumnSize, false));

		//第一遍遍历，'O'为true，'X'为false
		for (int i = 0; i < RowSize; i++) {
			for (int j = 0; j < ColumnSize; j++) {
				if (board[i][j] == 'O')
					isSurrounded[i][j] = true;
			}
		}

		//遍历上下边界
		for (int i = 0; i < ColumnSize; i++) {
			floodfill(0, i);
			floodfill(RowSize - 1, i);
		}

		//遍历左右边界
		for (int i = 0; i < RowSize; i++) {
			floodfill(i, 0);
			floodfill(i, ColumnSize - 1);
		}

		//更新
		for (int i = 0; i < RowSize; i++)
			for (int j = 0; j < ColumnSize; j++)
				if (isSurrounded[i][j])
					board[i][j] = 'X';

	}
};