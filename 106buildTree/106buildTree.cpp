#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*第106题 从中序和后序遍历序列构造二叉树*/
//解题思路：中序遍历顺序为：左子树->根节点->右子树，后序遍历顺序为：左子树->右子树->根节点
//找到根节点在中序遍历中的位置，即可知道此根节点左孩子的数量以及右孩子的数量
//在后序遍历中，根节点永远是最后一个遍历的节点，因此可以参考105题的解题思路
class Solution {
private:
	TreeNode * findRoot(vector<int>& inorder, int indexL, int indexR, vector<int>& postorder, int curIndex) {
		if (indexL > indexR || curIndex >= postorder.size())
			return NULL;

		TreeNode* newNode = new TreeNode(postorder[curIndex]);

		//postorder[curIndex]在inorder中的索引为indexL+newIndex，左孩子节点个数为newIndex个，右孩子节点个数为indexR-indexL-newIndex个
		//因此postorder[curIndex]的左孩子节点为postorder[curIndex-1-(indexR-indexL-newIndex)]，右孩子节点为postorder[curIndex-1]
		//左孩子节点在inorder中的索引范围为[indexL,indexL+newIndex-1]，右孩子节点在inorder中的索引范围为[indexL+newIndex+1,indexR]
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