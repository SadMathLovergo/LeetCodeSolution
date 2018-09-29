#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end(), greater<int>());
		sort(s.begin(), s.end(), greater<int>());
		int gi = 0, si = 0;
		int res = 0;

		while (gi < g.size() && si < s.size()) {
			if (g[gi] <= s[si]) {
				res++;
				gi++;
				si++;
			}
			else{
				gi++;
			}
		}

		return res;
	}
};