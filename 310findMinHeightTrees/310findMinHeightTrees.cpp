#pragma once
#include <vector>
#include <queue>
using namespace std;

//��310�� ��С�߶���
//����˼·��
//����ıߵ��м�ڵ�Ϊ���ڵ������һ������С�߶���
//�����ֻ��һ�������м�ڵ����������
//������ж��������м�ڵ�ֻ��һ��
//������Ҫ�ҵ����
//�������������ڵ㶼����ͨ�ģ���˶�����һ���ڵ����BFS�����������һ���ڵ㣬һ������ߵ�һ���˵�
//�ٶԴ˶˵����BFS�����Եõ�����һ���˵�
class Solution {
private:
	//�ڽӾ���
	vector<vector<bool>> graph;
	//��¼·��������
	vector<int> path;
	//������ȱ����������Ե�ǰ�ڵ�Ϊ���ڵ��������ߵ����һ���ڵ�
	int BFS(int index) {
		queue<int> heightRecord;
		//������ʼ�¼
		vector<bool> visitRecord(graph.size(), false);
		//������ڵ�
		heightRecord.push(index);
		visitRecord[index] = true;
		//��ǰ�ڵ�
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
	//����������ȱ�����Ѱ�Ҵ�fromIndex��endIndex��·��
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
		//��ʼ���ڽӾ���
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