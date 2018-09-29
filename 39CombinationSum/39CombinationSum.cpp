#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> resVec;
	vector<int> curVec;
	void combinationSum(vector<int>& candidates, int index, int curSum, int target) {
		for (int i = index; i < candidates.size(); i++) {//每次遍历从上一轮的序列开始遍历，防止重复
			int res = curSum + candidates[i];
			if (res == target) {//已得到一种组合，将结果保存，然后跳出循环
				curVec.push_back(candidates[i]);
				resVec.push_back(curVec);
				curVec.pop_back();
				break;
			}
			else if (res > target) {//若已超过目标，则跳出循环
				break;
			}
			else {//若未达到目标，则进行递归回溯
				curVec.push_back(candidates[i]);
				combinationSum(candidates, i, res, target);
				curVec.pop_back();
			}
		}
	}

public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		resVec.clear();

		if (candidates.empty())
			return resVec;
		//先对候选数字进行排序
		sort(candidates.begin(), candidates.end());

		if (candidates[0] > target)
			return resVec;

		combinationSum(candidates, 0, 0, target);

		return resVec;
	}
};