#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

//第211题 添加与搜索单词-数据结构设计
//解题思路：利用二叉搜索树来实现数据结构，重载比较运算符
struct Node {
	string value;		//该节点的字符串
	Node* left;			//该节点的左孩子
	Node* right;		//该节点的右孩子
	size_t maxLength;		//以该节点为根节点的二叉树的字符串的最大长度
	size_t minLength;		//以该节点为根节点的二叉树的字符串的最小长度
	Node(string _value):value(_value),left(NULL),right(NULL),maxLength(_value.length()),minLength(_value.length()){}
};

//用于addWord中的比较字符串，word1和word2都不能包含'.'
bool lower(string& word1, string& word2) {
	int size = min(word1.length(), word2.length());
	for (int i = 0; i < size; i++)
		if (word1[i] != '.' && word2[i] != '.')
			if (word1[i] < word2[i])
				return true;
			else if (word1[i] > word2[i])
				return false;
	return word1.length() < word2.length();
}

//用于search中已经确定word1和word2不匹配情况下的比较字符串
//word2可以包含'.'，word1 < word2返回 -1，word1 > word2返回1，若word2既可以 < word1也可以 > word1返回0
//关键在于'.'出现在不匹配的索引之前还是之后，若是之前，则返回0，若是之后，则返回不匹配索引字符的大小
int compareWithDot(string& word1, string& word2) {
	int size = min(word1.length(), word2.length());
	int i = 0;
	//若'.'之前的部分有不匹配的情况，则返回不匹配索引的大小比较情况
	while (word2[i] != '.' && i < size) {
		if (word1[i] < word2[i])
			return -1;
		else if (word1[i] > word2[i])
			return 1;
		i++;
	}
	//'.'若有一个字符串已经遍历完毕，则比较字符串的长度
	if (i == size)
		return word1.length() < word2.length() ? -1 : 1;
	//若还没有遍历完，则'.'必然出现在不匹配的索引之前，返回0
	else
		return 0;
}

//字符串是否匹配，word2中可以包含'.'
bool isMatch(string& word1, string& word2) {
	if (word1.length() != word2.length())
		return false;
	for (int i = 0; i < word2.length(); i++)
		if (word2[i] != '.' && word1[i] != word2[i])
			return false;
	return true;
}

class WordDictionary {
private:
	Node * root;	//根节点
	int capacity;	//当前节点个数

	Node* addWord(Node* root, string word) {
		if (root == NULL)
			return new Node(word);
		if (lower(word, root->value))
			root->left = addWord(root->left, word);
		else
			root->right = addWord(root->right, word);

		root->maxLength = max(root->maxLength, word.length());
		root->minLength = min(root->minLength, word.length());

		return root;
	}

	bool search(Node* node, string word) {
		if (node == NULL)
			return false;
		//若与当前节点匹配
		if (isMatch(node->value, word))
			return true;
		//若在当前节点的字符串长度范围之外
		if (word.length() < node->minLength || word.length() > node->maxLength)
			return false;
		//若在当前节点的左子树中
		if (compareWithDot(node->value, word) == 1)
			return search(node->left, word);
		//若在当前节点的右子树中
		else if (compareWithDot(node->value, word) == -1)
			return search(node->right, word);
		//若左子树和右子树都有可能
		else
			return search(node->left, word) || search(node->right, word);
	}

public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = NULL;
		capacity = 0;
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		root = addWord(root, word);
		capacity++;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return search(root, word);
	}
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/

int main() {
	WordDictionary dictionary = WordDictionary();
	string word = "";

	word = "at";
	dictionary.addWord(word);
	cout << "插入字符串：" << word << endl;

	word = "and";
	dictionary.addWord(word);
	cout << "插入字符串：" << word << endl;

	word = "an";
	dictionary.addWord(word);
	cout << "插入字符串：" << word << endl;

	word = "add";
	dictionary.addWord(word);
	cout << "插入字符串：" << word << endl;

	word = "bat";
	dictionary.addWord(word);
	cout << "插入字符串：" << word << endl;


	word = "a";
	if (dictionary.search(word))
		cout << "可以搜索到字符串：" << word << endl;
	else
		cout << "无法搜索到字符串：" << word << endl;

	word = ".at";
	if (dictionary.search(word))
		cout << "可以搜索到字符串：" << word << endl;
	else
		cout << "无法搜索到字符串：" << word << endl;

	word = "an";
	if (dictionary.search(word))
		cout << "可以搜索到字符串：" << word << endl;
	else
		cout << "无法搜索到字符串：" << word << endl;

	word = "a.d.";
	if (dictionary.search(word))
		cout << "可以搜索到字符串：" << word << endl;
	else
		cout << "无法搜索到字符串：" << word << endl;

	word = "b.";
	if (dictionary.search(word))
		cout << "可以搜索到字符串：" << word << endl;
	else
		cout << "无法搜索到字符串：" << word << endl;

	word = "a.d";
	if (dictionary.search(word))
		cout << "可以搜索到字符串：" << word << endl;
	else
		cout << "无法搜索到字符串：" << word << endl;

	word = ".";
	if (dictionary.search(word))
		cout << "可以搜索到字符串：" << word << endl;
	else
		cout << "无法搜索到字符串：" << word << endl;

	system("pause");
	return 0;
}