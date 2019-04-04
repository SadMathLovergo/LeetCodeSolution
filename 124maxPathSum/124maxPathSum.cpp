#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//使用递归解决
class Solution {
private:
	int maxSum;
	int findMaxSum(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int leftVal = findMaxSum(root->left);
		int rightVal = findMaxSum(root->right);
		int curMaxSum = root->val;

		if (leftVal > 0 && rightVal > 0)
			curMaxSum += leftVal + rightVal;
		else if (leftVal > 0)
			curMaxSum += leftVal;
		else if (rightVal > 0)
			curMaxSum += rightVal;

		if (curMaxSum > maxSum)
			maxSum = curMaxSum;

		return root->val + max(max(leftVal, rightVal), 0);
	}

public:
	int maxPathSum(TreeNode* root) {
		if (root == nullptr)
			return 0;

		maxSum = INT_MIN;
		findMaxSum(root);

		return maxSum;
	}
};