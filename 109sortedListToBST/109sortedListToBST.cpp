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

/*第109题：有序链表转二叉搜索树*/
//解题思路：找到合适的根节点，让左孩子和右孩子的数量相差不超过1
class Solution {
private:
	//在head和end之间找到中间的ListNode，作为新的TreeNode
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