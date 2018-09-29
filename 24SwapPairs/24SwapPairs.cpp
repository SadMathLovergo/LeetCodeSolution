#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*�����������*/
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

/*��ӡ�������*/
void PrintLinkedList(ListNode* head) {
	ListNode* curNode = head;
	while (curNode != NULL) {
		cout << curNode->val << "->";
		curNode = curNode->next;
	}

	cout << "NULL" << endl;
}

/*ɾ���������*/
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
	ListNode * swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* dummyNode = new ListNode(0);
		dummyNode->next = head;

		ListNode* pNode = dummyNode;

		while (pNode->next != NULL && pNode->next->next != NULL)
		{
			ListNode* node1 = pNode->next;
			ListNode* node2 = node1->next;
			ListNode* nextNode = node2->next;

			node1->next = nextNode;
			node2->next = node1;
			pNode->next = node2;

			pNode = node1;
		}

		pNode = dummyNode->next;
		delete dummyNode;
		return pNode;
	}
};