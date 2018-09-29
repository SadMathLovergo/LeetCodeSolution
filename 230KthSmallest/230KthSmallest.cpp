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
public:
	int kthSmallest(TreeNode* root, int k) {
		vector<int> vec;
		InOrder(root, vec);
		return vec[k - 1];
	}

private:
	void InOrder(TreeNode* root, vector<int>& vec) {
		if (root == NULL)
			return;
		InOrder(root->left, vec);
		vec.push_back(root->val);
		InOrder(root->right, vec);
	}
};