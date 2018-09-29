#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return 0;
		if (s.size() == 1) {
			if (s[0] == '0')
				return 0;
			return 1;
		}

		vector<int> memory(s.size(), 0);
		if (s[0] == '0')
			return 0;
		memory[0] = 1;
		if (s[0] == '1') {
			if (s[1] == '0')
				memory[1] = 1;
			else
				memory[1] = 2;
		}
		else if (s[0] == '2') {
			if (s[1] >= '1' && s[1] <= '6')
				memory[1] = 2;
			else
				memory[1] = 1;
		}
		else {
			if (s[1] == '0')
				return 0;
			memory[1] = 1;
		}

		for (int i = 2; i < s.size(); i++) {
			if (s[i - 1] == '1') {
				if (s[i] == '0')
					memory[i] = memory[i - 2];
				else
					memory[i] = memory[i - 2] + memory[i - 1];
			}
			else if (s[i - 1] == '2') {
				if (s[i] >= '1' && s[i] <= '6')
					memory[i] = memory[i - 2] + memory[i - 1];
				else if (s[i] == '0')
					memory[i] = memory[i - 2];
				else
					memory[i] = memory[i - 1];
			}
			else {
				if (s[i] == '0')
					return 0;
				else
					memory[i] = memory[i - 1];
			}
		}

		return memory[s.size() - 1];
	}
};

int main() {
	string s = "227";
	int res = Solution().numDecodings(s);
	cout << res << endl;

	system("pause");
	return 0;
}