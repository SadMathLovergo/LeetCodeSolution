#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == NULL)
			return 0;

		int lHeight = countLeftHeight(root);
		int rHeight = countRightHeight(root);

		if (lHeight == rHeight)
			return pow(2, lHeight) - 1;
		else
			return countNodes(root->left) + countNodes(root->right) + 1;
	}

private:
	int countLeftHeight(TreeNode* node) {
		if (node == NULL)
			return 0;
		return countLeftHeight(node->left) + 1;
	}

	int countRightHeight(TreeNode* node) {
		if (node == NULL)
			return 0;
		return countRightHeight(node->right) + 1;
	}
};