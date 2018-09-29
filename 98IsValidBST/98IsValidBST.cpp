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
	bool isValidBST(TreeNode* root) {
		vector<int> vec;
		InOrder(root, vec);
		if (vec.size() <= 1)
			return true;
		for (int i = 0; i < vec.size() - 1; i++) {
			if (vec[i] >= vec[i + 1])
				return false;
		}
		return true;
	}

private:
	void InOrder(TreeNode* root, vector<int>& nums) {
		if (root == NULL)
			return;
		InOrder(root->left, nums);
		nums.push_back(root->val);
		InOrder(root->right, nums);
	}
};