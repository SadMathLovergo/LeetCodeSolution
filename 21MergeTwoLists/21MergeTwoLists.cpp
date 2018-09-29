#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*创建链表操作*/
ListNode* CreateLinkedList(int arr[], int n) {
	if (n == 0)
		return NULL;

	ListNode* head = new ListNode(arr[0]);

	ListNode* curNode = head;
	for (int i = 1; i < n; i++) {
		curNode->next = new ListNode(arr[i]);
		curNode = curNode->next;
	}

	return head;
}

/*打印链表操作*/
void PrintLinkedList(ListNode* head) {
	ListNode* curNode = head;
	while (curNode != NULL) {
		cout << curNode->val << "->";
		curNode = curNode->next;
	}

	cout << "NULL" << endl;
}

/*删除链表操作*/
void DeleteLinkedList(ListNode* head) {
	ListNode* curNode = head;

	while (curNode != NULL) {
		ListNode* deleteNode = curNode;
		curNode = curNode->next;
		delete deleteNode;
	}
}

class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		ListNode* head = new ListNode(0);
		ListNode* curNode = head;
		ListNode* l1Node = l1;
		ListNode* l2Node = l2;

		while (l1 != NULL && l2 != NULL) {
			if (l1->val < l2->val) {
				curNode->next = l1;
				curNode = curNode->next;
				l1 = l1->next;
			}
			else
			{
				curNode->next = l2;
				curNode = curNode->next;
				l2 = l2->next;
			}
		}

		while (l1 != NULL) {
			curNode->next = l1;
			curNode = curNode->next;
			l1 = l1->next;
		}

		while (l2 != NULL) {
			curNode->next = l2;
			curNode = curNode->next;
			l2 = l2->next;
		}

		curNode = head->next;
		delete head;
		return curNode;
	}
};