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
	ListNode * reverseKGroup(ListNode* head, int k) {
		if (k == 1)
			return head;

		ListNode* dummyNode = new ListNode(0);
		dummyNode->next = head;

		ListNode* p = dummyNode;

		while (p != NULL) {
			ListNode* lastNode = p;

			for (int i = 0; i < k; i++) {
				lastNode = lastNode->next;
				if (lastNode == NULL)
					break;
			}
			if (lastNode == NULL)
				break;

			ListNode* node1 = p->next;
			ListNode* node2 = node1->next;
			ListNode* nextNode;

			do
			{
				nextNode = node2->next;

				node2->next = node1;
				node1 = node2;
				node2 = nextNode;
			} while (node1 != lastNode);

			ListNode* newNode = p->next;
			p->next->next = node2;
			p->next = node1;

			p = newNode;
		}

		p = dummyNode->next;
		delete dummyNode;
		return p;
	}
};