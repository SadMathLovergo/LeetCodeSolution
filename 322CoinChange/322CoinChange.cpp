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

		vector<int> memory(amount + 1, -1);//���ñ�������������ֵΪ�����˱�������Ҫ����СӲ����������Ϊ-1

		for (int i = 0; i < coins.size(); i++)
			if (coins[i] <= amount)
				memory[coins[i]] = 1;//����һ��Ӳ�������ı���

		for (int i = 0; i < amount; i++) {
			if (memory[i] != -1) {//����i�ܱ������������һ������Ӳ�ң��鿴�ܱ����������ı���
				for (int j = 0; j < coins.size(); j++) {
					if (i + coins[j] >= 0 && i + coins[j] <= amount) {//�������ݣ����˱���ԭ���޷�����������СӲ�Ҹ�������Ϊmemory[i]+1���������Ѿ��������������Ϊmin(memory[i + coins[j]], memory[i] + 1))
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