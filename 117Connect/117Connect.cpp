#include <iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/*��117�� ���ͬһ����ֵܽڵ�2*/
//����˼·������ʹ�õݹ�ķ��������
//�������ڶ��������ܲ������������������Բ���ʹ��116���˼·
class Solution {
	//��upperNode�ĺ��ӽڵ����һ�����ӽڵ�����
	TreeLinkNode* connectLayer(TreeLinkNode* upperNode) {
		if (upperNode == NULL)
			return upperNode;

		//�����Ӳ�Ϊ��
		if (upperNode->left != NULL) {
			if (upperNode->right != NULL) {//���Һ��Ӳ�Ϊ��
				//�������Ӻ��Һ���
				upperNode->left->next = upperNode->right;
				//���Һ�������һ�����ӽڵ�����
				upperNode->right->next = connectLayer(upperNode->next);
				return upperNode->left;
			}
			else {//���Һ���Ϊ��
				//����������һ�����ӽڵ�����
				upperNode->left->next = connectLayer(upperNode->next);
				return upperNode->left;
			}
		}
		else {//������Ϊ��
			if (upperNode->right != NULL) {//���Һ��Ӳ�Ϊ��
				//���Һ�������һ�����ӽڵ�����
				upperNode->right->next = connectLayer(upperNode->next);
				return upperNode->right;
			}
			else//���Һ���Ϊ�գ�������һ�����ӽڵ�
				return connectLayer(upperNode->next);
		}

	}

public:
	void connect(TreeLinkNode *root) {
		//����ǰ��ĺ��ӽڵ�ȫ������������ͬʱ��ȡ��һ��ĵ�һ���ڵ�
		TreeLinkNode* nextNode = connectLayer(root);
		//����һ��û�нڵ㣬��ʾ�Ѿ��������
		if (nextNode == NULL)
			return;
		//��ʼ������һ��ڵ�
		connect(nextNode);
	}
};