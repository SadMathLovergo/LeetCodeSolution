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
			//��һ�α���ʱ������ʹ���ظ�������
			while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
				i++;
		}
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		resVec.clear();
		if (candidates.empty())
			return resVec;

		//����ÿ��������ÿ�������ֻ����һ�Σ�����candidates�п������ظ������֣�����ȶ�candidates��������
		sort(candidates.begin(), candidates.end());

		if (candidates[0] > target)
			return resVec;

		combinationSum2(candidates, 0, 0, target);

		return resVec;
	}
};