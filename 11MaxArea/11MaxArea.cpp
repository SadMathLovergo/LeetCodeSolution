#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size() < 2)
			return 0;
		int res = 0;
		for (int i = 0, j = height.size() - 1; i < j;) {
			res = max(res, min(height[i], height[j])*(j - i));
			if (height[i] < height[j])
				i++;
			else
				j--;
		}
		return res;
	}
};