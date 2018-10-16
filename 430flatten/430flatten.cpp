#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
	int val = NULL;
	Node* prev = NULL;
	Node* next = NULL;
	Node* child = NULL;

	Node() {}

	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};

/*��430�� ��ƽ���༶˫������*/
//����˼·����Ҫ��ԥ��ֱ�ӵݹ�ͺã�ʹ��stack����ת�۵�Node
class Solution {
private:
	Node * flattenNext(Node* head, stack<Node*>& memo) {
		//���˽ڵ㲻ӵ�к��ӽڵ�
		if (head->child == NULL) {
			//����һ���ڵ�ҲΪ��
			if (head->next == NULL) {
				if (!memo.empty()) {
					Node* nextNode = memo.top();
					memo.pop();
					nextNode->prev = head;
					head->next = flattenNext(nextNode, memo);
				}
				return head;
			}
			//����һ���ڵ㲻Ϊ��
			head->next = flattenNext(head->next, memo);
			return head;
		}
		else {//���˽ڵ�ӵ�к��ӽڵ�
			Node* childNode = head->child;
			childNode->prev = head;
			Node* nextNode = head->next;
			if(nextNode!=NULL)
				memo.push(nextNode);
			head->child = NULL;
			head->next = flattenNext(childNode, memo);
		}
		return head;
	}
public:
	Node * flatten(Node* head) {
		if (head == NULL)
			return head;

		stack<Node*> memo;

		Node* zeroNode = new Node();
		zeroNode->next = head;
		head->prev = zeroNode;

		zeroNode = flattenNext(zeroNode, memo);
		head = zeroNode->next;
		head->prev = NULL;
		delete zeroNode;

		return head;
	}
};