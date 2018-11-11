#include <vector>
using namespace std;

//��260�⣺ֻ����һ�ε�����3
//����˼·��ʹ���߼�λ���㣬��ͬ�����������Ϊ0
//�ҵ�������������������е�һ��1���ڵ�������������Ϊֻ����һ�ε������������Ʋ���ͬ�ĵ�һλ
//�����е������ݸ������Ƿ�Ϊ1��Ϊ���࣬������ֻ����һ�ε�����Ȼ���Էֱ��ڲ�ͬ�����࣬�ֱ������������������տ��Եõ���������
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> res;
		if (nums.empty())
			return res;

		//�������������Ϊֻ����һ�ε��������������
		int XorRes = 0;
		for (int i = 0; i < nums.size(); i++)
			XorRes ^= nums[i];

		int firstIndex = 0;
		//�ҵ�������е�һ��1���ڵ�������������Ϊֻ����һ�ε������������Ʋ���ͬ�ĵ�һλ
		for (int i = 0; i < 8 * sizeof(int); i++) {
			if (XorRes & 1 != 0)
				break;
			XorRes = XorRes >> 1;
			firstIndex++;
		}

		//�����е������ݸ�����λ�Ƿ�Ϊ1��Ϊ���࣬������ֻ����һ�ε�����Ȼ���Էֱ��ڲ�ͬ�����࣬�ֱ������������������տ��Եõ���������
		int firstNum = 0;
		int secondNum = 0;
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] >> firstIndex & 1)
				firstNum ^= nums[i];
			else
				secondNum ^= nums[i];

		res.push_back(firstNum);
		res.push_back(secondNum);
		return res;
	}
};