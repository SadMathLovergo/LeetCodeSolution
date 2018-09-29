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
public:
	ListNode * reverseBetween(ListNode* head, int m, int n) {
		if (m == n)
			return head;
		/*oriNodeΪ��m-1���ڵ㣬��mΪ1����oriNodeΪNULL*/
		/*filNodeΪ��n+1���ڵ�*/
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
		/*����[m,n-1]�Ľڵ㣬�ı�ÿ���ڵ��nextָ�룬ָ��ǰһ���ڵ㣬���У���m���ڵ�ָ���n+1���ڵ�*/
		for (int i = 0; i < n - m; i++) {
			curNode->next = preNode;
			preNode = curNode;
			curNode = nextNode;
			nextNode = nextNode->next;
		}
		/*�õ�n���ڵ�ָ���n+1���ڵ�*/
		curNode->next = preNode;

		if (m == 1)
			return curNode;
		/*�õ�m-1���ڵ�ָ���n���ڵ�*/
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