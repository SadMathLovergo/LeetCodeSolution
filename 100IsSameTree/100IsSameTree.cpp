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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
			return false;
		vector<int> vecP;
		vector<int> vecQ;
		PreOrder(p, vecP);
		PreOrder(q, vecQ);
		if (vecP.size() != vecQ.size())
			return false;
		for (int i = 0; i < vecP.size(); i++) {
			if (vecP[i] != vecQ[i])
				return false;
		}
		return true;
	}

private:
	void PreOrder(TreeNode* node, vector<int>& vec) {
		if (node == NULL) {
			vec.push_back(NULL);
			return;
		}
		if (node->left == NULL && node->right == NULL) {
			vec.push_back(node->val);
			return;
		}
		vec.push_back(node->val);
		PreOrder(node->left, vec);
		PreOrder(node->right, vec);
	}
};