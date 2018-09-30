#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> resVec;
	vector<int> curVec;
	void combinationSum2(vector<int>& candidates, int index, int curSum, int target) {
		for (int i = index; i < candidates.size(); i++) {
			int res = curSum + candidates[i];
			if (res == target) {
				curVec.push_back(candidates[i]);
				resVec.push_back(curVec);
				curVec.pop_back();
				break;
			}
			else if (res > target) {
				break;
			}
			else {
				curVec.push_back(candidates[i]);
				combinationSum2(candidates, i + 1, res, target);
				curVec.pop_back();
			}
			//下一次遍历时，不能使用重复的数字
			while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
				i++;
		}
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		resVec.clear();
		if (candidates.empty())
			return resVec;

		//由于每个数字在每个组合中只能用一次，并且candidates中可能有重复的数字，因此先对candidates进行排序
		sort(candidates.begin(), candidates.end());

		if (candidates[0] > target)
			return resVec;

		combinationSum2(candidates, 0, 0, target);

		return resVec;
	}
};