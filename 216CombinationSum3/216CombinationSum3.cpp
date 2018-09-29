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
		for (int i = lastNum + 1; i < 11 - k + curSize; i++) {//i��ȡֵ��Χ��֤������ȡ��k����
			if (curSize + 1 == k) {//����Ѿ�������k���������жϺ��Ƿ����n
				if (curSum + i == n) {//������n
					curVec.push_back(i);
					resVec.push_back(curVec);
					curVec.pop_back();
					break;
				}
				else if (curSum + i > n)//������n������������������
					break;
				else//��С��n�������������һ����
					continue;
			}
			else{//����δ����k����
				if (curSum + i < n) {//����С��n������еݹ����
					curVec.push_back(i);
					findCombination(k, n, curSum + i);
					curVec.pop_back();
				}
				else//�����Ѿ����ڵ���n������Ҫ���к�������
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