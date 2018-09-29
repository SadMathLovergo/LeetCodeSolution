#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> resVec;//�������ս��
	vector<bool> visited;//�������״̬
	void doPermute(vector<int>& nums, vector<int>& curVec) {
		if (curVec.size() == nums.size()) {//���Ѿ������꣬��curVec������resVec��
			resVec.push_back(curVec);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (!visited[i]) {//��û��ʹ�ù�
				//�ݹ����
				curVec.push_back(nums[i]);
				visited[i] = true;
				doPermute(nums, curVec);
				curVec.pop_back();
				visited[i] = false;
				//�ж���һ�������������Ƿ�ʹ�������ͬ
				while ( i < nums.size() - 1 && nums[i] == nums[i + 1])
					i++;
			}
		}
	}

public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.empty())
			return resVec;

		sort(nums.begin(), nums.end());
		visited = vector<bool>(nums.size(), false);
		vector<int> curVec;
		doPermute(nums, curVec);
		return resVec;
	}
};