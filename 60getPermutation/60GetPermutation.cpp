#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*��60�� ��k������*/
/*����˼·��1~k�ܹ���k!�����з�ʽ*/
class Solution {
public:
	string getPermutation(int n, int k) {
		/*����0~k�Ľ׳�ֵ*/
		vector<int> factorialMemo;
		int factorial = 1;
		factorialMemo.push_back(factorial);
		for (int i = 1; i <= n; i++) {
			factorial *= i;
			factorialMemo.push_back(factorial);
		}

		/*�����ַ���ÿһλ�Ĵ��������*/
		/*ÿһλ�Ĵ��������Ϊ����ǰ��λ����ȥ������ʣ�µ������е�����*/
		vector<int> memo;
		for (int i = n - 1; i >= 0; i--) {
			memo.push_back((k - 1) / factorialMemo[i] + 1);
			k = (k - 1) % factorialMemo[i] + 1;
		}

		string resStr;
		/*��ԭ�ַ���ÿһλ��ԭʼ����*/
		vector<bool> usageMemo(n + 1, false);
		for (int i = 0; i < n; i++) {
			int finalNum = memo[i];
			int oriNum = 0;
			
			while (finalNum != 0) {
				if (!usageMemo[oriNum + 1])
					finalNum--;
				oriNum++;
			}
			usageMemo[oriNum] = true;
			resStr += ('0' + oriNum);
		}

		return resStr;
	}
};

int main() {
	string str = Solution().getPermutation(3, 3);
	cout << str << endl;
	system("pause");
	return 0;
}