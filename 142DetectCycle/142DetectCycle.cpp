#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return NULL;
		unordered_set<ListNode*> record;
		ListNode* curNode = head;
		while (curNode != NULL) {
			if (record.find(curNode) != record.end())
				return curNode;
			record.insert(curNode);
			curNode = curNode->next;
		}
		return NULL;
	}
};