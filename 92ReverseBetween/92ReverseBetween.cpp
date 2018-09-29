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
	ListNode * reverseBetween(ListNode* head, int m, int n) {
		if (m == n)
			return head;
		/*oriNode为第m-1个节点，若m为1，则oriNode为NULL*/
		/*filNode为第n+1个节点*/
		ListNode* oriNode;
		ListNode* filNode;
		if (m == 1) {
			oriNode = NULL;
		}
		else
		{
			oriNode = head;
			for (int i = 0; i < m - 2; i++) {
				oriNode = oriNode->next;
			}
		}
		filNode = head;
		for (int i = 0; i < n; i++) {
			filNode = filNode->next;
		}

		ListNode* preNode = filNode;
		ListNode* curNode = m == 1 ? head : oriNode->next;
		ListNode* nextNode = curNode->next;
		/*遍历[m,n-1]的节点，改变每个节点的next指针，指向前一个节点，其中，第m个节点指向第n+1个节点*/
		for (int i = 0; i < n - m; i++) {
			curNode->next = preNode;
			preNode = curNode;
			curNode = nextNode;
			nextNode = nextNode->next;
		}
		/*让第n个节点指向第n+1个节点*/
		curNode->next = preNode;

		if (m == 1)
			return curNode;
		/*让第m-1个节点指向第n个节点*/
		oriNode->next = curNode;
		return head;
	}
};

int main() {
	Solution solution;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	ListNode* head = CreateLinkedList(arr, sizeof(arr) / sizeof(int));

	PrintLinkedList(head);

	head = solution.reverseBetween(head, 1, 10);

	PrintLinkedList(head);

	DeleteLinkedList(head);

	system("pause");
	return 0;
}