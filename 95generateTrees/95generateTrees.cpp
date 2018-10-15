#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*��95�� ��ͬ�Ķ���������2*/
//����˼·��ͬ��ʹ�ö�̬�滮��˼·��ֻ������Ҫ����������������ͬʱ��Ҫ�Զ�����������ֵ�����޸�
class Solution {
private:
	//�Եݹ�ķ�ʽ����������������ͬʱ��ֵ�����޸�
	TreeNode * copyTrees(TreeNode* oriNode, int deltaNum) {
		if (oriNode == NULL)
			return NULL;
		TreeNode* newNode = new TreeNode(oriNode->val + deltaNum);
		newNode->left = copyTrees(oriNode->left, deltaNum);
		newNode->right = copyTrees(oriNode->right, deltaNum);
		return newNode;
	}

public:
	vector<TreeNode*> generateTrees(int n) {
		//treesMemo[i]�б�����ǽڵ�1~�ڵ�i���еĶ�������������ĸ��ڵ�
		vector<vector<TreeNode*>> treesMemo(n + 1, vector<TreeNode*>());

		//�������iΪ0��ֱ�ӷ���
		if (n == 0)
			return treesMemo[0];

		treesMemo[0].push_back(NULL);
		treesMemo[1].push_back(new TreeNode(1));

		//����ڵ�1~�ڵ�i���ܹ��ɵ����еĶ���������
		for (int i = 2; i <= n; i++) {
			//�Խڵ�jΪ���ڵ�ʱ
			for (int j = 1; j <= i; j++) {
				//���ڵ��������Ϊ�ڵ�1~�ڵ�j-1���ɵĶ���������
				for(vector<TreeNode*>::iterator leftIter = treesMemo[j-1].begin(); leftIter!=treesMemo[j-1].end(); leftIter++)
					//���ڵ�������Ϊ�ڵ�j+1~�ڵ�i���ɵĶ���������
					for (vector<TreeNode*>::iterator rightIter = treesMemo[i - j].begin(); rightIter != treesMemo[i - j].end(); rightIter++) {
						TreeNode* newNode = new TreeNode(j);
						newNode->left = copyTrees(*leftIter, 0);
						newNode->right = copyTrees(*rightIter, j);
						treesMemo[i].push_back(newNode);
					}
			}
		}

		return treesMemo[n];
	}
};