#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<bool>> visited;
	int direction[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int xSize, ySize;
	bool inArea(int x, int y) {
		return x >= 0 && x < xSize && y >= 0 && y < ySize;
	}

	void findIslands(vector<vector<char>>& grid, int xIndex, int yIndex) {
		visited[xIndex][yIndex] = true;

		for (int i = 0; i < 4; i++) {
			int newX = xIndex + direction[i][0];
			int newY = yIndex + direction[i][1];
			if (inArea(newX, newY))
				if (!visited[newX][newY] && grid[newX][newY] == '1')
					findIslands(grid, newX, newY);
		}
		return;
	}

public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0)
			return 0;
		int islandNum = 0;
		xSize = grid.size();
		ySize = grid[0].size();
		visited = vector<vector<bool>>(xSize, vector<bool>(ySize, false));
		for (int i = 0; i < xSize; i++)
			for (int j = 0; j < ySize; j++)
				if (grid[i][j] == '1' && !visited[i][j]) {
					islandNum++;
					findIslands(grid, i, j);
				}
		return islandNum;
	}
};

int main() {
	vector<vector<char>> grid { { '1','1','1','1','0' },{ '1','1','0','1','0' },{ '1','1','0','0','0' },{ '0','0','0','0','0' } };
	int nums = Solution().numIslands(grid);
	cout << nums << endl;
	system("pause");
	return 0;
}