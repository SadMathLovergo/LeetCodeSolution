#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
	void restoreIpAddresses(string s, int charIndex, vector<string>& ipAddress, vector<string>& resVec) {
		/*如果当前字符串已经拆分完毕，且已经构成ip，则将构成的ip地址压入resVec中*/
		if (charIndex == s.size() && ipAddress.size() == 4) {
			string ip = ipAddress[0] + '.' + ipAddress[1] + '.' + ipAddress[2] + '.' + ipAddress[3];
			resVec.push_back(ip);
			return;
		}
		else if (charIndex == s.size() || ipAddress.size() == 4) {/*如果字符串遍历完，而未构成ip，或者构成ip，但字符串未遍历完*/
			return;
		}
		for (int i = 1; i <= 3; i++) {
			if (s[charIndex] == '0' && i > 1)
				break;
			/*若截取字符串超过255，或者序列超出字符串范围*/
			if (charIndex + i > s.size() || stoi(s.substr(charIndex, i)) > 255)
				break;
			ipAddress.push_back(s.substr(charIndex, i));
			restoreIpAddresses(s, charIndex + i, ipAddress, resVec);
			ipAddress.pop_back();
		}
	}

public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> resVec;

		if (s.size() < 4)
			return resVec;

		vector<string> ipAddress;
		restoreIpAddresses(s, 0, ipAddress, resVec);

		return resVec;
	}
};

int main() {
	string s = "010010";
	vector<string> res = Solution().restoreIpAddresses(s);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	system("pause");
	return 0;
}