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
	ListNode * removeElements(ListNode* head, int val) {
		ListNode* dummyNode = new ListNode(0);
		dummyNode->next = head;

		ListNode* curNode = dummyNode;
		while (curNode->next != NULL) {
			ListNode* deleteNode = curNode->next;
			if (deleteNode->val == val) {
				curNode->next = deleteNode->next;
				delete deleteNode;
			}
			else
				curNode = curNode->next;
		}

		ListNode* returnNode = dummyNode->next;
		delete dummyNode;

		return returnNode;
	}
};

int main() {
	int arr[] = { 1,2,3,4,5 };
	ListNode* head = CreateLinkedList(arr, sizeof(arr) / sizeof(int));
	PrintLinkedList(head);

	Solution solution;
	ListNode* returnNode = solution.removeElements(head, 3);

	PrintLinkedList(returnNode);

	DeleteLinkedList(returnNode);

	system("pause");
	return 0;
}