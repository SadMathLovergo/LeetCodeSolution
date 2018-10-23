#include <vector>
#include <iostream>
using namespace std;

//��207�� �γ̱�
//����˼·���鿴�Ƿ����ѭ��
//ʹ��DFS�������Ƿ����ѭ��
class Solution {
private:
	vector<bool> hasBeenFinished;				//���ڱ�����DFS�����У�ͼ�ı��������Ϊ��ʵ�ֵݹ���ݣ�trueΪ�ѱ�����falseΪδ����
	vector<bool> canBeFinished;				//���ڱ���ÿ���ڵ��Ƿ���Ա��������������鿴���еĽڵ��Ƿ��ܱ���
	vector<bool> needPrerequisites;				//needPrerequisites[i]Ϊ�Ƿ���ָ��i��·��
	vector<vector<int>> prerequisitesMemo;		//���ڱ���ͼ��·��,prerequisitesVec[i][j]Ϊtrue��ζ�Ŵ���i->prerequisitesVec[i][j]��·��

	//����ѭ������false��������ѭ������true
	bool DFS(int index) {
		//�������е�·��
		for (int i = 0; i < prerequisitesMemo[index].size(); i++) {
			//���ѱ������˽ڵ�
			if (hasBeenFinished[prerequisitesMemo[index][i]])
				return false;
			else {//��û�������˽ڵ㣬������Դ˽ڵ����DFS���ݹ����
				hasBeenFinished[prerequisitesMemo[index][i]] = true;
				if (!DFS(prerequisitesMemo[index][i]))
					return false;
				hasBeenFinished[prerequisitesMemo[index][i]] = false;
			}
		}
		//��������ѭ��
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

		//������û���Ⱦ������Ľڵ���б���
		for (int i = 0; i < numCourses; i++)
			if (!needPrerequisites[i]) {//���˽ڵ�û���Ⱦ�����
				hasBegin = true;
				hasBeenFinished[i] = true;
				canBeFinished[i] = true;
				if (!DFS(i))//������ѭ�����򷵻�false
					return false;
			}

		//��û�б������ڵ㣬�����нڵ㶼���Ⱦ�����
		if (!hasBegin)
			return false;

		//���нڵ��޷�������������ζ�Ŵ���ѭ��
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
		cout << "����������пγ�" << endl;
	else
		cout << "�޷�������пγ�" << endl;

	system("pause");
	return 0;
}