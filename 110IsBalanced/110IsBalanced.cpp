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
public:
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		if (isBalanced(root->left) && isBalanced(root->right))
			return abs(height(root->left) - height(root->right)) <= 1;
		return false;
	}

private:
	int height(TreeNode* root) {
		if (root == NULL)
			return 0;

		if (root->left == NULL && root->right == NULL)
			return 1;

		return max(height(root->left), height(root->right)) + 1;
	}
};