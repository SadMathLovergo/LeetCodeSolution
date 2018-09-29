#include <iostream>
#include <vector>
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
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> vecP;
		vector<TreeNode*> vecQ;
		hasTreeNode(root, p, vecP);
		hasTreeNode(root, q, vecQ);
		int indexP = vecP.size() - 1;
		int indexQ = vecQ.size() - 1;
		while ( indexP >= 0 && indexQ >= 0 && vecP[indexP] == vecQ[indexQ]) {
			indexP--;
			indexQ--;
		}
		return vecP[indexP + 1];
	}

private:
	bool hasTreeNode(TreeNode* root, TreeNode* node, vector<TreeNode*>& vec) {
		if (root == NULL)
			return false;
		if (root == node) {
			vec.push_back(root);
			return true;
		}
		if (hasTreeNode(root->left, node, vec) || hasTreeNode(root->right, node, vec)) {
			vec.push_back(root);
			return true;
		}
		return false;
	}
};