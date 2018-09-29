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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if (root == NULL)
			return res;
		if (root->left == NULL && root->right == NULL) {
			res.push_back(to_string(root->val));
			return res;
		}

		vector<string> vecL = binaryTreePaths(root->left);
		vector<string> vecR = binaryTreePaths(root->right);
		for (int i = 0; i < vecL.size(); i++)
			res.push_back(to_string(root->val) + "->" + vecL[i]);
		for (int i = 0; i < vecR.size(); i++)
			res.push_back(to_string(root->val) + "->" + vecR[i]);

		return res;
	}
};