#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return false;

		ListNode* newNode = new ListNode(0);
		ListNode* curNode = head;
		while (curNode != NULL) {
			ListNode* nextNode = curNode->next;
			if (nextNode == newNode)
				return true;
			curNode->next = newNode;
			curNode = nextNode;
		}

		return false;
	}
};