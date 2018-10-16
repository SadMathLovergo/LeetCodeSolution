#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*第105题 从前序和中序遍历序列构造二叉树*/
//解题思路：前序遍历顺序为：根节点->左子树->右子树，中序遍历顺序为：左子树->根节点->右子树
//找到根节点在中序遍历中的位置，即可知道此根节点左孩子节点以及右孩子节点
class Solution {
private:
	//找到preorder[curIndex]在inorder中的位置([indexL,indexR]中)，即可找到preorder[curIndex]的左孩子节点和右孩子节点
	TreeNode * findRoot(vector<int>& preorder, int curIndex, vector<int>& inorder, int indexL, int indexR) {
		//当indexL>indexR时，意味着此孩子节点为NULL
		if (curIndex >= preorder.size() ||  indexL > indexR)
			return NULL;

		TreeNode* newNode = new TreeNode(preorder[curIndex]);
		//preorder[curIndex]在inorder中的索引为indexL+newIndex，左孩子数量为newIndex个，右孩子数量为indexR-indexL-newIndex个
		//因此preorder[curIndex]的左孩子节点为preorder[curIndex+1]，右孩子节点为preorder[curIndex+newIndex+1]，如果存在的话
		//左孩子节点preorder[curIndex+1]在inorder中的索引范围为[indexL,indexL+newIndex-1]
		//右孩子节点preorder[curIndex+newIndex+1]在inorder中的索引范围为[indexL+newIndex+1,indexR]
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