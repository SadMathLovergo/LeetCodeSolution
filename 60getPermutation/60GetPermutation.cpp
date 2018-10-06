#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*第60题 第k个排列*/
/*解题思路：1~k总共有k!种排列方式*/
class Solution {
public:
	string getPermutation(int n, int k) {
		/*计算0~k的阶乘值*/
		vector<int> factorialMemo;
		int factorial = 1;
		factorialMemo.push_back(factorial);
		for (int i = 1; i <= n; i++) {
			factorial *= i;
			factorialMemo.push_back(factorial);
		}

		/*计算字符串每一位的处理后索引*/
		/*每一位的处理后索引为：将前几位数字去掉后，在剩下的数字中的索引*/
		vector<int> memo;
		for (int i = n - 1; i >= 0; i--) {
			memo.push_back((k - 1) / factorialMemo[i] + 1);
			k = (k - 1) % factorialMemo[i] + 1;
		}

		string resStr;
		/*还原字符串每一位的原始索引*/
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