#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		if (path.empty())
			return path;

		stack<string> record;
		int charIndex = 0;
		string pathString = "";

		while (charIndex < path.size()) {
			if (path[charIndex] != '/') {//��û������'/'
				pathString += path[charIndex];
			}
			else {//����������'/'
				if (pathString != "") {
					if (pathString == "..") {
						if (!record.empty())
							record.pop();
					}
					else if (pathString != ".")
						record.push(pathString);
					pathString = "";
				}
			}
			charIndex++;
		}

		//���������󣬽����һ��pathStringѹ��stack��
		if (pathString != "") {
			if (pathString == "..") {
				if (!record.empty())
					record.pop();
			}
			else if (pathString != ".")
				record.push(pathString);
			pathString = "";
		}

		string ret = "";
		vector<string> resVec;
		while (!record.empty()) {
			resVec.push_back(record.top());
			record.pop();
		}
		for (vector<string>::reverse_iterator iter = resVec.rbegin(); iter != resVec.rend(); iter++) {
			ret += '/';
			ret += *iter;
		}
		if (ret == "")
			return "/";
		return ret;
	}
};

int main() {
	string path = "/..";
	string simplified = Solution().simplifyPath(path);
	cout << simplified << endl;
	system("pause");
	return 0;
}