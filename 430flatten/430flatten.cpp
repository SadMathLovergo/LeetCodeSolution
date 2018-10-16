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

/*第430题 扁平化多级双向链表*/
//解题思路：不要犹豫，直接递归就好，使用stack储存转折的Node
class Solution {
private:
	Node * flattenNext(Node* head, stack<Node*>& memo) {
		//若此节点不拥有孩子节点
		if (head->child == NULL) {
			//若下一个节点也为空
			if (head->next == NULL) {
				if (!memo.empty()) {
					Node* nextNode = memo.top();
					memo.pop();
					nextNode->prev = head;
					head->next = flattenNext(nextNode, memo);
				}
				return head;
			}
			//若下一个节点不为空
			head->next = flattenNext(head->next, memo);
			return head;
		}
		else {//若此节点拥有孩子节点
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