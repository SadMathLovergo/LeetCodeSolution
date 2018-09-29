#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		if (s.empty())
			return true;

		int si = 0, ti = 0;
		while (ti < t.size()) {
			if (s[si] == t[ti]) {
				si++;
				ti++;
				if (si == s.size())
					return true;
			}
			else {
				ti++;
			}
		}
		return false;
	}
};