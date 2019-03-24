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
	void levelOrder(TreeNode* node, vector<vector<int>>& orderResult, int level) {
		if (node == nullptr)
			return;

		if (orderResult.size() == level)
			orderResult.push_back(vector<int>());

		orderResult[level].push_back(node->val);
		
		levelOrder(node->left, orderResult, level + 1);
		levelOrder(node->right, orderResult, level + 1);
	}

public:
	int findBottomLeftValue(TreeNode* root) {
		vector<vector<int>> orderResult;

		levelOrder(root, orderResult, 0);

		return orderResult.back()[0];
	}
};