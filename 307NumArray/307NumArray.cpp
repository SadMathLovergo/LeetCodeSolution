#pragma once
#include <vector>
using namespace std;

//第307题 区域和检索-数组可修改
//解题思路：使用树状数组
class NumArray {
private:
	vector<int> oriNum;
	vector<int> memo;

public:
	NumArray(vector<int> nums) {
		oriNum = vector<int>(nums.begin(), nums.end());
		memo.resize(nums.size() + 1);
		memo[0] = 0;
		for (int i = 0; i < nums.size(); i++)
			memo[i + 1] = nums[i];
		for (int i = 1; i < memo.size(); i++) {
			int j = i + (i & -i);
			if (j < memo.size())
				memo[j] += memo[i];
		}
	}

	void update(int i, int val) {
		int delta = val - oriNum[i];
		oriNum[i] = val;
		i++;
		while (i < memo.size()) {
			memo[i] += delta;
			i = i + (i & -i);
		}
	}

	int sumRange(int i, int j) {
		if (i == 0)
			return sum(j);
		return sum(j) - sum(i - 1);
	}

	int sum(int i) {
		int temp = 0;
		i++;
		while (i > 0) {
			temp += memo[i];
			i = i - (i & -i);
		}
		return temp;
	}
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* obj.update(i,val);
* int param_2 = obj.sumRange(i,j);
*/

int main() {
	vector<int> nums{ 0,9,5,7,3 };
	NumArray numArray(nums);
	numArray.sumRange(4, 4);
	numArray.sumRange(2, 4);
	numArray.sumRange(3, 3);
	numArray.update(4, 5);
	numArray.update(1, 7);
	numArray.update(0, 8);
	numArray.sumRange(1, 2);
	numArray.update(1, 9);
	numArray.sumRange(4, 4);
	numArray.update(3, 4);
}