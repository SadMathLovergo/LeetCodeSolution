#include <vector>
#include <queue>
using namespace std;

/*��48�⣬��תͼ��*/
/*����˼·���������ڣ�һ��һ�����˳ʱ����ת*/
/*�Ե�i�������תʱ��ÿ����תһ���ܹ���ת(n - 2*i + 1)��*/
/*ÿ�α���ʱ����ʱ�뷽���Ԫ�ؽ��б���*/
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;

		int n = matrix.size();
		/*nxn�ľ����ܹ���n/2�㣬ֻ��һ��Ԫ�ص����ڲ㲻��*/
		int circleNum = n / 2;

		/*�Ե�i����б�����ÿһ���ÿһ������(n - 2*i + 2)��Ԫ��*/
		for (int i = 1; i <= circleNum; i++) {
			/*��ÿһ����е�j����ת*/
			for (int j = 0; j < (n - 2 * i + 1); j++) {
				/*����ÿһ������Ͻ�Ԫ��*/
				int temp = matrix[i - 1][i - 1];
				/*����߽�����ת*/
				for (int k = i - 1; k < n - i; k++)
					matrix[k][i - 1] = matrix[k + 1][i - 1];
				/*���±߽�����ת*/
				for (int k = i - 1; k < n - i; k++)
					matrix[n - i][k] = matrix[n - i][k + 1];
				/*���ұ߽�����ת*/
				for (int k = n - i; k > i - 1; k--)
					matrix[k][n - i] = matrix[k - 1][n - i];
				/*���ϱ߽�����ת*/
				for (int k = n - i; k > i - 1; k--)
					matrix[i - 1][k] = matrix[i - 1][k - 1];
				/*�������һ��Ԫ��*/
				matrix[i - 1][i] = temp;
			}
		}

	}
};