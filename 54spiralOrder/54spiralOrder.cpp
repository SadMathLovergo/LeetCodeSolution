#include <vector>
using namespace std;

/*��54�� ��������*/
/*����˼·��һȦһȦ����*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> resVec;
		if (matrix.empty())
			return resVec;

		int beginRow = 0;
		int endRow = matrix.size() - 1;
		int beginCol = 0;
		int endCol = matrix[0].size() - 1;

		while (beginRow < endRow && beginCol < endCol) {
			/*�����ϵ�*/
			for (int i = beginCol; i < endCol; i++)
				resVec.push_back(matrix[beginRow][i]);
			/*�����ұ�*/
			for (int i = beginRow; i < endRow; i++)
				resVec.push_back(matrix[i][endCol]);
			/*�����µ�*/
			for (int i = endCol; i > beginCol; i--)
				resVec.push_back(matrix[endRow][i]);
			/*�������*/
			for (int i = endRow; i > beginRow; i--)
				resVec.push_back(matrix[i][beginCol]);
			/*���±߽�ֵ*/
			beginRow++;
			endRow--;
			beginCol++;
			endCol--;
		}

		/*ʣ��һ��δ����*/
		if (beginRow == endRow) {
			for (int i = beginCol; i <= endCol; i++)
				resVec.push_back(matrix[beginRow][i]);
		}
		else if (beginCol == endCol) {/*ʣ�����һ��δ����*/
			for (int i = beginRow; i <= endRow; i++)
				resVec.push_back(matrix[i][beginCol]);
		}

		return resVec;
	}
};