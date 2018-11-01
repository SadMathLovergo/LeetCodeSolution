#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

//��221�� ���������
//����˼·������ÿһ���Խ��ߵĵ㣬����ĶԽ��߿�ʼ����
class Solution {
private:
	int RowSize, ColSize;
	//�ҵ���matrix[rowIndex][colIndex]Ϊ���ϽǶ����ֻ����1����������εı߳�
	int findMaximalSquare(int rowIndex, int colIndex, vector<vector<char>>& matrix) {
		if (matrix[rowIndex][colIndex] == '0')
			return 0;
		int i = 1;
		for (; rowIndex + i < RowSize && colIndex + i < ColSize; i++) {
			bool isNormalSquare = true;
			for (int j = 0; j <= i; j++)
				if (matrix[rowIndex + i][colIndex + j] == '0' || matrix[rowIndex + j][colIndex + i] == '0') {
					isNormalSquare = false;
					break;
				}
			if (!isNormalSquare)
				break;
		}
		return i;
	}

public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		RowSize = matrix.size();
		ColSize = matrix[0].size();

		int Ret = 0;
		
		if (RowSize < ColSize) {
			//����ColSize-RowSize+1����ĶԽ��ߣ���i���Խ���
			for (int i = 0; i <= ColSize - RowSize; i++) {
				//��i���Խ��ߣ���j����
				for (int j = 0; j < RowSize; j++) {
					Ret = max(Ret, findMaximalSquare(j, i + j, matrix));
					if (Ret >= RowSize - j - 1)
						break;
				}
			}
			//��������ʣ�µ�RowSize-1���Խ���
			for (int i = 1; i < RowSize; i++) {
				for (int j = 0; j < RowSize - i; j++) {
					Ret = max(Ret, findMaximalSquare(i + j, j, matrix));
					Ret = max(Ret, findMaximalSquare(j, ColSize - RowSize + i + j, matrix));
					if (Ret >= RowSize - i - j - 1)
						break;
				}
			}

			return pow(Ret, 2);
		}
		else {
			//����RowSize-ColSize+1����ĶԽ��ߣ���i���Խ���
			for (int i = 0; i <= RowSize - ColSize; i++) {
				//��i���Խ��ߣ���j����
				for (int j = 0; j < ColSize; j++) {
					Ret = max(Ret, findMaximalSquare(i + j, j, matrix));
					if (Ret >= ColSize - j - 1)
						break;
				}
			}
			//��������ʣ�µ�ColSize-1���Խ���
			for (int i = 1; i < ColSize; i++) {
				for (int j = 0; j < ColSize - i; j++) {
					Ret = max(Ret, findMaximalSquare(j, i + j, matrix));
					Ret = max(Ret, findMaximalSquare(RowSize - ColSize + i + j, j, matrix));
					if (Ret >= ColSize - i - j - 1)
						break;
				}
			}

			return pow(Ret, 2);
		}
		
	}
};

int main() {
	vector<vector<char>> matrix;
	matrix.push_back(vector<char>{'1', '0', '1', '0', '0'});
	matrix.push_back(vector<char>{'1', '0', '1', '1', '1'});
	matrix.push_back(vector<char>{'1', '1', '1', '1', '1'});
	matrix.push_back(vector<char>{'1', '0', '0', '1', '0'});
	int ret = Solution().maximalSquare(matrix);
	cout << ret << endl;
	system("pause");
	return 0;
}