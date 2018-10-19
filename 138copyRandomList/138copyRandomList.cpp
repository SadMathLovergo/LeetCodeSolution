#include <iostream>
#include <vector>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/*第138题 复制带随机指针的链表*/
//解题思路：先将每一个节点保存至vector中，然后将每一个节点的random指针指向的序列记录下来
//随后复制每一个节点，并给每一个节点的next指针和random指针赋值
class Solution {
public:
	RandomListNode * copyRandomList(RandomListNode *head) {
		if (head == NULL)
			return head;

		//保存所有的原节点指针
		vector<RandomListNode*> oriListNode;

		RandomListNode* curNode = head;
		while (curNode != NULL) {
			oriListNode.push_back(curNode);
			curNode = curNode->next;
		}

		int nodeNum = oriListNode.size();

		//保存所有的random指针的序列
		vector<int> randomMemo;
		for (int i = 0; i < nodeNum; i++) {
			if (oriListNode[i]->random == NULL)
				randomMemo.push_back(-1);
			else {
				for(int j = 0; j < nodeNum; j++)
					if (oriListNode[i]->random == oriListNode[j]) {
						randomMemo.push_back(j);
						break;
					}
			}
		}

		//复制所有的节点
		vector<RandomListNode*> newListNode;
		for (int i = 0; i < nodeNum; i++) {
			RandomListNode* newNode = new RandomListNode(oriListNode[i]->label);
			newListNode.push_back(newNode);
		}
		//给所有节点的next指针和random指针赋值
		for (int i = 0; i < nodeNum - 1; i++) {
			newListNode[i]->next = newListNode[i + 1];
			newListNode[i]->random = randomMemo[i] != -1 ? newListNode[randomMemo[i]] : NULL;
		}

		newListNode[nodeNum - 1]->random = randomMemo[nodeNum - 1] != -1 ? newListNode[randomMemo[nodeNum - 1]] : NULL;

		//返回结果
		return newListNode[0];
	}
};