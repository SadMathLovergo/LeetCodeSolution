#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<bool>> visited;
	vector<vector<int>> direction;

	bool doExist(vector<vector<char>>& board, string word, int xIndex, int yIndex, int strIndex) {
		if (strIndex == word.size())
			return true;
		if (xIndex < 0 || xIndex >= board.size() || yIndex < 0 || yIndex >= board[0].size())
			return false;
		if (visited[xIndex][yIndex])
			return false;
		if (board[xIndex][yIndex] == word[strIndex]) {
			visited[xIndex][yIndex] = true;
			if (doExist(board, word, xIndex + direction[0][0], yIndex + direction[0][1], strIndex + 1) ||
				doExist(board, word, xIndex + direction[1][0], yIndex + direction[1][1], strIndex + 1) ||
				doExist(board, word, xIndex + direction[2][0], yIndex + direction[2][1], strIndex + 1) ||
				doExist(board, word, xIndex + direction[3][0], yIndex + direction[3][1], strIndex + 1))
				return true;
			visited[xIndex][yIndex] = false;
		}
		return false;
	}

public:
	bool exist(vector<vector<char>>& board, string word) {
		if (word == "")
			return true;
		visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
		direction = vector<vector<int>>{ vector<int>{-1,0},vector<int>{0,1},vector<int>{1,0},vector<int>{0,-1} };
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++)
				if (doExist(board, word, i, j, 0))
					return true;
		return false;
	}
};