#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//第173题 二叉搜索树迭代器
//解题思路：目前想到的是，进行先序遍历，将遍历到的节点val值，放入队列中，不断从队头取元素
class BSTIterator {
private:
	queue<int> treeNodeQueue;
	void preOrder(TreeNode* root) {
		if (root == NULL)
			return;
		preOrder(root->left);
		treeNodeQueue.push(root->val);
		preOrder(root->right);
	}

public:
	BSTIterator(TreeNode *root) {
		preOrder(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !treeNodeQueue.empty();
	}

	/** @return the next smallest number */
	int next() {
		int next = treeNodeQueue.front();
		treeNodeQueue.pop();
		return next;
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/