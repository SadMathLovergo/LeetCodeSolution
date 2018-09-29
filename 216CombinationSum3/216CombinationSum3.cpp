#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
	vector<vector<int>> resVec;
	vector<int> curVec;
	void findCombination(int k, int n, int curSum) {
		int curSize = curVec.size();
		int lastNum = curSize ? curVec[curSize - 1] : 0;
		for (int i = lastNum + 1; i < 11 - k + curSize; i++) {//i的取值范围保证，可以取够k个数
			if (curSize + 1 == k) {//如果已经塞入了k个数，就判断和是否等于n
				if (curSum + i == n) {//若等于n
					curVec.push_back(i);
					resVec.push_back(curVec);
					curVec.pop_back();
					break;
				}
				else if (curSum + i > n)//若大于n，则后续遍历无需进行
					break;
				else//若小于n，则继续遍历下一个数
					continue;
			}
			else{//若还未塞入k个数
				if (curSum + i < n) {//若和小于n，则进行递归回溯
					curVec.push_back(i);
					findCombination(k, n, curSum + i);
					curVec.pop_back();
				}
				else//若和已经大于等于n，则不需要进行后续遍历
					break;
			}
		}
	}
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		resVec.clear();
		curVec.clear();

		if (n < k*(k + 1) / 2 || k > 9)
			return resVec;

		findCombination(k, n, 0);
		return resVec;
	}
};