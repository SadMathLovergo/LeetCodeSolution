#include <vector>
using namespace std;

/*第134题 加油站*/
//解题思路：查阅资料后，获得思路
//若从加油站i经过若干站后无法到达加油站j（j为第一个无法到达的加油站），则从i到j之间任何一个加油站出发，都无法到达j
//若所有加油站的油的总和大于消耗油的总和，则必然有一个加油站可以绕一圈
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int startPort = 0;	//起始加油站
		int totalGas = 0;	//从第0个加油站开始，到当前加油站所剩油量
		int curGas = 0;		//当前所剩油量

		for (int i = 0; i < gas.size(); i++) {
			//若从第startPort个加油站无法到第i+1个加油站，则从第i+1个节点开始重新计算
			if ((curGas += gas[i] - cost[i]) < 0) {
				startPort = i + 1;
				totalGas += curGas;
				curGas = 0;
			}
		}

		return (totalGas + curGas) >= 0 ? startPort : -1;
	}
};