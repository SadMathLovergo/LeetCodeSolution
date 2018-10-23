#include <vector>
#include <iostream>
using namespace std;

//��210�� �γ̱�2
//����˼·���鿴�Ƿ����ѭ�����ڲ鿴�Ĺ����м�¼·��
//ʹ��DFS�������Ƿ����ѭ��
class Solution {
private:
	vector<bool> hasBeenFinished;				//���ڱ�����DFS�����У�ͼ�ı��������Ϊ��ʵ�ֵݹ���ݣ�trueΪ�ѱ�����falseΪδ����
	vector<bool> canBeFinished;					//���ڱ���ÿ���ڵ��Ƿ���Ա��������������鿴���еĽڵ��Ƿ��ܱ���
	vector<bool> needPrerequisites;				//needPrerequisites[i]Ϊ�Ƿ���ָ��ڵ�i��·����trueΪ�У�falseΪû��
	vector<vector<int>> prerequisitesMemo;		//���ڱ���ͼ��·��,prerequisitesVec[i][j]Ϊtrue��ζ�Ŵ���i->prerequisitesVec[i][j]��·��
	vector<int> pathMemo;						//������DFS�����б���·��

	//����ѭ������false��������ѭ������true
	bool DFS(int index) {
		//���˽ڵ���Ա��������Ȼ�Ѿ��������������Ѿ���pathMemo��
		if (canBeFinished[index])
			return true;
		//�������е�·��
		for (int i = 0; i < prerequisitesMemo[index].size(); i++) {
			//���ѱ������˽ڵ�
			if (hasBeenFinished[prerequisitesMemo[index][i]]) {
				return false;
			}
			else {//��û�������˽ڵ㣬������Դ˽ڵ����DFS���ݹ����
				hasBeenFinished[prerequisitesMemo[index][i]] = true;
				if (!DFS(prerequisitesMemo[index][i])) {
					return false;
				}
				hasBeenFinished[prerequisitesMemo[index][i]] = false;
			}
		}
		//��������ѭ�����򽫴˽ڵ����pathMemo�У�������true�����pathMemo�е�·��Ϊ����·��
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

		//������û���Ⱦ������Ľڵ���б���
		for (int i = 0; i < numCourses; i++)
			if (!needPrerequisites[i]) {//���˽ڵ�û���Ⱦ�����
				hasBeenFinished[i] = true;
				if (!DFS(i))//������ѭ�����򷵻ؿ�����
					return vector<int>();
			}

		//��û�б������ڵ㣬�����нڵ㶼���Ⱦ����������ؿ�����
		if (pathMemo.empty())
			return pathMemo;

		//���нڵ��޷�������������ζ�Ŵ���ѭ�������ؿ�����
		for (int i = 0; i < numCourses; i++)
			if (!canBeFinished[i])
				return vector<int>();

		//������һ��·�����򷵻ش�·��
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
		cout << "�޷�������пγ�" << endl;
	else {
		cout << res[0];
		for (int i = 1; i < res.size(); i++)
			cout << "->" << res[i];
		cout << endl;
	}

	system("pause");
	return 0;
}