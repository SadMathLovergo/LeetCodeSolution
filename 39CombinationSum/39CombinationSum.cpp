#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> resVec;
	vector<int> curVec;
	void combinationSum(vector<int>& candidates, int index, int curSum, int target) {
		for (int i = index; i < candidates.size(); i++) {//ÿ�α�������һ�ֵ����п�ʼ��������ֹ�ظ�
			int res = curSum + candidates[i];
			if (res == target) {//�ѵõ�һ����ϣ���������棬Ȼ������ѭ��
				curVec.push_back(candidates[i]);
				resVec.push_back(curVec);
				curVec.pop_back();
				break;
			}
			else if (res > target) {//���ѳ���Ŀ�꣬������ѭ��
				break;
			}
			else {//��δ�ﵽĿ�꣬����еݹ����
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
		//�ȶԺ�ѡ���ֽ�������
		sort(candidates.begin(), candidates.end());

		if (candidates[0] > target)
			return resVec;

		combinationSum(candidates, 0, 0, target);

		return resVec;
	}
};