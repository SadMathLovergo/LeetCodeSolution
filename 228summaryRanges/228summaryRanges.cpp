#include <string>
#include <vector>
using namespace std;

//��228�� ��������
//����˼·��
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> memo;
		int i = 0;
		while (i < nums.size()) {
			int j = i + 1;
			while (j < nums.size() && nums[j] - nums[j - 1] == 1)
				j++;
			//��ֻ��һ����
			if (j - 1 == i)
				memo.push_back(to_string(nums[i]));
			else//���ж����
				memo.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
			i = j;
		}
		return memo;
	}
};