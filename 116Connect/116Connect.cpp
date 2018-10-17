#include <iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/*��116�� ���ͬһ����ֵܽڵ�*/
//����˼·��ֱ�ӵݹ�ͺ�
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
		//�����Ӻ��Һ��ӽ��еݹ����
		connect(root->left);
		connect(root->right);

	}
};