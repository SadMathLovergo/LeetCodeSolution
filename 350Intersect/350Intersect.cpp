#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> record;
		for (int i = 0; i < nums1.size(); i++)
			record[nums1[i]]++;

		vector<int> result;
		for(int i = 0 ; i < nums2.size() ; i++)
			if (record[nums2[i]] > 0) {
				result.push_back(nums2[i]);
				record[nums2[i]]--;
			}

		return result;
	}
};