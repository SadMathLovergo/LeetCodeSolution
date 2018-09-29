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
			if (path[charIndex] != '/') {//若没遍历到'/'
				pathString += path[charIndex];
			}
			else {//若遍历到了'/'
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

		//遍历结束后，将最后一段pathString压入stack中
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