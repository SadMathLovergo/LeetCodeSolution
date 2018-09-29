#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> record;
		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
			if (record.find(*iter) != record.end())
				return true;
			record.insert(*iter);
		}
		return false;
	}
};