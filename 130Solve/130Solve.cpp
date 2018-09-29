#include <vector>
#include <iostream>
using namespace std;

/************************************
˼·��
ֻ�б߽��ϵ�'O'���Լ���߽��ϵ�'O'������'O'�����ᱻ'X'Χ��
��ˣ��ҳ����в��ڱ߽��ϣ����Ҳ���߽��ϵ�'O'������'O'������
����floodfill�㷨���Ա߽��ϵ�'O'���б������ҵ�������߽��ϵ�'O'������'O'��ʣ�µ�'O'Ϊ�����Ƶ�'O'
************************************/
class Solution {
private:
	int RowSize;//��������
	int ColumnSize;//��������
	vector<vector<bool>> isSurrounded;//���滷����Ϣ�������Ƶ�'O'Ϊtrue������Ϊfalse
	vector<vector<int>> direction{ vector<int>{-1,0},vector<int>{0,1}, vector<int>{1,0}, vector<int>{0,-1} };
	//�ж������Ƿ�Ϸ�
	bool inArea(int i, int j) {
		return i >= 0 && i < RowSize && j >= 0 && j < ColumnSize;
	}
	//�ҵ������뵱ǰ'O'�ڵ�������'O'��������isSurrounded��Ϣ
	void floodfill(int iIndex, int jIndex) {
		//��Ϊ�Ƿ�����������Ϊ'X'������Ϊ�Ѿ���������'O'
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

		//��һ�������'O'Ϊtrue��'X'Ϊfalse
		for (int i = 0; i < RowSize; i++) {
			for (int j = 0; j < ColumnSize; j++) {
				if (board[i][j] == 'O')
					isSurrounded[i][j] = true;
			}
		}

		//�������±߽�
		for (int i = 0; i < ColumnSize; i++) {
			floodfill(0, i);
			floodfill(RowSize - 1, i);
		}

		//�������ұ߽�
		for (int i = 0; i < RowSize; i++) {
			floodfill(i, 0);
			floodfill(i, ColumnSize - 1);
		}

		//����
		for (int i = 0; i < RowSize; i++)
			for (int j = 0; j < ColumnSize; j++)
				if (isSurrounded[i][j])
					board[i][j] = 'X';

	}
};