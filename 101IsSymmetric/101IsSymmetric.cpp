#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		return isSymmetric(root->left, root->right);
	}

private:
	bool isSymmetric(TreeNode* pNode, TreeNode* qNode) {
		if (pNode == NULL && qNode == NULL)
			return true;
		if (pNode == NULL || qNode == NULL)
			return false;
		return (pNode->val == qNode->val) && isSymmetric(pNode->left, qNode->right) && isSymmetric(pNode->right, qNode->left);
	}
};