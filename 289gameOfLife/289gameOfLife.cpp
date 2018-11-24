#pragma once
#include <vector>
#include <algorithm>
using namespace std;

//��289�� ������Ϸ
//����Ĺؼ����ڸ���ϸ��״̬��ͬʱ������֮ǰ��״̬��Ϣ
//����ԭ�ظ��µĹؼ�
//��һ�θ��£���ϸ��->��ϸ����0->10
//��ϸ��->��ϸ����1->11
//���ָ��·�ʽ���Ա�������֮ǰ��״̬��Ϣ
class Solution {
private:
	int RowSize;
	int ColSize;

	//�����ھ��еĻ�ϸ����
	int CountNeighbor(const vector<vector<int>>& board, int rowIndex, int colIndex) {
		int count = 0;
		for (int i = max(0, rowIndex - 1); i <= min(rowIndex + 1, RowSize - 1); i++)
			for (int j = max(0, colIndex - 1); j <= min(colIndex + 1, ColSize - 1); j++)
				if (board[i][j] % 10 == 1 && (i != rowIndex || j != colIndex))
					count++;
		return count;
	}

	//�Զ�ά������е�һ�θ���
	//�˴θ��¿��Ա�������ǰ��ϸ����Ϣ
	void Update(vector<vector<int>>& board) {
		for (int i = 0; i < RowSize; i++)
			for (int j = 0; j < ColSize; j++) {
				int count = CountNeighbor(board, i, j);
				if (count == 3 || (count == 2 && board[i][j] == 1))
					board[i][j] += 10;
			}

	}

	//���еڶ��θ���
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