#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

//��133�� ��¡ͼ
//����˼·����138��Ľ���˼·������֮�����ؼ�����ÿ���ڵ��neighbors��θ�ֵ
class Solution {
private:
	vector<UndirectedGraphNode*> oriNodeVec;		//����ԭ�ڵ������
	vector<UndirectedGraphNode*> newNodeVec;		//�����½ڵ������
	vector<vector<int>> neighborsMemo;				//�������нڵ��neighbors����������
	stack<UndirectedGraphNode*> oriNodeStack;
	unordered_set<UndirectedGraphNode*> oriNodeSet;

public:
	UndirectedGraphNode * cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL)
			return node;

		oriNodeVec.push_back(node);
		oriNodeStack.push(node);
		oriNodeSet.insert(node);

		//�������е�ԭ�ڵ�
		while (!oriNodeStack.empty()) {
			UndirectedGraphNode* curNode = oriNodeStack.top();
			oriNodeStack.pop();
			//�������е��ھӽڵ�
			for (int i = 0; i < curNode->neighbors.size(); i++) {
				UndirectedGraphNode* newNode = curNode->neighbors[i];
				//�����ھӽڵ㲻����
				if (oriNodeSet.find(newNode) == oriNodeSet.end()) {
					oriNodeVec.push_back(newNode);
					oriNodeStack.push(newNode);
					oriNodeSet.insert(newNode);
				}
			}
		}

		//��¼���нڵ��neighbors������
		int nodeSize = oriNodeVec.size();
		neighborsMemo = vector<vector<int>>(nodeSize, vector<int>());
		//����ÿһ���ڵ�
		for (int i = 0; i < nodeSize; i++) {
			for (int j = 0; j < oriNodeVec[i]->neighbors.size(); j++) {
				//�ҵ�ÿһ���ھӽڵ������
				UndirectedGraphNode* neighborNode = oriNodeVec[i]->neighbors[j];
				for (int k = 0; k < nodeSize; k++) {
					if (neighborNode == oriNodeVec[k]) {
						neighborsMemo[i].push_back(k);
						break;
					}
				}
			}
		}

		//�������нڵ�
		for (int i = 0; i < nodeSize; i++) {
			UndirectedGraphNode* copyNode = new UndirectedGraphNode(oriNodeVec[i]->label);
			newNodeVec.push_back(copyNode);
		}

		//�����нڵ��neighbors��ֵ
		for (int i = 0; i < nodeSize; i++) {
			for (int j = 0; j < neighborsMemo[i].size(); j++)
				newNodeVec[i]->neighbors.push_back(newNodeVec[neighborsMemo[i][j]]);
		}

		return newNodeVec[0];
	}
};