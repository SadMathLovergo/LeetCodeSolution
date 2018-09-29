#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int freq[256] = { 0 };
		int indexL = 0, indexR = -1;
		int res = 0;
		while (indexL < s.size()) {
			if (indexR + 1 < s.size() && freq[s[indexR + 1]] == 0)
				freq[s[++indexR]]++;
			else
				freq[s[indexL++]]--;
			res = max(res, indexR - indexL + 1);
		}
		return res;
	}
};