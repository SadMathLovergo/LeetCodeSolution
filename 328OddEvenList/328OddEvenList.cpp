#include <iostream>
#include <unordered_set>
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
	ListNode * oddEvenList(ListNode* head) {
		ListNode* leftNode = new ListNode(0);
		ListNode* rightNode = new ListNode(0);
		ListNode* leftCurNode = leftNode;
		ListNode* rightCurNode = rightNode;
		ListNode* curNode = head;
		int i = 1;

		while (curNode != NULL) {
			if (i % 2 == 1) {
				leftCurNode->next = curNode;
				leftCurNode = leftCurNode->next;
			}
			else
			{
				rightCurNode->next = curNode;
				rightCurNode = rightCurNode->next;
			}
			curNode = curNode->next;
			i++;
		}

		leftCurNode->next = rightNode->next;
		rightCurNode->next = NULL;
		delete leftNode;
		delete rightNode;

		return head;
	}
};

int main() {
	int arr[] = { 1,2,3,4,5,6 };
	ListNode* head = CreateLinkedList(arr, sizeof(arr) / sizeof(int));
	Solution solution;
	head = solution.oddEvenList(head);
	PrintLinkedList(head);
	DeleteLinkedList(head);

	system("pause");
	return 0;
}