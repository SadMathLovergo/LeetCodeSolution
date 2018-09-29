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

		/*�Ƚ����нڵ���ݽڵ�ֵ����map�У���ʽΪ[�ڵ�ֵ,�ڵ�ָ������]*/
		unordered_map<int, vector<ListNode*>> valMap;
		for (vector<ListNode*>::iterator iter = lists.begin(); iter != lists.end(); iter++) {
			ListNode* curNode = *iter;
			while (curNode != NULL) {
				valMap[curNode->val].push_back(curNode);
				curNode = curNode->next;
			}
		}

		/*���ݽڵ��valֵ����pair<�ڵ�ֵ,�ڵ�ָ������>�������ȶ����У���С��������*/
		priority_queue < pair<int, vector<ListNode*>>, vector<pair<int, vector<ListNode*>>>, greater<pair<int, vector<ListNode*>>>> ListnodeQueue;
		for (unordered_map<int, vector<ListNode*>>::iterator iter = valMap.begin(); iter != valMap.end(); iter++)
			ListnodeQueue.push(make_pair(iter->first, iter->second));

		/*����ͷ��㣬�����������*/
		ListNode* beginNode = new ListNode(0);
		ListNode* curNode = beginNode;

		/*���ڵ㰴˳����������*/
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