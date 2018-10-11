#include <vector>
using namespace std;

/*��73�� ��������*/
class Solution {
private:
	/*��ָ��������*/
	void setRowZero(vector<vector<int>>& matrix, int Row) {
		for (int i = 0; i < matrix[0].size(); i++)
			matrix[Row][i] = 0;
	}

	/*��ָ��������*/
	void setColZero(vector<vector<int>>& matrix, int Col) {
		for (int i = 0; i < matrix.size(); i++)
			matrix[i][Col] = 0;
	}

public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;

		int m = matrix.size();
		int n = matrix[0].size();

		vector<bool> RowMemo(m, false);//��¼���Ƿ�Ҫ����Ϊ0��trueΪ�ǣ�falseΪ��
		vector<bool> ColMemo(n, false);//��¼���Ƿ�Ҫ����Ϊ0��trueΪ�ǣ�falseΪ��

		for(int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					RowMemo[i] = true;
					ColMemo[j] = true;
				}
			}

		for (int i = 0; i < m; i++)
			if (RowMemo[i])
				setRowZero(matrix, i);

		for (int i = 0; i < n; i++)
			if (ColMemo[i])
				setColZero(matrix, i);


	}
};