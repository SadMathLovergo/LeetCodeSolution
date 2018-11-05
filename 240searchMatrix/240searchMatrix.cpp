#include <vector>
#include <iostream>
using namespace std;

//��240�⣺������ά����2
//����˼·���ο���LeetCode�������������������½ǿ�ʼѰ�ң��������Ϸ�Ԫ�ؾ��ȵ�ǰԪ��С���������ҷ�Ԫ�ؾ��ȵ�ǰԪ�ش�
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;
		int i = matrix.size() - 1;
		int j = 0;
		while (i >= 0 && j < matrix[0].size())
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] < target)
				j++;
			else
				i--;
		return false;
	}
};

int main() {
	vector<vector<int>> matrix{
		vector<int>{1,4,7,11,15},
		vector<int>{2,5,8,12,19},
		vector<int>{3,6,9,16,22},
		vector<int>{10,13,14,17,24},
		vector<int>{18,21,23,26,30}
	};
	int target = 5;

	if (Solution().searchMatrix(matrix, target))
		cout << "�����ҵ�target" << endl;
	else
		cout << "�����ҵ�target" << endl;
	
	system("pause");
	return 0;
}