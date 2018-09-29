#include <iostream>
#include <unordered_set>
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
	ListNode * partition(ListNode* head, int x) {
		ListNode* leftNode = new ListNode(0);
		ListNode* rightNode = new ListNode(0);
		ListNode* leftCurNode = leftNode;
		ListNode* rightCurNode = rightNode;
		ListNode* curNode = head;
		while (curNode != NULL) {
			if (curNode->val < x) {
				leftCurNode->next = curNode;
				leftCurNode = leftCurNode->next;
			}
			else
			{
				rightCurNode->next = curNode;
				rightCurNode = rightCurNode->next;
			}
			curNode = curNode->next;
		}

		leftCurNode->next = rightNode->next;
		rightCurNode->next = NULL;
		head = leftNode->next;

		delete leftNode;
		delete rightNode;

		return head;
	}
};

int main() {
	int arr[] = { 1,4,3,2,5,2 };
	ListNode* head = CreateLinkedList(arr, sizeof(arr) / sizeof(int));
	Solution solution;
	head = solution.partition(head, 3);
	PrintLinkedList(head);
	DeleteLinkedList(head);

	system("pause");
	return 0;
}