#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;

		if (k > nums.size() || k <= 0)
			return result;

		priority_queue<pair<int, int>> queueRecord;

		for (int i = 0; i < k - 1; i++)
			queueRecord.push(make_pair(nums[i], i));

		for (int i = k - 1; i < nums.size(); i++) {
			queueRecord.push(make_pair(nums[i], i));
			auto item = queueRecord.top();
			while (item.second < i - (k - 1)) {
				queueRecord.pop();
				item = queueRecord.top();
			}
			result.push_back(item.first);
		}
		return result;
	}
};