#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//��173�� ����������������
//����˼·��Ŀǰ�뵽���ǣ�����������������������Ľڵ�valֵ����������У����ϴӶ�ͷȡԪ��
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