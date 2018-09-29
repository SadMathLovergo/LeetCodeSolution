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
	ListNode * rotateRight(ListNode* head, int k) {
		if (head == NULL)
			return NULL;

		ListNode* curNode = head;
		int countNum = 1;

		while (curNode->next != NULL) {
			curNode = curNode->next;
			countNum++;
		}

		k %= countNum;
		if (k == 0)
			return head;

		ListNode* startNode = head;
		ListNode* endNode = head;
		for (int i = 0; i < k; i++) {
			endNode = endNode->next;
		}

		while (endNode->next != NULL) {
			startNode = startNode->next;
			endNode = endNode->next;
		}

		curNode = startNode->next;
		startNode->next = NULL;
		endNode->next = head;

		return curNode;
	}
};