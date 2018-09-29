#include <iostream>
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
private:
	ListNode * sortList(ListNode* headNode, ListNode* endNode) {
		if (headNode == endNode)
			return headNode;
		/*�ҵ��м�ڵ�*/
		ListNode* mediumNode = headNode;
		ListNode* lastNode = headNode->next;
		while (lastNode->next != NULL) {
			mediumNode = mediumNode->next;
			lastNode = lastNode->next;
			if (lastNode->next != NULL)
				lastNode = lastNode->next;
		}
		/*�����������м�Ͽ����ֱ�����*/
		ListNode* nextNode = mediumNode->next;
		mediumNode->next = NULL;
		ListNode* curNode1 = sortList(headNode, mediumNode);
		ListNode* curNode2 = sortList(nextNode, endNode);

		ListNode* newHead = new ListNode(0);
		ListNode* newHeadNode = newHead;
		/*���õ��������������������*/
		while (curNode1 != NULL && curNode2 != NULL) {
			if (curNode1->val <= curNode2->val) {
				newHeadNode->next = curNode1;
				newHeadNode = newHeadNode->next;
				curNode1 = curNode1->next;
			}
			else {
				newHeadNode->next = curNode2;
				newHeadNode = newHeadNode->next;
				curNode2 = curNode2->next;
			}
		}
		while (curNode1 != NULL) {
			newHeadNode->next = curNode1;
			newHeadNode = newHeadNode->next;
			curNode1 = curNode1->next;
		}
		while (curNode2 != NULL) {
			newHeadNode->next = curNode2;
			newHeadNode = newHeadNode->next;
			curNode2 = curNode2->next;
		}
		/*���������ͷ*/
		newHeadNode = newHead->next;
		delete newHead;
		return newHeadNode;
	}

public:
	ListNode * sortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* end = head;
		while (end->next != NULL)
			end = end->next;
		return sortList(head, end);
	}
};

int main() {
	int arr[]{ 4,2,1,3 };
	ListNode* head = CreateLinkedList(arr, sizeof(arr) / sizeof(int));
	PrintLinkedList(head);
	ListNode* newHead = Solution().sortList(head);
	PrintLinkedList(newHead);
	DeleteLinkedList(newHead);
	system("pause");
	return 0;
}