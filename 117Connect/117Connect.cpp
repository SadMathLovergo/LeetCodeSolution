#include <iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/*第117题 填充同一层的兄弟节点2*/
//解题思路：依旧使用递归的方法来解决
//但是由于二叉树可能不是完美二叉树，所以不能使用116题的思路
class Solution {
	//将upperNode的孩子节点和下一个孩子节点相连
	TreeLinkNode* connectLayer(TreeLinkNode* upperNode) {
		if (upperNode == NULL)
			return upperNode;

		//若左孩子不为空
		if (upperNode->left != NULL) {
			if (upperNode->right != NULL) {//若右孩子不为空
				//连接左孩子和右孩子
				upperNode->left->next = upperNode->right;
				//将右孩子与下一个孩子节点相连
				upperNode->right->next = connectLayer(upperNode->next);
				return upperNode->left;
			}
			else {//若右孩子为空
				//将左孩子与下一个孩子节点相连
				upperNode->left->next = connectLayer(upperNode->next);
				return upperNode->left;
			}
		}
		else {//若左孩子为空
			if (upperNode->right != NULL) {//若右孩子不为空
				//将右孩子与下一个孩子节点相连
				upperNode->right->next = connectLayer(upperNode->next);
				return upperNode->right;
			}
			else//若右孩子为空，返回下一个孩子节点
				return connectLayer(upperNode->next);
		}

	}

public:
	void connect(TreeLinkNode *root) {
		//将当前层的孩子节点全部连接起来，同时获取下一层的第一个节点
		TreeLinkNode* nextNode = connectLayer(root);
		//若下一层没有节点，表示已经连接完毕
		if (nextNode == NULL)
			return;
		//开始连接下一层节点
		connect(nextNode);
	}
};