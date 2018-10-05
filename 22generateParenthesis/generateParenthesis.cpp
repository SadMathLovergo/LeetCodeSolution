#include <vector>
#include <string>
using namespace std;

/*��22���������ɣ�ʹ�õݹ���ݷ�*/
class Solution {
private:
	vector<string> resVec;//���ڴ洢���
	vector<char> curStr;//��ǰ�ַ���

	void generateParenthesis(int leftNum, int rightNum, int num) {
		//���'('����')'����������n
		if (leftNum > num || rightNum > num)
			return;

		//���'('��')'������������n
		if (leftNum == num && rightNum == num) {
			string resStr(curStr.begin(), curStr.end());
			resVec.push_back(resStr);
			return;
		}

		//��'('����С��')'�����������Ϲ涨���򷵻أ���֤�ڵݹ�Ĺ����У�'('������Զ���ڵ���')'����
		if (leftNum < rightNum)
			return;

		//�ݹ����
		curStr.push_back('(');
		generateParenthesis(leftNum + 1, rightNum, num);
		curStr.pop_back();

		curStr.push_back(')');
		generateParenthesis(leftNum, rightNum + 1, num);
		curStr.pop_back();
			
	}

public:
	vector<string> generateParenthesis(int n) {
		resVec.clear();
		curStr.clear();

		generateParenthesis(0, 0, n);
		return resVec;
	}
};