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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result;

		if (root == NULL)
			return result;

		levelOrder(root, result, 0);

		return vector<vector<int>>(result.rbegin(), result.rend());
	}
};