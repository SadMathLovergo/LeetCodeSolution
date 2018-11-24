#pragma once
#include <vector>
#include <queue>
using namespace std;

//第310题 最小高度数
//解题思路：
//以最长的边的中间节点为根节点的树，一定是最小高度树
//若最长边只有一条，则中间节点可能有两个
//若最长边有多条，则中间节点只有一个
//首先需要找到最长边
//由于任意两个节点都是连通的，因此对任意一个节点进行BFS，遍历的最后一个节点，一定是最长边的一个端点
//再对此端点进行BFS，可以得到另外一个端点
class Solution {
private:
	//邻接矩阵
	vector<vector<bool>> graph;
	//记录路径的数组
	vector<int> path;
	//广度优先遍历，返回以当前节点为根节点的树的最长边的最后一个节点
	int BFS(int index) {
		queue<int> heightRecord;
		//保存访问记录
		vector<bool> visitRecord(graph.size(), false);
		//放入根节点
		heightRecord.push(index);
		visitRecord[index] = true;
		//当前节点
		int curNode = index;
		//BFS
		while (!heightRecord.empty()) {
			curNode = heightRecord.front();
			for (int i = 0; i < graph.size(); i++)
				if (graph[curNode][i] && !visitRecord[i]) {
					heightRecord.push(i);
					visitRecord[i] = true;
				}
			heightRecord.pop();
		}
		return curNode;
	}
	//利用深度优先遍历，寻找从fromIndex到endIndex的路径
	bool DFS(int fromIndex, int endIndex) {
		for(int i = 0; i < graph.size(); i++)
			if (graph[fromIndex][i]) {
				path.push_back(i);
				if (i == endIndex)
					return true;
				graph[fromIndex][i] = false;
				graph[i][fromIndex] = false;
				if (DFS(i, endIndex)) {
					graph[fromIndex][i] = true;
					graph[i][fromIndex] = true;
					return true;
				}
				path.pop_back();
				graph[fromIndex][i] = true;
				graph[i][fromIndex] = true;
			}
		return false;
	}

public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if (n == 2)
			return vector<int>{0, 1};
		//初始化邻接矩阵
		graph = vector<vector<bool>>(n, vector<bool>(n, false));
		for (int i = 0; i < edges.size(); i++) {
			graph[edges[i].first][edges[i].second] = true;
			graph[edges[i].second][edges[i].first] = true;
		}

		int beginPort = BFS(0);
		int endPoint = BFS(beginPort);
		path.push_back(beginPort);
		DFS(beginPort, endPoint);

		if (path.size() % 2 == 1)
			return vector<int>{path[path.size() / 2]};
		else
			return vector<int>{path[path.size() / 2 - 1], path[path.size() / 2]};
	}
};