#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

//第211题 添加与搜索单词-数据结构设计
//解题思路：利用树来实现数据结构，重载比较运算符，以字符串的每个字母为节点，每个节点有26个孩子节点，作为下一个字母
struct TrieNode
{
	bool isWord;
	TrieNode* child[26];
	TrieNode():isWord(false){
		for (auto &a : child)
			a = NULL;
	}
};

class WordDictionary {
private:
	TrieNode* root;
	bool search(string& word, TrieNode* root, int index) {
		if (index == word.length())
			return root->isWord;

		if (word[index] == '.') {
			for (auto &nextNode : root->child)
				if (nextNode&&search(word, nextNode, index + 1))
					return true;
			return false;
		}
		else {
			return root->child[word[index] - 'a'] && search(word, root->child[word[index] - 'a'], index + 1);
		}

	}

public:

	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode* curNode = root;
		for (auto &curChar : word) {
			int i = curChar - 'a';
			if (!curNode->child[i])
				curNode->child[i] = new TrieNode();
			curNode = curNode->child[i];
		}
		curNode->isWord = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return search(word, root, 0);
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