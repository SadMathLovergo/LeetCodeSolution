#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int robRoot(TreeNode* root) {
		if (root == NULL)
			return 0;
		return max(robRoot(root->left) + robRoot(root->right), root->val + robChildRoot(root->left) + robChildRoot(root->right));
	}

	int robChildRoot(TreeNode* root) {
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return 0;
		if (root->left == NULL)
			return robRoot(root->right);
		if (root->right == NULL)
			return robRoot(root->left);
		return robRoot(root->left) + robRoot(root->right);
	}

public:
	int rob(TreeNode* root) {
		if (root == NULL)
			return 0;
		return robRoot(root);
	}
};