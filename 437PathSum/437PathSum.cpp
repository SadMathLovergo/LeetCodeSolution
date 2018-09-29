#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return 0;

		int res = 0;

		res = findPaths(root, sum);
		res += pathSum(root->left, sum);
		res += pathSum(root->right, sum);

		return res;
	}

private:
	int findPaths(TreeNode* root, int sum) {
		if (root == NULL)
			return 0;

		int res = 0;
		if (root->val == sum)
			res += 1;

		return findPaths(root->left, sum - root->val) + findPaths(root->right, sum - root->val) + res;
	}
};