#include <vector>
#include <map>
#include <utility>
using namespace std;

class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		vector<double> result;

		if (k > nums.size() || k <= 0)
			return result;

		map<int, int> numRecord;

		for (int i = 0; i < k - 1; i++)
			if (numRecord.find(nums[i]) != numRecord.end())
				numRecord[nums[i]]++;
			else
				numRecord.insert(make_pair(nums[i], 1));

		for (int i = k - 1; i < nums.size(); i++) {
			//插入新元素
			if (numRecord.find(nums[i]) != numRecord.end())
				numRecord[nums[i]]++;
			else
				numRecord.insert(make_pair(nums[i], 1));

			//奇数个
			if (k % 2) {
				int sum = 0;
				int target = (k + 1) / 2;
				for (auto iter = numRecord.begin(); iter != numRecord.end(); iter++) {
					sum += iter->second;
					if (sum >= target) {
						result.push_back(iter->first);
						break;
					}
				}
			}
			else {//偶数个
				int sum = 0;
				int num1 = k / 2;
				int num2 = num1 + 1;
				for (auto iter = numRecord.begin(); iter != numRecord.end(); iter++) {
					sum += iter->second;
					if (sum >= num1) {
						long item1 = iter->first;
						long item2 = 0;
						if (sum >= num2)
							item2 = iter->first;
						else
							item2 = (++iter)->first;
						result.push_back(((double)item1 + (double)item2) / 2);
						break;
					}
				}
			}

			//弹出第一个元素
			numRecord[nums[i - (k - 1)]]--;
			if (numRecord[nums[i - (k - 1)]] == 0)
				numRecord.erase(nums[i - (k - 1)]);
		}

		return result;
	}
};