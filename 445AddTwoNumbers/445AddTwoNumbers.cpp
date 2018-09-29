#include <iostream>
#include <stack>
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
		stack<int> record1;
		stack<int> record2;
		stack<int> resultStack;
		ListNode* curNode;

		int curNum = 0;
		int nextNum = 0;
		/*将第一个链表数字压入堆栈，从高位到低位*/
		curNode = l1;
		while (curNode != NULL) {
			record1.push(curNode->val);
			curNode = curNode->next;
		}
		/*将第二个链表数字压入堆栈，从高位到低位*/
		curNode = l2;
		while (curNode != NULL) {
			record2.push(curNode->val);
			curNode = curNode->next;
		}

		ListNode* head = new ListNode(0);
		curNode = head;

		/*将计算结果压入堆栈，从低位到高位*/
		while (!record1.empty() && !record2.empty()) {
			curNum = record1.top() + record2.top() + nextNum;
			nextNum = curNum / 10;
			curNum %= 10;
			record1.pop();
			record2.pop();

			resultStack.push(curNum);
		}

		while (!record1.empty()) {
			curNum = record1.top() + nextNum;
			nextNum = curNum / 10;
			curNum %= 10;
			record1.pop();

			resultStack.push(curNum);
		}

		while (!record2.empty()) {
			curNum = record2.top() + nextNum;
			nextNum = curNum / 10;
			curNum %= 10;
			record2.pop();

			resultStack.push(curNum);
		}

		if (nextNum != 0) {
			resultStack.push(nextNum);
		}

		/*从堆栈中弹出数字，从高位到低位创建链表*/
		while (!resultStack.empty()) {
			ListNode* newNode = new ListNode(resultStack.top());
			curNode->next = newNode;
			curNode = curNode->next;

			resultStack.pop();
		}

		curNode = head->next;
		delete head;

		return curNode;

	}
};