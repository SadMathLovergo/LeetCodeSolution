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
	ListNode * deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return NULL;

		ListNode* curNode = head;
		unordered_set<int> record;
		record.insert(head->val);

		while (curNode->next != NULL) {
			if (record.find(curNode->next->val) != record.end()) {
				ListNode* deleteNode = curNode->next;
				curNode->next = deleteNode->next;
				delete deleteNode;
			}
			else
			{
				record.insert(curNode->next->val);
				curNode = curNode->next;
			}
		}

		return head;
	}
};

int main() {
	int arr[] = { 1,2,2,3,3,3,4,5,4,5,6 };
	ListNode* head = CreateLinkedList(arr, sizeof(arr) / sizeof(int));
	Solution solution;
	head = solution.deleteDuplicates(head);
	PrintLinkedList(head);
	DeleteLinkedList(head);
	system("pause");
	return 0;
}