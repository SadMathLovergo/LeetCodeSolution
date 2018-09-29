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
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* l1Node = l1;
		ListNode* l2Node = l2;
		ListNode* head = new ListNode(0);
		ListNode* curNode = head;
		int curNum = 0;
		int nextNum = 0;

		while (l1Node != NULL && l2Node != NULL) {
			curNum = l1Node->val + l2Node->val + nextNum;
			nextNum = curNum / 10;
			curNum = curNum % 10;
			l1Node = l1Node->next;
			l2Node = l2Node->next;
			ListNode* newNode = new ListNode(curNum);
			curNode->next = newNode;
			curNode = curNode->next;
		}

		while (l1Node != NULL) {
			curNum = l1Node->val + nextNum;
			nextNum = curNum / 10;
			curNum = curNum % 10;
			l1Node = l1Node->next;
			ListNode* newNode = new ListNode(curNum);
			curNode->next = newNode;
			curNode = curNode->next;
		}

		while (l2Node != NULL) {
			curNum = l2Node->val + nextNum;
			nextNum = curNum / 10;
			curNum = curNum % 10;
			l2Node = l2Node->next;
			ListNode* newNode = new ListNode(curNum);
			curNode->next = newNode;
			curNode = curNode->next;
		}

		if (nextNum != 0) {
			ListNode* newNode = new ListNode(nextNum);
			curNode->next = newNode;
			curNode = curNode->next;
		}

		curNode = head->next;
		delete head;
		return curNode;
	}
};