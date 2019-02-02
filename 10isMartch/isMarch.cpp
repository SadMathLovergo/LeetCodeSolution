#include <string>
using namespace std;

//算法需要优化
class Solution {
private:
	bool Match(string& s, string& p, int sIndex, int pIndex) {
		//若模板字符串已经匹配完毕
		if (pIndex >= p.length())
			return sIndex == s.length();
		//若模板字符串已经匹配到最后一位
		if ((pIndex + 1) == p.length())
			return (sIndex + 1) == s.length() && (s[sIndex] == p[pIndex] || p[pIndex] == '.');
		//若字符串已经匹配完毕
		if (sIndex == s.length())
			return p[pIndex + 1] == '*'&&Match(s, p, sIndex, pIndex + 2);
		//若模板字符串下一个字符为'*'
		if (p[pIndex + 1] == '*') {
			//若当前字符匹配
			if (s[sIndex] == p[pIndex] || p[pIndex] == '.')
				//'*'匹配0个
				return Match(s, p, sIndex, pIndex + 2) ||
				//'*'匹配多个
				Match(s, p, sIndex + 1, pIndex) ||
				//'*'匹配1个
				Match(s, p, sIndex + 1, pIndex + 2);
			//若当前字符不匹配
			return Match(s, p, sIndex, pIndex + 2);
		}
		//若模板字符串下一个不为'*'，且字符匹配
		if (s[sIndex] == p[pIndex] || p[pIndex] == '.')
			return Match(s, p, sIndex + 1, pIndex + 1);
		//若字符不匹配
		return false;
	}

public:
	bool isMatch(string s, string p) {
		return Match(s, p, 0, 0);
	}
};