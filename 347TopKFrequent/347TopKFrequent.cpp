#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		//统计元素出现次数[数据，频率]
		unordered_map<int, int> FreqMap;
		for (int i = 0; i < nums.size(); i++)
			FreqMap[nums[i]]++;

		//保存数据出现的频率，记录格式为<频率，数据>
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> QueueK;
		for (unordered_map<int, int>::iterator iter = FreqMap.begin(); 
			iter != FreqMap.end(); iter++) {

			if (QueueK.size() == k) {
				if (iter->second > QueueK.top().first) {
					QueueK.pop();
					QueueK.push(make_pair(iter->second, iter->first));
				}
			}
			else
				QueueK.push(make_pair(iter->second, iter->first));
		}

		stack<int> resStack;
		while (!QueueK.empty()) {
			resStack.push(QueueK.top().second);
			QueueK.pop();
		}

		vector<int> resVec;
		while (!resStack.empty()) {
			resVec.push_back(resStack.top());
			resStack.pop();
		}

		return resVec;
	}
};

int main() {
	Solution solution;
	vector<int> vec{ 1,1,1,2,2,3 };
	vector<int> ret = solution.topKFrequent(vec, 2);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";

	system("pause");
	return 0;
}