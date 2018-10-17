#include <iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/*第116题 填充同一层的兄弟节点*/
//解题思路，直接递归就好
class Solution {
private:
	void connectBridge(TreeLinkNode* leftRoot, TreeLinkNode* rightRoot) {
		if (leftRoot != NULL)
			leftRoot->next = rightRoot;
		if (rightRoot != NULL && leftRoot->right != NULL)
			connectBridge(leftRoot->right, rightRoot->left);
		
	}
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;

		connectBridge(root->left, root->right);
		//对左孩子和右孩子进行递归操作
		connect(root->left);
		connect(root->right);

	}
};