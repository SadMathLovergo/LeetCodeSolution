#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode * sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
			return NULL;
		TreeNode* root = insertNode(nums, 0, nums.size() - 1);
		return root;
	}

private:
	TreeNode * insertNode(vector<int>& nums, int indexL, int indexR) {//利用[indexL,indexR]中的元素来创建子树
		if (indexL > indexR)
			return NULL;

		if (indexL == indexR)
			return new TreeNode(nums[indexL]);

		int indexM = indexL + (indexR - indexL + 1) / 2;
		TreeNode* node = new TreeNode(nums[indexM]);

		node->left = insertNode(nums, indexL, indexM - 1);
		node->right = insertNode(nums, indexM + 1, indexR);

		return node;
	}
};