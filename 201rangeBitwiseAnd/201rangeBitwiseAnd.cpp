#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//第201题 数字范围按位与
//解题思路：找到从m和n的二进制，从高位到低位，相同的部分，剩下部分置零，即为最终的结果
//我真是蠢，之前的方法太智障
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int i = 0;
		while (m != n) {
			m >>= 1;
			n >>= 1;
			i++;
		}
		return m << i;
	}
};

int main() {
	int res = Solution().rangeBitwiseAnd(5, 7);
	cout << res << endl;
	system("pause");
	return 0;
}