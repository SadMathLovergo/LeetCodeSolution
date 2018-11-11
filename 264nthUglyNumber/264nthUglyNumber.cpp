#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��264�⣺����2
//����˼·��ÿһ��������Ȼ���ø�С��һ��������2��3��5����С�ĳ���Ϊ1������Ĺؼ�������α��ֳ�����������
//���ö�̬�滮�ķ��������м��㣬ÿһ��������2��3��5�����Եõ�һ���µĳ���
//�趨��������index2��index3��index5��index2Ϊ���Գ���2�ĵ�һ��������index3Ϊ���Գ���3�ĵ�һ��������index5Ϊ���Գ���5�ĵ�һ������
//��n������Ϊǰn-1�������е�ĳ���������ֱ��2��3��5�õ���������С��
//ÿһ��ѭ�����ٸ���һ����
class Solution {
public:
	int nthUglyNumber(int n) {
		if (n == 0)
			return 0;

		vector<int> res;
		res.push_back(1);
		
		int index2 = 0;
		int index3 = 0;
		int index5 = 0;

		for (int i = 1; i < n; i++) {
			int num = min(res[index2] * 2, min(res[index3] * 3, res[index5] * 5));
			res.push_back(num);
			if (num == res[index2] * 2)
				index2++;
			if (num == res[index3] * 3)
				index3++;
			if (num == res[index5] * 5)
				index5++;
		}

		return res.back();
	}
};