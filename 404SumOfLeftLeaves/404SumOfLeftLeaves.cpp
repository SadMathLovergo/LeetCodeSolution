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
	int sumOfLeftLeaves(TreeNode* root) {
		vector<TreeNode*> vec;
		pushLeftLeaves(root, vec);
		int res = 0;
		for (int i = 0; i < vec.size(); i++)
			res += vec[i]->val;
		return res;
	}

private:
	void pushLeftLeaves(TreeNode* root, vector<TreeNode*>& vec) {
		if (root == NULL)
			return;

		if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
			vec.push_back(root->left);
			pushLeftLeaves(root->right, vec);
			return;
		}

		pushLeftLeaves(root->left, vec);
		pushLeftLeaves(root->right, vec);
	}

};