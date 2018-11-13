#include <vector>
#include <algorithm>
using namespace std;

//��152�� �˻����������
//����˼·����̬�滮
//�۳˵����ֵ����һ���������ĸ����۳˵���Сֵ������������һ������Ҳ����һ���ܴ����
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int maxNum = nums[0];	//������ǰλ���ڵĳ˻����ֵ
		int minNum = nums[0];	//������ǰλ���ڵĳ˻���Сֵ
		int ans = nums[0];		//��ǰ���ֵ

		for (int i = 1; i < nums.size(); i++) {
			int a = maxNum * nums[i];
			int b = minNum * nums[i];
			maxNum = max(max(a, b), nums[i]);
			minNum = min(min(a, b), nums[i]);
			ans = max(ans, maxNum);
		}

		return ans;

	}
};