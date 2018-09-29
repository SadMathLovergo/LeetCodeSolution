#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int indexL = 0;
		int indexR = p.size() - 1;
		int sFreq[256] = { 0 };
		int pFreq[256] = { 0 };
		vector<int> oriIndex;
		bool isTrue = false;
		for (int i = 0; i < p.size(); i++)
			pFreq[p[i]]++;
		for (int i = 0; i < p.size(); i++)
			sFreq[s[i]]++;
		while (indexR < s.size()) {
			isTrue = true;
			for (int i = 0; i < 256; i++)
				if (sFreq[i] != pFreq[i]) {
					isTrue = false;
					break;
				}
			if (isTrue) {
				oriIndex.push_back(indexL);
			}
			sFreq[s[indexL++]]--;
			sFreq[s[++indexR]]++;
		}
		return oriIndex;
	}
};