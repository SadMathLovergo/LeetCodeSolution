#include <vector>
using namespace std;

/*第96题 不同的二叉搜索树*/
//解题思路：典型的动态规划题目
//对于每一个含有1~n这n个节点的二叉搜索树而言，二叉搜索树的总数量等于分别将节点i作为根节点时的二叉搜索树数量之和
//将节点i作为根节点时，二叉搜索树的数量等于节点1~节点i-1所能构成的二叉搜索树的数量乘以节点i+1~节点n所能构成的二叉搜索树的数量
class Solution {
public:
	int numTrees(int n) {
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;

		//设定初始值
		vector<int> memo(n + 1, 0);
		memo[0] = 1;
		memo[1] = 1;
		memo[2] = 2;

		//计算1~i这i个节点所能构成的二叉搜索树的数量
		for (int i = 3; i <= n; i++) {
			//以root为根节点时，所能构成的二叉搜索树的数量
			for (int root = 1; root <= i; root++)
				memo[i] += memo[root - 1] * memo[i - root];
		}

		return memo[n];
	}
};