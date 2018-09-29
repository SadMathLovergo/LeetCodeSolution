#include <iostream>
#include <unordered_map>
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
		unordered_map<int, int> recordMap;
		ListNode* curNode = head;

		while (curNode != NULL) {
			recordMap[curNode->val]++;
			curNode = curNode->next;
		}

		for (unordered_map<int, int>::iterator iter = recordMap.begin(); iter != recordMap.end(); iter++) {
			if (iter->second > 1) {
				iter->second = 0;
			}
		}

		ListNode* dummyNode = new ListNode(0);
		dummyNode->next = head;
		curNode = dummyNode;
		while (curNode->next != NULL) {
			if (recordMap[curNode->next->val] == 0) {
				ListNode* deleteNode = curNode->next;
				curNode->next = deleteNode->next;
				delete deleteNode;
			}
			else
			{
				curNode = curNode->next;
			}
		}

		curNode = dummyNode->next;
		delete dummyNode;
		return curNode;
	}
};