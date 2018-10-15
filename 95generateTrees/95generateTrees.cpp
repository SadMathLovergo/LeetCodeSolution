#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*第95题 不同的二叉搜索树2*/
//解题思路：同样使用动态规划的思路，只不过需要拷贝二叉搜索树，同时需要对二叉搜索树的值进行修改
class Solution {
private:
	//以递归的方式拷贝二叉搜索树，同时对值进行修改
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
		//treesMemo[i]中保存的是节点1~节点i所有的二叉搜索树种类的根节点
		vector<vector<TreeNode*>> treesMemo(n + 1, vector<TreeNode*>());

		//若输入的i为0，直接返回
		if (n == 0)
			return treesMemo[0];

		treesMemo[0].push_back(NULL);
		treesMemo[1].push_back(new TreeNode(1));

		//计算节点1~节点i所能构成的所有的二叉搜索树
		for (int i = 2; i <= n; i++) {
			//以节点j为根节点时
			for (int j = 1; j <= i; j++) {
				//根节点的左子树为节点1~节点j-1构成的二叉搜索树
				for(vector<TreeNode*>::iterator leftIter = treesMemo[j-1].begin(); leftIter!=treesMemo[j-1].end(); leftIter++)
					//根节点右子树为节点j+1~节点i构成的二叉搜索树
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