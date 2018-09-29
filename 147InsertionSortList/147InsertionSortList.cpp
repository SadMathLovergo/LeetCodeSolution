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
	ListNode * insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* dummyNode = new ListNode(0);
		dummyNode->next = head;

		ListNode* curNode = head;
		while (curNode->next != NULL) {
			ListNode* deleteNode = curNode->next;
			ListNode* nextNode = deleteNode->next;

			int curNum = deleteNode->val;
			curNode->next = nextNode;
			delete deleteNode;

			ListNode* testNode = dummyNode;
			for (; testNode != curNode; testNode = testNode->next) {
				if (testNode->next->val >= curNum)
					break;
			}

			ListNode* newNode = new ListNode(curNum);
			newNode->next = testNode->next;
			testNode->next = newNode;
			if (curNode == testNode)
				curNode = curNode->next;
		}

		curNode = dummyNode->next;
		delete dummyNode;

		return curNode;
	}
};

int main() {
	int arr[]{ -1,5,3,4,0 };
	ListNode* head = CreateLinkedList(arr, sizeof(arr) / sizeof(int));
	Solution solution;
	head = solution.insertionSortList(head);
	PrintLinkedList(head);
	DeleteLinkedList(head);

	system("pause");
	return 0;
}