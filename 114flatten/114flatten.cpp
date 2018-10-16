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
//我擦，原题没说要按升序来排列链表,题目里的例子容易引起误解，尼玛，你在逗我吗？？呵呵！呵呵！
//我以为要按升序来排列链表，忙活了半天，原来是直接按先序遍历的序列来排列就好
//这简直不要太简单了
class Solution {
private:
	//对以root为根节点的二叉树进行展开操作，返回新的根节点
	TreeNode * flattenRoot(TreeNode* root) {
		if (root == NULL)
			return root;

		root->left = flattenRoot(root->left);
		root->right = flattenRoot(root->right);

		if (root->left == NULL)
			return root;

		TreeNode* leftNode = root->left;
		while (leftNode->right != NULL)
				leftNode = leftNode->right;
		leftNode->right = root->right;
		root->right = root->left;
		root->left = NULL;
		return root;
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