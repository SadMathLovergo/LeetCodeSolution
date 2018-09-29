#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * reverseList(ListNode* head) {
		ListNode* preNode = NULL;
		ListNode* curNode = head;
		ListNode* nextNode;
		while (curNode != NULL) {
			nextNode = curNode->next;

			curNode->next = preNode;
			preNode = curNode;
			curNode = nextNode;
			
		}
		return preNode;
	}
};