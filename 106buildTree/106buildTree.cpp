#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*��106�� ������ͺ���������й��������*/
//����˼·���������˳��Ϊ��������->���ڵ�->���������������˳��Ϊ��������->������->���ڵ�
//�ҵ����ڵ�����������е�λ�ã�����֪���˸��ڵ����ӵ������Լ��Һ��ӵ�����
//�ں�������У����ڵ���Զ�����һ�������Ľڵ㣬��˿��Բο�105��Ľ���˼·
class Solution {
private:
	TreeNode * findRoot(vector<int>& inorder, int indexL, int indexR, vector<int>& postorder, int curIndex) {
		if (indexL > indexR || curIndex >= postorder.size())
			return NULL;

		TreeNode* newNode = new TreeNode(postorder[curIndex]);

		//postorder[curIndex]��inorder�е�����ΪindexL+newIndex�����ӽڵ����ΪnewIndex�����Һ��ӽڵ����ΪindexR-indexL-newIndex��
		//���postorder[curIndex]�����ӽڵ�Ϊpostorder[curIndex-1-(indexR-indexL-newIndex)]���Һ��ӽڵ�Ϊpostorder[curIndex-1]
		//���ӽڵ���inorder�е�������ΧΪ[indexL,indexL+newIndex-1]���Һ��ӽڵ���inorder�е�������ΧΪ[indexL+newIndex+1,indexR]
		int newIndex = 0;
		for (int i = indexL; i <= indexR; i++)
			if (inorder[i] == postorder[curIndex])
				break;
			else
				newIndex++;

		newNode->left = findRoot(inorder, indexL, indexL + newIndex - 1, postorder, curIndex - 1 - indexR + indexL + newIndex);
		newNode->right = findRoot(inorder, indexL + newIndex + 1, indexR, postorder, curIndex - 1);

		return newNode;
	}
public:
	TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
		return findRoot(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
	}
};