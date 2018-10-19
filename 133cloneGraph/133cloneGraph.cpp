#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

//第133题 克隆图
//解题思路：和138题的解题思路有相似之处，关键在于每个节点的neighbors如何赋值
class Solution {
private:
	vector<UndirectedGraphNode*> oriNodeVec;		//保存原节点的向量
	vector<UndirectedGraphNode*> newNodeVec;		//保存新节点的向量
	vector<vector<int>> neighborsMemo;				//保存所有节点的neighbors的索引向量
	stack<UndirectedGraphNode*> oriNodeStack;
	unordered_set<UndirectedGraphNode*> oriNodeSet;

public:
	UndirectedGraphNode * cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL)
			return node;

		oriNodeVec.push_back(node);
		oriNodeStack.push(node);
		oriNodeSet.insert(node);

		//保存所有的原节点
		while (!oriNodeStack.empty()) {
			UndirectedGraphNode* curNode = oriNodeStack.top();
			oriNodeStack.pop();
			//遍历所有的邻居节点
			for (int i = 0; i < curNode->neighbors.size(); i++) {
				UndirectedGraphNode* newNode = curNode->neighbors[i];
				//若此邻居节点不存在
				if (oriNodeSet.find(newNode) == oriNodeSet.end()) {
					oriNodeVec.push_back(newNode);
					oriNodeStack.push(newNode);
					oriNodeSet.insert(newNode);
				}
			}
		}

		//记录所有节点的neighbors的索引
		int nodeSize = oriNodeVec.size();
		neighborsMemo = vector<vector<int>>(nodeSize, vector<int>());
		//遍历每一个节点
		for (int i = 0; i < nodeSize; i++) {
			for (int j = 0; j < oriNodeVec[i]->neighbors.size(); j++) {
				//找到每一个邻居节点的索引
				UndirectedGraphNode* neighborNode = oriNodeVec[i]->neighbors[j];
				for (int k = 0; k < nodeSize; k++) {
					if (neighborNode == oriNodeVec[k]) {
						neighborsMemo[i].push_back(k);
						break;
					}
				}
			}
		}

		//复制所有节点
		for (int i = 0; i < nodeSize; i++) {
			UndirectedGraphNode* copyNode = new UndirectedGraphNode(oriNodeVec[i]->label);
			newNodeVec.push_back(copyNode);
		}

		//给所有节点的neighbors赋值
		for (int i = 0; i < nodeSize; i++) {
			for (int j = 0; j < neighborsMemo[i].size(); j++)
				newNodeVec[i]->neighbors.push_back(newNodeVec[neighborsMemo[i][j]]);
		}

		return newNodeVec[0];
	}
};