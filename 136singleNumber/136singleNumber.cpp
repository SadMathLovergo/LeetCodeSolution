#include <vector>
using namespace std;

//��136�� ֻ����һ�ε�����
//����˼·�������߼������ ���
//�κ�������ͬ���������������õ��Ķ���0
//�κ�����0����������㣬�õ��Ķ��Ǳ���
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (auto num : nums)
			res ^= num;
		return res;
	}
};