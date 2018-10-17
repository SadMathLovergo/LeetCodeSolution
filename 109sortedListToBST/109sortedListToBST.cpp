#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*��109�⣺��������ת����������*/
//����˼·���ҵ����ʵĸ��ڵ㣬�����Ӻ��Һ��ӵ�����������1
class Solution {
private:
	//��head��end֮���ҵ��м��ListNode����Ϊ�µ�TreeNode
	TreeNode * findRoot(ListNode* head, ListNode* end) {
		if (head == end)
			return new TreeNode(head->val);
		ListNode* lastNode = head;
		ListNode* mediumNode = head;
		ListNode* endNode = head->next;

		while (endNode != end) {
			lastNode = mediumNode;
			mediumNode = mediumNode->next;
			endNode = endNode->next;
			if (endNode != end)
				endNode = endNode->next;
		}

		TreeNode* newTreeNode = new TreeNode(mediumNode->val);
		if (lastNode != mediumNode)
			newTreeNode->left = findRoot(head, lastNode);
		newTreeNode->right = findRoot(mediumNode->next, end);

		return newTreeNode;
	}

public:
	TreeNode * sortedListToBST(ListNode* head) {
		if (head == NULL)
			return NULL;

		ListNode* end = head;
		while (end->next != NULL)
			end = end->next;

		TreeNode* newHead = findRoot(head, end);

		return newHead;

	}
};