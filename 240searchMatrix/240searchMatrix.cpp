#include <vector>
#include <iostream>
using namespace std;

//第240题：搜索二维矩阵2
//解题思路：参考了LeetCode上面大神的做法，从左下角开始寻找，所在列上方元素均比当前元素小，所在列右方元素均比当前元素大
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
		cout << "可以找到target" << endl;
	else
		cout << "不能找到target" << endl;
	
	system("pause");
	return 0;
}