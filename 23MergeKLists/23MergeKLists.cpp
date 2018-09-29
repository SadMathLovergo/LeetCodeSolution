#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool compare(pair<int, vector<ListNode*>> pair1, pair<int, vector<ListNode*>> pair2) {
	return pair1.first < pair2.first;
}

class Solution {
public:
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return NULL;

		/*先将所有节点根据节点值存入map中，格式为[节点值,节点指针向量]*/
		unordered_map<int, vector<ListNode*>> valMap;
		for (vector<ListNode*>::iterator iter = lists.begin(); iter != lists.end(); iter++) {
			ListNode* curNode = *iter;
			while (curNode != NULL) {
				valMap[curNode->val].push_back(curNode);
				curNode = curNode->next;
			}
		}

		/*根据节点的val值，将pair<节点值,节点指针向量>放入优先队列中，从小到大排列*/
		priority_queue < pair<int, vector<ListNode*>>, vector<pair<int, vector<ListNode*>>>, greater<pair<int, vector<ListNode*>>>> ListnodeQueue;
		for (unordered_map<int, vector<ListNode*>>::iterator iter = valMap.begin(); iter != valMap.end(); iter++)
			ListnodeQueue.push(make_pair(iter->first, iter->second));

		/*虚拟头结点，方便后续操作*/
		ListNode* beginNode = new ListNode(0);
		ListNode* curNode = beginNode;

		/*将节点按顺序连接起来*/
		while (!ListnodeQueue.empty()) {
			for (int i = 0; i < ListnodeQueue.top().second.size(); i++) {
				curNode->next = ListnodeQueue.top().second[i];
				curNode = curNode->next;
			}
			ListnodeQueue.pop();
		}
		curNode->next = NULL;

		curNode = beginNode->next;
		delete beginNode;
		return curNode;
	}
};