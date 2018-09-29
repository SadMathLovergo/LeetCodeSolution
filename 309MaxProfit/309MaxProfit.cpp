#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty() || prices.size() == 1)
			return 0;
		if (prices.size() == 2)
			return max(0, prices[1] - prices[0]);
		int n = prices.size();

		vector<int> WithProfit(n, 0);
		vector<int> WithoutProfit(n, 0);

		WithoutProfit[0] = 0;
		WithoutProfit[1] = max(0, prices[1] - prices[0]);
		WithProfit[0] = -prices[0];
		WithProfit[1] = max(-prices[0], -prices[1]);

		for (int i = 2; i < prices.size(); i++) {
			WithProfit[i] = max(WithProfit[i - 1], WithoutProfit[i - 2] - prices[i]);
			WithoutProfit[i] = max(WithProfit[i - 1] + prices[i], WithoutProfit[i - 1]);
		}

		return WithoutProfit[prices.size() - 1];
	}
};

int main() {
	vector<int> nums{ 1,2,3,0,2 };
	int res = Solution().maxProfit(nums);
	cout << res << endl;
	system("pause");
	return 0;
}