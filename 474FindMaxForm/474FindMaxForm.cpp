#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {

public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> memory(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < strs.size(); i++) {
			int CharacterNum[2]{ 0,0 };
			for (int j = 0; j < strs[i].size(); j++)
				CharacterNum[strs[i][j] - '0']++;
			for (int l = m; l >= CharacterNum[0]; l--)
				for (int k = n; k >= CharacterNum[1]; k--)
					memory[l][k] = max(memory[l - CharacterNum[0]][k - CharacterNum[1]] + 1, memory[l][k]);
		}
		return memory[m][n];
	}
};

int main() {
	vector<string> strs{ "111","1000","1000","1000" };
	int m = 9;
	int n = 3;
	int res = Solution().findMaxForm(strs, m, n);
	cout << res << endl;
	system("pause");
	return 0;
}