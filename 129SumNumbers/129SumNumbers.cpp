#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		if (root == NULL)
			return 0;

		int ret = 0;
		vector<queue<int>> oriVec = FindPaths(root);
		for (int i = 0; i < oriVec.size(); i++) {
			int num = 0;
			int j = 0;
			while (!oriVec[i].empty()) {
				num += oriVec[i].front()*pow(10, j);
				oriVec[i].pop();
				j++;
			}
			ret += num;
		}

		return ret;
	}

private:
	vector<queue<int>> FindPaths(TreeNode* root) {
		vector<queue<int>> res;

		if (root == NULL)
			return res;

		if (root->left == NULL && root->right == NULL) {
			res.push_back(queue<int>());
			res[0].push(root->val);
			return res;
		}

		vector<queue<int>> resL = FindPaths(root->left);
		vector<queue<int>> resR = FindPaths(root->right);

		for (int i = 0; i < resL.size(); i++) {
			resL[i].push(root->val);
			res.push_back(resL[i]);
		}

		for (int i = 0; i < resR.size(); i++) {
			resR[i].push(root->val);
			res.push_back(resR[i]);
		}

		return res;
	}
};

int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	Solution solution;
	int answer = solution.sumNumbers(root);
	cout << answer << endl;

	system("pause");
	return 0;
}