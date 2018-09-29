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
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummyNode = new ListNode(0);
		dummyNode->next = head;

		ListNode* startNode = dummyNode;
		ListNode* endNode = dummyNode;

		for (int i = 0; i < n; i++)
			endNode = endNode->next;

		while (endNode->next != NULL) {
			startNode = startNode->next;
			endNode = endNode->next;
		}

		ListNode* deleteNode = startNode->next;
		startNode->next = deleteNode->next;
		delete deleteNode;

		startNode = dummyNode->next;
		delete dummyNode;
		return startNode;
	}
};