#include <vector>
#include <iostream>
using namespace std;

//第210题 课程表2
//解题思路：查看是否存在循环，在查看的过程中记录路径
//使用DFS来查找是否存在循环
class Solution {
private:
	vector<bool> hasBeenFinished;				//用于保存在DFS过程中，图的遍历情况，为了实现递归回溯，true为已遍历，false为未遍历
	vector<bool> canBeFinished;					//用于保存每个节点是否可以被遍历，用于最后查看所有的节点是否都能遍历
	vector<bool> needPrerequisites;				//needPrerequisites[i]为是否有指向节点i的路径，true为有，false为没有
	vector<vector<int>> prerequisitesMemo;		//用于保存图的路径,prerequisitesVec[i][j]为true意味着存在i->prerequisitesVec[i][j]的路径
	vector<int> pathMemo;						//用于在DFS过程中保存路径

	//存在循环返回false，不存在循环返回true
	bool DFS(int index) {
		//若此节点可以遍历，则必然已经遍历过，并且已经在pathMemo中
		if (canBeFinished[index])
			return true;
		//遍历所有的路径
		for (int i = 0; i < prerequisitesMemo[index].size(); i++) {
			//若已遍历过此节点
			if (hasBeenFinished[prerequisitesMemo[index][i]]) {
				return false;
			}
			else {//若没遍历过此节点，则继续对此节点进行DFS，递归回溯
				hasBeenFinished[prerequisitesMemo[index][i]] = true;
				if (!DFS(prerequisitesMemo[index][i])) {
					return false;
				}
				hasBeenFinished[prerequisitesMemo[index][i]] = false;
			}
		}
		//若不存在循环，则将此节点放入pathMemo中，并返回true，因此pathMemo中的路径为倒序路径
		pathMemo.push_back(index);
		canBeFinished[index] = true;
		return true;
	}

public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		hasBeenFinished = vector<bool>(numCourses, false);
		canBeFinished = vector<bool>(numCourses, false);
		needPrerequisites = vector<bool>(numCourses, false);
		prerequisitesMemo = vector<vector<int>>(numCourses, vector<int>());

		for (int i = 0; i < prerequisites.size(); i++) {
			prerequisitesMemo[prerequisites[i].second].push_back(prerequisites[i].first);
			needPrerequisites[prerequisites[i].first] = true;
		}

		//对所有没有先决条件的节点进行遍历
		for (int i = 0; i < numCourses; i++)
			if (!needPrerequisites[i]) {//若此节点没有先决条件
				hasBeenFinished[i] = true;
				if (!DFS(i))//若存在循环，则返回空数组
					return vector<int>();
			}

		//若没有遍历到节点，即所有节点都有先决条件，返回空数组
		if (pathMemo.empty())
			return pathMemo;

		//若有节点无法被遍历，则意味着存在循环，返回空数组
		for (int i = 0; i < numCourses; i++)
			if (!canBeFinished[i])
				return vector<int>();

		//若存在一条路径，则返回此路径
		return vector<int>(pathMemo.rbegin(), pathMemo.rend());
	}
};

int main() {
	int numCourses = 4;
	vector<pair<int, int>> prerequisites;
	prerequisites.push_back(make_pair(1, 0));
	prerequisites.push_back(make_pair(2, 0));
	prerequisites.push_back(make_pair(3, 1));
	prerequisites.push_back(make_pair(3, 2));

	vector<int> res = Solution().findOrder(numCourses, prerequisites);
	if (res.empty())
		cout << "无法完成所有课程" << endl;
	else {
		cout << res[0];
		for (int i = 1; i < res.size(); i++)
			cout << "->" << res[i];
		cout << endl;
	}

	system("pause");
	return 0;
}