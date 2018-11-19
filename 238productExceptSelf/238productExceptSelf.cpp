#include <vector>
using namespace std;

//��238�� ��������������ĳ˻�
//����˼·����Ҫʹ��O(N)ʱ�临�Ӷȵ��㷨
//������������α���
//��һ�α�������nums[0]��nums[n-1]���б�����output[i]�д洢��nums[0]��nums[i-1]�ĳ˻�������һ����ÿ�μ�����Ի�����һ�εļ���������Сʱ�临�Ӷ�
//�ڶ��α�������nums[n-1]��nums[0]���б�����output[i]�д洢���յĽ��
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> output(nums.size(), 0);
		output[0] = 1;

		//��һ�ֱ���
		for (int i = 1; i < output.size(); i++)
			output[i] = output[i - 1] * nums[i - 1];

		//�ڶ��ֱ���
		for (int i = output.size() - 2, temp = nums[i + 1]; i >= 0; i--) {
			output[i] *= temp;
			temp *= nums[i];
		}

		return output;
	}
};

int main() {
	vector<int> nums{ 1,2,3 };
	Solution().productExceptSelf(nums);

	system("pause");
	return 0;
}