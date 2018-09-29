#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
	void restoreIpAddresses(string s, int charIndex, vector<string>& ipAddress, vector<string>& resVec) {
		/*�����ǰ�ַ����Ѿ������ϣ����Ѿ�����ip���򽫹��ɵ�ip��ַѹ��resVec��*/
		if (charIndex == s.size() && ipAddress.size() == 4) {
			string ip = ipAddress[0] + '.' + ipAddress[1] + '.' + ipAddress[2] + '.' + ipAddress[3];
			resVec.push_back(ip);
			return;
		}
		else if (charIndex == s.size() || ipAddress.size() == 4) {/*����ַ��������꣬��δ����ip�����߹���ip�����ַ���δ������*/
			return;
		}
		for (int i = 1; i <= 3; i++) {
			if (s[charIndex] == '0' && i > 1)
				break;
			/*����ȡ�ַ�������255���������г����ַ�����Χ*/
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