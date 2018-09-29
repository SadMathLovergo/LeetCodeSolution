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
	TreeNode * deleteNode(TreeNode* root, int key) {
		if (root == NULL)
			return NULL;
		if (key < root->val) {
			root->left = deleteNode(root->left, key);
			return root;
		}
		else if (key > root->val) {
			root->right = deleteNode(root->right, key);
			return root;
		}
		else {//key == root->val
			return deleteNode(root);
		}
	}
private:
	TreeNode * deleteNode(TreeNode* root) {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}
		else if (root->right == NULL) {//右子树不存在
			TreeNode* leftNode = root->left;
			delete root;
			return leftNode;
		}
		else if (root->left == NULL) {//左子树不存在
			TreeNode* rightNode = root->right;
			delete root;
			return rightNode;
		}
		else {//左子树和右子树都存在
			TreeNode* maxNode = root->left;
			while (maxNode->right != NULL)
				maxNode = maxNode->right;
			TreeNode* successor = new TreeNode(maxNode->val);
			successor->right = root->right;
			successor->left = RemoveMax(root->left);
			delete root;
			return successor;
		}
	}
	//删除以当前节点为根节点的树中的最大值
	TreeNode* RemoveMax(TreeNode* root) {
		if (root->right != NULL) {
			root->right = RemoveMax(root->right);
			return root;
		}
		else {
			TreeNode* leftNode = root->left;
			delete root;
			return leftNode;
		}
	}
};