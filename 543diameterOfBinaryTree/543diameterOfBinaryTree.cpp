#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	unordered_map<TreeNode*, int> heightRecord;
	//以当前节点为根节点的树的高度
	int findHeight(TreeNode* node) {
		if (node == nullptr)
			return 0;

		int leftHeight = findHeight(node->left);
		int rightHeight = findHeight(node->right);
		int height = max(leftHeight, rightHeight) + 1;

		heightRecord.insert(make_pair(node, height));

		return height;
	}

	int findDiameter(TreeNode* node) {
		if (node == nullptr)
			return 0;
		int value = heightRecord[node->left] + heightRecord[node->right];
		return max(value, max(findDiameter(node->left), findDiameter(node->right)));
	}

public:
	int diameterOfBinaryTree(TreeNode* root) {
		heightRecord.clear();

		findHeight(root);

		return findDiameter(root);
	}

};