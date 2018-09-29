#include <iostream>
#include<queue>
#include<stack>
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
	bool isPalindrome(ListNode* head) {
		queue<int> QueueRecord;
		stack<int> StackRecord;
		ListNode* curNode = head;

		while (curNode != NULL) {
			QueueRecord.push(curNode->val);
			StackRecord.push(curNode->val);
			curNode = curNode->next;
		}

		while (!QueueRecord.empty()) {
			if (QueueRecord.front() != StackRecord.top())
				return false;
			QueueRecord.pop();
			StackRecord.pop();
		}

		return true;
	}
};