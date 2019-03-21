#pragma once
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
	void serialize(TreeNode* pRoot, string& str) {
		if (pRoot == nullptr) {
			str += "$,";
			return;
		}

		str += to_string(pRoot->val);
		str += ",";
		serialize(pRoot->left, str);
		serialize(pRoot->right, str);
	}

	TreeNode* deserialize(const char** str) {
		if (**str == '$') {
			*str += 2;
			return nullptr;
		}

		int i = 0;
		while ((*str)[i] != ',')
			i++;

		string value = string(*str, i);
		TreeNode* curNode = new TreeNode(stoi(value));
		*str += i + 1;

		curNode->left = deserialize(str);
		curNode->right = deserialize(str);
		return curNode;
	}

public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res = "";
		serialize(root, res);

		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty())
			return nullptr;
		const char* str = data.c_str();
		return deserialize(&str);
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));