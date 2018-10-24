#include <string>
#include <iostream>
using namespace std;

struct Node {
	string value;
	Node* left;
	Node* right;
	Node(string _value):value(_value),left(NULL),right(NULL){}
};

//word是否以prefix为字符串前缀
bool isStartWith(string word, string prefix) {
	if (word.length() < prefix.length())
		return false;
	for (int i = 0; i < prefix.length(); i++)
		if (word[i] != prefix[i])
			return false;
	return true;
}

//第208题 实现前缀树
//解题思路：就是单纯用二叉搜索树实现的一个简单的数据结构
class Trie {
private:
	Node * root;	//根节点
	int capacity;	//当前节点个数

	//在以root为根节点的树中插入value为word的新节点，并返回新的根节点
	Node* insert(Node* root, string word) {
		if (root == NULL)
			return new Node(word);
		if (word < root->value)
			root->left = insert(root->left, word);
		else//word > root->value
			root->right = insert(root->right, word);
		return root;
	}

	//在以root为根节点的树中寻找value为word的节点
	bool search(Node* root, string word) {
		if (root == NULL)
			return false;
		if (root->value == word)
			return true;
		else if (word < root->value)
			return search(root->left, word);
		else//word > root->value
			return search(root->right, word);
	}

	//在以root为根节点的树中寻找，是否有以word开头的节点
	bool startsWith(Node* root, string word) {
		if (root == NULL)
			return false;
		if (isStartWith(root->value, word))
			return true;
		else if (word < root->value)
			return startsWith(root->left, word);
		else// word > root->value
			return startsWith(root->right, word);
	}

public:
	/** Initialize your data structure here. */
	Trie() {
		root = NULL;
		capacity = 0;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		root = insert(root, word);
		capacity++;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		return search(root, word);
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		return startsWith(root, prefix);
	}
};

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/

int main() {
	Trie trie = Trie();

	trie.insert("apple");

	if (trie.search("apple"))
		cout << "有apple" << endl;
	else
		cout << "不存在apple" << endl;

	if (trie.search("app"))
		cout << "有app" << endl;
	else
		cout << "不存在app" << endl;

	if (trie.startsWith("app"))
		cout << "有以app为前缀的单词" << endl;
	else
		cout << "不存在以app为前缀的单词" << endl;

	trie.insert("app");
	
	if (trie.search("app"))
		cout << "有app" << endl;
	else
		cout << "不存在app" << endl;

	system("pause");
	return 0;
}