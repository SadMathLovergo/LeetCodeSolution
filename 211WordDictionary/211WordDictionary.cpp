#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

//��211�� �������������-���ݽṹ���
//����˼·�����ö�����������ʵ�����ݽṹ�����رȽ������
struct Node {
	string value;		//�ýڵ���ַ���
	Node* left;			//�ýڵ������
	Node* right;		//�ýڵ���Һ���
	size_t maxLength;		//�Ըýڵ�Ϊ���ڵ�Ķ��������ַ�������󳤶�
	size_t minLength;		//�Ըýڵ�Ϊ���ڵ�Ķ��������ַ�������С����
	Node(string _value):value(_value),left(NULL),right(NULL),maxLength(_value.length()),minLength(_value.length()){}
};

//����addWord�еıȽ��ַ�����word1��word2�����ܰ���'.'
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

//����search���Ѿ�ȷ��word1��word2��ƥ������µıȽ��ַ���
//word2���԰���'.'��word1 < word2���� -1��word1 > word2����1����word2�ȿ��� < word1Ҳ���� > word1����0
//�ؼ�����'.'�����ڲ�ƥ�������֮ǰ����֮������֮ǰ���򷵻�0������֮���򷵻ز�ƥ�������ַ��Ĵ�С
int compareWithDot(string& word1, string& word2) {
	int size = min(word1.length(), word2.length());
	int i = 0;
	//��'.'֮ǰ�Ĳ����в�ƥ���������򷵻ز�ƥ�������Ĵ�С�Ƚ����
	while (word2[i] != '.' && i < size) {
		if (word1[i] < word2[i])
			return -1;
		else if (word1[i] > word2[i])
			return 1;
		i++;
	}
	//'.'����һ���ַ����Ѿ�������ϣ���Ƚ��ַ����ĳ���
	if (i == size)
		return word1.length() < word2.length() ? -1 : 1;
	//����û�б����꣬��'.'��Ȼ�����ڲ�ƥ�������֮ǰ������0
	else
		return 0;
}

//�ַ����Ƿ�ƥ�䣬word2�п��԰���'.'
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
	Node * root;	//���ڵ�
	int capacity;	//��ǰ�ڵ����

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
		//���뵱ǰ�ڵ�ƥ��
		if (isMatch(node->value, word))
			return true;
		//���ڵ�ǰ�ڵ���ַ������ȷ�Χ֮��
		if (word.length() < node->minLength || word.length() > node->maxLength)
			return false;
		//���ڵ�ǰ�ڵ����������
		if (compareWithDot(node->value, word) == 1)
			return search(node->left, word);
		//���ڵ�ǰ�ڵ����������
		else if (compareWithDot(node->value, word) == -1)
			return search(node->right, word);
		//�������������������п���
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
	cout << "�����ַ�����" << word << endl;

	word = "and";
	dictionary.addWord(word);
	cout << "�����ַ�����" << word << endl;

	word = "an";
	dictionary.addWord(word);
	cout << "�����ַ�����" << word << endl;

	word = "add";
	dictionary.addWord(word);
	cout << "�����ַ�����" << word << endl;

	word = "bat";
	dictionary.addWord(word);
	cout << "�����ַ�����" << word << endl;


	word = "a";
	if (dictionary.search(word))
		cout << "�����������ַ�����" << word << endl;
	else
		cout << "�޷��������ַ�����" << word << endl;

	word = ".at";
	if (dictionary.search(word))
		cout << "�����������ַ�����" << word << endl;
	else
		cout << "�޷��������ַ�����" << word << endl;

	word = "an";
	if (dictionary.search(word))
		cout << "�����������ַ�����" << word << endl;
	else
		cout << "�޷��������ַ�����" << word << endl;

	word = "a.d.";
	if (dictionary.search(word))
		cout << "�����������ַ�����" << word << endl;
	else
		cout << "�޷��������ַ�����" << word << endl;

	word = "b.";
	if (dictionary.search(word))
		cout << "�����������ַ�����" << word << endl;
	else
		cout << "�޷��������ַ�����" << word << endl;

	word = "a.d";
	if (dictionary.search(word))
		cout << "�����������ַ�����" << word << endl;
	else
		cout << "�޷��������ַ�����" << word << endl;

	word = ".";
	if (dictionary.search(word))
		cout << "�����������ַ�����" << word << endl;
	else
		cout << "�޷��������ַ�����" << word << endl;

	system("pause");
	return 0;
}