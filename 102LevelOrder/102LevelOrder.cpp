#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> resVec;

		if (root == NULL)
			return resVec;

		queue<pair<TreeNode*, int>> QueueRecord;
		QueueRecord.push(make_pair(root, 0));

		while (!QueueRecord.empty()) {
			pair<TreeNode*, int> newPair = QueueRecord.front();
			QueueRecord.pop();

			if (newPair.second == resVec.size()) {
				resVec.push_back(vector<int>());
				resVec[newPair.second].push_back(newPair.first->val);
			}
			else {
				resVec[newPair.second].push_back(newPair.first->val);
			}

			if (newPair.first->left != NULL) {
				QueueRecord.push(make_pair(newPair.first->left, newPair.second + 1));
			}

			if (newPair.first->right != NULL) {
				QueueRecord.push(make_pair(newPair.first->right, newPair.second + 1));
			}

		}

		return resVec;
	}
};