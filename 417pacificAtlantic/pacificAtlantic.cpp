#include <vector>
#include <iostream>
using namespace std;

//˼·�����ˮ��������̫ƽ������꣬�Լ�����������������꣬ȡ����
//�����߽�ĵ㣬����floodfill�㷨�����ֱ����ˮ��������̫ƽ��ʹ����������
class Solution {
private:
	int RowSize;
	int ColumnSize;
	vector<vector<bool>> pacificMemo;//����ˮ���ܷ�����̫ƽ��falseΪ�����ԣ�trueΪ����
	vector<vector<bool>> atlanticMemo;//����ˮ���ܷ�����������falseΪ�����ԣ�trueΪ����
	vector<vector<int>> direction{ vector<int>{-1,0}, vector<int>{0,1}, vector<int>{1,0}, vector<int>{0,-1} };

	bool inArea(int iIndex, int jIndex) {
		return (iIndex >= 0) && (iIndex < RowSize) && (jIndex >= 0) && (jIndex < ColumnSize);
	}

	void floodFill(int iIndex, int jIndex, int lastValue,  vector<vector<bool>>& memo, vector<vector<int>>& matrix) {
		//���������Ϸ��������Ѿ�ȷ��ˮ��������̫ƽ��/��������return
		if (!inArea(iIndex, jIndex) || memo[iIndex][jIndex])
			return;
		int value = matrix[iIndex][jIndex];
		if (value >= lastValue) {
			memo[iIndex][jIndex] = true;
			for (int i = 0; i < 4; i++)
				floodFill(iIndex + direction[i][0], jIndex + direction[i][1], value, memo, matrix);
		}
	}

public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<pair<int, int>> resVec;
		if (matrix.empty())
			return resVec;

		RowSize = matrix.size();
		ColumnSize = matrix[0].size();

		pacificMemo = vector<vector<bool>>(RowSize, vector<bool>(ColumnSize, false));
		atlanticMemo = vector<vector<bool>>(RowSize, vector<bool>(ColumnSize, false));

		//�����������߽���б���
		for (int i = 0; i < ColumnSize; i++) {
			floodFill(0, i, -1, pacificMemo, matrix);
			floodFill(RowSize - 1, i, -1, atlanticMemo, matrix);
		}

		//�����������߽���б���
		for (int i = 0; i < RowSize; i++) {
			floodFill(i, 0, -1, pacificMemo, matrix);
			floodFill(i, ColumnSize-1, -1, atlanticMemo, matrix);
		}

		for (int i = 0; i < RowSize; i++)
			for (int j = 0; j < ColumnSize; j++)
				if (pacificMemo[i][j] && atlanticMemo[i][j])
					resVec.push_back(make_pair(i, j));

		return resVec;
	}
};

int main() {
	vector<vector<int>> matrix{ vector<int>{1,2,3,4,5},vector<int>{16,17,18,19,6}, vector<int>{15,24,25,20,7}, vector<int>{14,23,22,21,8}, vector<int>{13,12,11,10,9} };
	vector<pair<int, int>> resVec = Solution().pacificAtlantic(matrix);
	for (int i = 0; i < resVec.size(); i++)
		cout << '(' << resVec[i].first << ',' << resVec[i].second << ')' << endl;
	system("pause");
	return 0;
}