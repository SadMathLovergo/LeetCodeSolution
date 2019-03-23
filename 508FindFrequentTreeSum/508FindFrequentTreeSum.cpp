#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool compare(const pair<int, int>& pair1, const pair<int, int>& pair2) {
	return pair1.second > pair2.second;
}

class Solution {
private:
	map<int, int> numRecord;
	int findSum(TreeNode* node) {
		if (node == nullptr)
			return 0;
		int sum1 = findSum(node->left);
		int sum2 = findSum(node->right);
		int value = sum1 + sum2 + node->val;
		if (numRecord.find(value) == numRecord.end())
			numRecord.insert(make_pair(value, 1));
		else
			numRecord[value]++;
		return value;
	}

public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		numRecord.clear();
		findSum(root);

		vector<pair<int, int>> recordVec(numRecord.begin(), numRecord.end());
		sort(recordVec.begin(), recordVec.end(), compare);
		vector<int> resVec;

		if (recordVec.empty())
			return resVec;

		int value = recordVec.begin()->second;
		for (auto iter = recordVec.begin(); iter != recordVec.end(); iter++) {
			if (iter->second == value)
				resVec.push_back(iter->first);
			else
				break;
		}

		return resVec;
	}
};

int main() {
	Solution solution;
	solution.findFrequentTreeSum(nullptr);

	system("pause");
	return 0;
}