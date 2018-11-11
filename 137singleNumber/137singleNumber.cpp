#include <vector>
#include <iostream>
using namespace std;

//��137�� ֻ����һ�ε�����2
//����˼·�������߼�λ�����˼·
//ͳ��ÿһλ��1���ֵĴ���
//��ֻ�������ε���������һλ��1������һλ��1���ֵĴ�����3ȡ�����1
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int> bitMemo(32, 0);
		int res = 0;

		for (auto num : nums) //����ÿһ����
			for (int i = 0; i < 32; i++) //�ӵ�λ����λ
				bitMemo[i] = (bitMemo[i] + ((num >> i) & 1)) % 3;

		for (int i = 0; i < 32; i++)
			res = res | (bitMemo[i] << i);

		return res;
	}
};

int main() {
	vector<int> nums{ 2,2,3,2 };
	int res = Solution().singleNumber(nums);
	cout << res << endl;
	system("pause");
	return 0;
}