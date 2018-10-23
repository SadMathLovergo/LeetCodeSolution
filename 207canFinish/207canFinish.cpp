#include <vector>
#include <iostream>
using namespace std;

//第207题 课程表
//解题思路：查看是否存在循环
//使用DFS来查找是否存在循环
class Solution {
private:
	vector<bool> hasBeenFinished;				//用于保存在DFS过程中，图的遍历情况，为了实现递归回溯，true为已遍历，false为未遍历
	vector<bool> canBeFinished;				//用于保存每个节点是否可以被遍历，用于最后查看所有的节点是否都能遍历
	vector<bool> needPrerequisites;				//needPrerequisites[i]为是否有指向i的路径
	vector<vector<int>> prerequisitesMemo;		//用于保存图的路径,prerequisitesVec[i][j]为true意味着存在i->prerequisitesVec[i][j]的路径

	//存在循环返回false，不存在循环返回true
	bool DFS(int index) {
		//遍历所有的路径
		for (int i = 0; i < prerequisitesMemo[index].size(); i++) {
			//若已遍历过此节点
			if (hasBeenFinished[prerequisitesMemo[index][i]])
				return false;
			else {//若没遍历过此节点，则继续对此节点进行DFS，递归回溯
				hasBeenFinished[prerequisitesMemo[index][i]] = true;
				if (!DFS(prerequisitesMemo[index][i]))
					return false;
				hasBeenFinished[prerequisitesMemo[index][i]] = false;
			}
		}
		//若不存在循环
		canBeFinished[index] = true;
		return true;
	}
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		hasBeenFinished = vector<bool>(numCourses, false);
		canBeFinished = vector<bool>(numCourses, false);
		needPrerequisites = vector<bool>(numCourses, false);
		prerequisitesMemo = vector<vector<int>>(numCourses, vector<int>());

		for (int i = 0; i < prerequisites.size(); i++) {
			prerequisitesMemo[prerequisites[i].second].push_back(prerequisites[i].first);
			needPrerequisites[prerequisites[i].first] = true;
		}

		bool hasBegin = false;

		//对所有没有先决条件的节点进行遍历
		for (int i = 0; i < numCourses; i++)
			if (!needPrerequisites[i]) {//若此节点没有先决条件
				hasBegin = true;
				hasBeenFinished[i] = true;
				canBeFinished[i] = true;
				if (!DFS(i))//若存在循环，则返回false
					return false;
			}

		//若没有遍历到节点，即所有节点都有先决条件
		if (!hasBegin)
			return false;

		//若有节点无法被遍历，则意味着存在循环
		for (int i = 0; i < numCourses; i++)
			if (!canBeFinished[i])
				return false;

		return true;
	}
};

int main() {
	int numCourses = 8;
	vector<pair<int, int>> prerequisites;
	prerequisites.push_back(make_pair(1, 0));
	prerequisites.push_back(make_pair(2, 6));
	prerequisites.push_back(make_pair(1, 7));
	prerequisites.push_back(make_pair(5, 1));
	prerequisites.push_back(make_pair(6, 4));
	prerequisites.push_back(make_pair(7, 0));
	prerequisites.push_back(make_pair(0, 5));

	bool res = Solution().canFinish(numCourses, prerequisites);
	if (res)
		cout << "可以完成所有课程" << endl;
	else
		cout << "无法完成所有课程" << endl;

	system("pause");
	return 0;
}