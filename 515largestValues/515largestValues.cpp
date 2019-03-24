#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void levelOrder(TreeNode* node, vector<vector<int>>& orderResult, int level) {
		if (node == nullptr)
			return;

		if (orderResult.size() == level)
			orderResult.push_back(vector<int>());

		orderResult[level].push_back(node->val);

		levelOrder(node->left, orderResult, level + 1);
		levelOrder(node->right, orderResult, level + 1);
	}

public:
	vector<int> largestValues(TreeNode* root) {
		vector<vector<int>> orderResult;

		levelOrder(root, orderResult, 0);

		for (int i = 0; i < orderResult.size(); i++)
			sort(orderResult[i].begin(), orderResult[i].end());

		vector<int> resVec;
		for (int i = 0; i < orderResult.size(); i++)
			resVec.push_back(orderResult[i].back());

		return resVec;
	}
};