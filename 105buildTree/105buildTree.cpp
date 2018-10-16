#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*��105�� ��ǰ�������������й��������*/
//����˼·��ǰ�����˳��Ϊ�����ڵ�->������->���������������˳��Ϊ��������->���ڵ�->������
//�ҵ����ڵ�����������е�λ�ã�����֪���˸��ڵ����ӽڵ��Լ��Һ��ӽڵ�
class Solution {
private:
	//�ҵ�preorder[curIndex]��inorder�е�λ��([indexL,indexR]��)�������ҵ�preorder[curIndex]�����ӽڵ���Һ��ӽڵ�
	TreeNode * findRoot(vector<int>& preorder, int curIndex, vector<int>& inorder, int indexL, int indexR) {
		//��indexL>indexRʱ����ζ�Ŵ˺��ӽڵ�ΪNULL
		if (curIndex >= preorder.size() ||  indexL > indexR)
			return NULL;

		TreeNode* newNode = new TreeNode(preorder[curIndex]);
		//preorder[curIndex]��inorder�е�����ΪindexL+newIndex����������ΪnewIndex�����Һ�������ΪindexR-indexL-newIndex��
		//���preorder[curIndex]�����ӽڵ�Ϊpreorder[curIndex+1]���Һ��ӽڵ�Ϊpreorder[curIndex+newIndex+1]��������ڵĻ�
		//���ӽڵ�preorder[curIndex+1]��inorder�е�������ΧΪ[indexL,indexL+newIndex-1]
		//�Һ��ӽڵ�preorder[curIndex+newIndex+1]��inorder�е�������ΧΪ[indexL+newIndex+1,indexR]
		int newIndex = 0;
		for (int i = indexL; i <= indexR; i++)
			if (inorder[i] == preorder[curIndex])
				break;
			else
				newIndex++;

		newNode->left = findRoot(preorder, curIndex + 1, inorder, indexL, indexL + newIndex - 1);
		newNode->right = findRoot(preorder, curIndex + newIndex + 1, inorder, indexL + newIndex + 1, indexR);
		return newNode;
	}
public:
	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {
		return findRoot(preorder, 0, inorder, 0, preorder.size() - 1);
	}
};

int main() {
	vector<int> preorder{ 3,9,20,115,7 };
	vector<int> inorder{ 9,3,15,20,7 };
	TreeNode* newNode = Solution().buildTree(preorder, inorder);

	system("pause");
	return 0;
}