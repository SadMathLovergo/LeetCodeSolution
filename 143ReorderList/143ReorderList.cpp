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
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL || head->next->next == NULL)
			return ;

		ListNode* startNode = head;
		ListNode* endNode = head->next;

		/*获取中间指针*/
		while (endNode->next != NULL) {
			startNode = startNode->next;

			endNode = endNode->next;
			if (endNode->next == NULL)
				break;
			endNode = endNode->next;
		}

		/*翻转第二部分*/
		ListNode* node1 = startNode->next;
		ListNode* node2 = node1->next;
		ListNode* nextNode;
		node1->next = NULL;
		startNode->next = NULL;
		if (node2 != NULL) {
			do
			{
				nextNode = node2->next;

				node2->next = node1;
				node1 = node2;
				node2 = nextNode;
			} while (nextNode!=NULL);
		}

		/*给链表重新排序*/
		ListNode* leftCurNode = head;
		ListNode* leftNexNode = leftCurNode;
		ListNode* rightCurNode = node1;
		ListNode* rightNexNode = rightCurNode;
		while (rightCurNode != NULL) {
			leftNexNode = leftNexNode->next;
			rightNexNode = rightNexNode->next;

			rightCurNode->next = leftNexNode;
			leftCurNode->next = rightCurNode;

			rightCurNode = rightNexNode;
			leftCurNode = leftNexNode;
		}
	}
};

int main() {
	int arr[]{ 1,2,3,4 };
	ListNode* head = CreateLinkedList(arr, sizeof(arr) / sizeof(int));
	Solution solution;
	solution.reorderList(head);
	PrintLinkedList(head);
	DeleteLinkedList(head);

	system("pause");
	return 0;
}