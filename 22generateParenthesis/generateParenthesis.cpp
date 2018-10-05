#include <vector>
#include <string>
using namespace std;

/*第22题括号生成，使用递归回溯法*/
class Solution {
private:
	vector<string> resVec;//用于存储结果
	vector<char> curStr;//当前字符串

	void generateParenthesis(int leftNum, int rightNum, int num) {
		//如果'('或者')'的数量大于n
		if (leftNum > num || rightNum > num)
			return;

		//如果'('和')'的数量都等于n
		if (leftNum == num && rightNum == num) {
			string resStr(curStr.begin(), curStr.end());
			resVec.push_back(resStr);
			return;
		}

		//若'('数量小于')'数量，不符合规定，则返回，保证在递归的过程中，'('数量永远大于等于')'数量
		if (leftNum < rightNum)
			return;

		//递归回溯
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