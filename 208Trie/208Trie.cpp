#include <string>
#include <iostream>
using namespace std;

struct Node {
	string value;
	Node* left;
	Node* right;
	Node(string _value):value(_value),left(NULL),right(NULL){}
};

//word�Ƿ���prefixΪ�ַ���ǰ׺
bool isStartWith(string word, string prefix) {
	if (word.length() < prefix.length())
		return false;
	for (int i = 0; i < prefix.length(); i++)
		if (word[i] != prefix[i])
			return false;
	return true;
}

//��208�� ʵ��ǰ׺��
//����˼·�����ǵ����ö���������ʵ�ֵ�һ���򵥵����ݽṹ
class Trie {
private:
	Node * root;	//���ڵ�
	int capacity;	//��ǰ�ڵ����

	//����rootΪ���ڵ�����в���valueΪword���½ڵ㣬�������µĸ��ڵ�
	Node* insert(Node* root, string word) {
		if (root == NULL)
			return new Node(word);
		if (word < root->value)
			root->left = insert(root->left, word);
		else//word > root->value
			root->right = insert(root->right, word);
		return root;
	}

	//����rootΪ���ڵ������Ѱ��valueΪword�Ľڵ�
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

	//����rootΪ���ڵ������Ѱ�ң��Ƿ�����word��ͷ�Ľڵ�
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
		cout << "��apple" << endl;
	else
		cout << "������apple" << endl;

	if (trie.search("app"))
		cout << "��app" << endl;
	else
		cout << "������app" << endl;

	if (trie.startsWith("app"))
		cout << "����appΪǰ׺�ĵ���" << endl;
	else
		cout << "��������appΪǰ׺�ĵ���" << endl;

	trie.insert("app");
	
	if (trie.search("app"))
		cout << "��app" << endl;
	else
		cout << "������app" << endl;

	system("pause");
	return 0;
}