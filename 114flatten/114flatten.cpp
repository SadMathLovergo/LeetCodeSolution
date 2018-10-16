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

/*��114�� ������չ��Ϊ����*/
//����˼·��ֱ�ӵݹ�ͺã���Ҫ��ԥ
//�Ҳ���ԭ��û˵Ҫ�������������������꣬���ڶ����𣿺Ǻǣ��Ǻǣ�
//����ΪҪ����������������æ���˰��죬ԭ����ֱ�Ӱ�������������������оͺ�
class Solution {
private:
	//����rootΪ���ڵ�Ķ���������չ�������������µĸ��ڵ�
	TreeNode * flattenRoot(TreeNode* root) {
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return root;

		//��������������������չ������
		root->left = flattenRoot(root->left);
		root->right = flattenRoot(root->right);

		//�Ƚ����������������ϲ�����ʱ������������������չ������������������
		TreeNode* leftNode = root->left;
		TreeNode* rightNode = root->right;
		TreeNode* zeroNode = new TreeNode(0);
		TreeNode* curNode = zeroNode;

		//����������������Ϊ��ʱ��չ������
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


		if (leftNode == NULL) {//����Ϊ�գ��Һ��Ӳ�Ϊ��
			curNode->right = rightNode;
			while (rightNode != NULL) {
				rightNode = rightNode->right;
				curNode = curNode->right;
			}
		}
		else {//rightNode == NULL�Һ���Ϊ�գ����Ӳ�Ϊ��
			curNode->right = leftNode;
			while (leftNode != NULL) {
				leftNode = leftNode->right;
				curNode = curNode->right;
			}
		}

		//�����ڵ�ϲ���������
		curNode = zeroNode;
		while (curNode->right != NULL && curNode->right->val < root->val)
			curNode = curNode->right;
		root->left = NULL;
		root->right = curNode->right;
		curNode->right = root;

		//ɾ��ԭ�ڵ㣬�����µĸ��ڵ�
		curNode = zeroNode->right;
		delete zeroNode;
		return curNode;
		
	}
public:
	void flatten(TreeNode* root) {
		root = flattenRoot(root);
	}
};

//���ø����Ľڵ�ָ����������ɶ����������ڲ���
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

//��ӡ��������������
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