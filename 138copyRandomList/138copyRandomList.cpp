#include <iostream>
#include <vector>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/*��138�� ���ƴ����ָ�������*/
//����˼·���Ƚ�ÿһ���ڵ㱣����vector�У�Ȼ��ÿһ���ڵ��randomָ��ָ������м�¼����
//�����ÿһ���ڵ㣬����ÿһ���ڵ��nextָ���randomָ�븳ֵ
class Solution {
public:
	RandomListNode * copyRandomList(RandomListNode *head) {
		if (head == NULL)
			return head;

		//�������е�ԭ�ڵ�ָ��
		vector<RandomListNode*> oriListNode;

		RandomListNode* curNode = head;
		while (curNode != NULL) {
			oriListNode.push_back(curNode);
			curNode = curNode->next;
		}

		int nodeNum = oriListNode.size();

		//�������е�randomָ�������
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

		//�������еĽڵ�
		vector<RandomListNode*> newListNode;
		for (int i = 0; i < nodeNum; i++) {
			RandomListNode* newNode = new RandomListNode(oriListNode[i]->label);
			newListNode.push_back(newNode);
		}
		//�����нڵ��nextָ���randomָ�븳ֵ
		for (int i = 0; i < nodeNum - 1; i++) {
			newListNode[i]->next = newListNode[i + 1];
			newListNode[i]->random = randomMemo[i] != -1 ? newListNode[randomMemo[i]] : NULL;
		}

		newListNode[nodeNum - 1]->random = randomMemo[nodeNum - 1] != -1 ? newListNode[randomMemo[nodeNum - 1]] : NULL;

		//���ؽ��
		return newListNode[0];
	}
};