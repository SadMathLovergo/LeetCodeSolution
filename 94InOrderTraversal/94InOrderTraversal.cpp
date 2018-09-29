#include <vector>
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Command
{
	string s;
	TreeNode* node;
	Command(string s, TreeNode* node) : s(s), node(node) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> resVec;
		if (root == NULL)
			return resVec;

		stack<Command> StackCom;
		StackCom.push(Command("go", root));

		while (!StackCom.empty()) {
			Command com = StackCom.top();
			StackCom.pop();

			if (com.s == "go") {
				if (com.node->right != NULL)
					StackCom.push(Command("go", com.node->right));
				StackCom.push(Command("print", com.node));
				if (com.node->left != NULL)
					StackCom.push(Command("go", com.node->left));
			}
			else
			{
				assert(com.s == "print");
				resVec.push_back(com.node->val);
			}
		}

		return resVec;

	}
};