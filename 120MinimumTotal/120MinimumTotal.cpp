#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty())
			return 0;

		vector<vector<int>> memory(2, vector<int>(triangle.size(), 0));
		memory[0][0] = triangle[0][0];
		for (int i = 1; i < triangle.size(); i++) {
			memory[i % 2][0] = memory[(i - 1) % 2][0] + triangle[i][0];
			memory[i % 2][i] = memory[(i - 1) % 2][i - 1] + triangle[i][i];
			for (int j = 1; j < i; j++) {
				memory[i % 2][j] = min(memory[(i - 1) % 2][j - 1] + triangle[i][j], memory[(i - 1) % 2][j] + triangle[i][j]);
			}
		}
		int k = (triangle.size() - 1) % 2;
		int temp = memory[k][0];
		for (int i = 1; i < memory[0].size(); i++)
			temp = min(temp, memory[k][i]);
		return temp;
	}
};

int main() {
	vector<vector<int>> triangle;
	triangle.push_back(vector<int>{-1});
	triangle.push_back(vector<int>{2, 3});
	triangle.push_back(vector<int>{1, -1, -3});
	int res = Solution().minimumTotal(triangle);
	cout << res << endl;
	system("pause");
	return 0;
}