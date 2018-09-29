#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void levelOrder(TreeNode* root, vector<vector<int>>& result, int level) {
		if (root == NULL)
			return;

		if (result.size() == level)
			result.push_back(vector<int>());

		result[level].push_back(root->val);
		levelOrder(root->left, result, level + 1);
		levelOrder(root->right, result, level + 1);
	}

public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;

		if (root == NULL)
			return result;

		vector<vector<int>> levelOrderResult;;
		levelOrder(root, levelOrderResult, 0);

		for (int i = 0; i < levelOrderResult.size(); i++) {
			if (i % 2)
				result.push_back(vector<int>(levelOrderResult[i].rbegin(), levelOrderResult[i].rend()));
			else
				result.push_back(vector<int>(levelOrderResult[i].begin(), levelOrderResult[i].end()));
		}

		return result;
	}
};