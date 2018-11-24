#pragma once
#include <vector>
#include <algorithm>
using namespace std;

//第289题 生命游戏
//解题的关键在于更新细胞状态的同时，保持之前的状态信息
//这是原地更新的关键
//第一次更新：死细胞->活细胞，0->10
//活细胞->活细胞，1->11
//这种更新方式可以保留更新之前的状态信息
class Solution {
private:
	int RowSize;
	int ColSize;

	//计算邻居中的活细胞数
	int CountNeighbor(const vector<vector<int>>& board, int rowIndex, int colIndex) {
		int count = 0;
		for (int i = max(0, rowIndex - 1); i <= min(rowIndex + 1, RowSize - 1); i++)
			for (int j = max(0, colIndex - 1); j <= min(colIndex + 1, ColSize - 1); j++)
				if (board[i][j] % 10 == 1 && (i != rowIndex || j != colIndex))
					count++;
		return count;
	}

	//对二维数组进行第一次更新
	//此次更新可以保留更新前的细胞信息
	void Update(vector<vector<int>>& board) {
		for (int i = 0; i < RowSize; i++)
			for (int j = 0; j < ColSize; j++) {
				int count = CountNeighbor(board, i, j);
				if (count == 3 || (count == 2 && board[i][j] == 1))
					board[i][j] += 10;
			}

	}

	//进行第二次更新
	void Refresh(vector<vector<int>>& board) {
		for (int i = 0; i < RowSize; i++)
			for (int j = 0; j < ColSize; j++)
				board[i][j] /= 10;
	}

public:
	void gameOfLife(vector<vector<int>>& board) {
		RowSize = board.size();
		ColSize = board[0].size();

		Update(board);
		Refresh(board);
	}
};