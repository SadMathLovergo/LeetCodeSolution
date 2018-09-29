#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		if (root == NULL)
			return res;
		vector<vector<int>> oriVec = FindPath(root, sum);
		for (int i = 0; i < oriVec.size(); i++) {
			res.push_back(vector<int>(oriVec[i].rbegin(), oriVec[i].rend()));
		}
		return res;
	}

private:
	vector<vector<int>> FindPath(TreeNode* root, int sum) {
		vector<vector<int>> ret;

		if (root == NULL)
			return ret;

		if (root->left == NULL && root->right == NULL) {
			if (root->val == sum) {
				ret.push_back(vector<int>());
				ret[0].push_back(root->val);
				return ret;
			}
		}

		vector<vector<int>> retL = FindPath(root->left, sum - root->val);
		vector<vector<int>> retR = FindPath(root->right, sum - root->val);
		for (int i = 0; i < retL.size(); i++) {
			retL[i].push_back(root->val);
			ret.push_back(retL[i]);
		}
		for (int i = 0; i < retR.size(); i++) {
			retR[i].push_back(root->val);
			ret.push_back(retR[i]);
		}

		return ret;
	}
};
