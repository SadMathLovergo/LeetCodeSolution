#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (coins.empty())
			return -1;

		if (amount == 0)
			return 0;

		vector<int> memory(amount + 1, -1);//若该背包能填满，则值为填满此背包所需要的最小硬币数，否则为-1

		for (int i = 0; i < coins.size(); i++)
			if (coins[i] <= amount)
				memory[coins[i]] = 1;//能用一个硬币填满的背包

		for (int i = 0; i < amount; i++) {
			if (memory[i] != -1) {//背包i能被填满，则遍历一遍所有硬币，查看能被继续填满的背包
				for (int j = 0; j < coins.size(); j++) {
					if (i + coins[j] >= 0 && i + coins[j] <= amount) {//更新数据，若此背包原本无法填满，则最小硬币个数更新为memory[i]+1，若本身已经被填满，则更新为min(memory[i + coins[j]], memory[i] + 1))
						if (memory[i + coins[j]] == -1)
							memory[i + coins[j]] = memory[i] + 1;
						else
							memory[i + coins[j]] = min(memory[i + coins[j]], memory[i] + 1);
					}
				}
			}
		}
		return memory[amount];
	}
};

int main() {
	vector<int> coins{ 186,149,83,408 };
	int amount = 6249;
	int res = Solution().coinChange(coins, amount);
	cout << res << endl;

	system("pause");
	return 0;
}