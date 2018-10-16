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

/*第114题 二叉树展开为链表*/
//解题思路：直接递归就好，不要犹豫
//我擦，原题没说要按升序来排列链表，尼玛，你在逗我吗？呵呵！呵呵！
//我以为要按升序来排列链表，忙活了半天，原来是直接按先序遍历的序列来排列就好
class Solution {
private:
	//对以root为根节点的二叉树进行展开操作，返回新的根节点
	TreeNode * flattenRoot(TreeNode* root) {
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return root;

		//对左子树及右子树进行展开操作
		root->left = flattenRoot(root->left);
		root->right = flattenRoot(root->right);

		//先将左子树及右子树合并，此时左子树和右子树均已展开成链表，且升序排列
		TreeNode* leftNode = root->left;
		TreeNode* rightNode = root->right;
		TreeNode* zeroNode = new TreeNode(0);
		TreeNode* curNode = zeroNode;

		//左子树右子树均不为空时的展开操作
		while (leftNode != NULL && rightNode != NULL) {
			if (leftNode->val < rightNode->val) {
				curNode->right = leftNode;
				leftNode = leftNode->right;
			}
			else {
				curNode->right = rightNode;
				rightNode = rightNode->right;
			}
			curNode = curNode->right;
		}


		if (leftNode == NULL) {//左孩子为空，右孩子不为空
			curNode->right = rightNode;
			while (rightNode != NULL) {
				rightNode = rightNode->right;
				curNode = curNode->right;
			}
		}
		else {//rightNode == NULL右孩子为空，左孩子不为空
			curNode->right = leftNode;
			while (leftNode != NULL) {
				leftNode = leftNode->right;
				curNode = curNode->right;
			}
		}

		//将根节点合并到链表中
		curNode = zeroNode;
		while (curNode->right != NULL && curNode->right->val < root->val)
			curNode = curNode->right;
		root->left = NULL;
		root->right = curNode->right;
		curNode->right = root;

		//删除原节点，返回新的根节点
		curNode = zeroNode->right;
		delete zeroNode;
		return curNode;
		
	}
public:
	void flatten(TreeNode* root) {
		root = flattenRoot(root);
	}
};

//利用给定的节点指针队列来生成二叉树，用于测试
TreeNode* generateTree(queue<TreeNode*>& oriQueue) {
	queue<TreeNode*> nodeQueue;

	TreeNode* root = oriQueue.front();
	nodeQueue.push(root);
	oriQueue.pop();

	while (!nodeQueue.empty()) {
		TreeNode* newNode = nodeQueue.front();
		nodeQueue.pop();
		if (newNode == NULL)
			continue;
		if (!oriQueue.empty()) {
			newNode->left = oriQueue.front();
			nodeQueue.push(oriQueue.front());
			oriQueue.pop();
		}
		if (!oriQueue.empty()) {
			newNode->right = oriQueue.front();
			nodeQueue.push(oriQueue.front());
			oriQueue.pop();
		}
	}

	return root;
}

//打印二叉树，测试用
void PrintTree(TreeNode* root) {
	queue<TreeNode*> memo;
	memo.push(root);
	while (!memo.empty()) {
		TreeNode* curNode = memo.front();
		memo.pop();
		if (curNode == NULL)
			cout << "NULL" << " ";
		else {
			cout << curNode->val << " ";
			if (!(curNode->left == NULL && curNode->right == NULL)) {
				memo.push(curNode->left);
				memo.push(curNode->right);
			}
		}
	}
	cout << endl;
}

int main() {
	queue<TreeNode*> oriQueue;
	oriQueue.push(new TreeNode(1));
	oriQueue.push(new TreeNode(2));
	oriQueue.push(NULL);
	oriQueue.push(new TreeNode(3));
	oriQueue.push(new TreeNode(4));
	oriQueue.push(new TreeNode(5));

	TreeNode* root = generateTree(oriQueue);
	Solution().flatten(root);
	PrintTree(root);

	system("pause");
	return 0;
}