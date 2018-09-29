#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<char, string> record;
		string::iterator patIter = pattern.begin();
		string::iterator strIter = str.begin();

		while (patIter != pattern.end() && strIter != str.end()) {
			/*���ַ����н���һ�����ַ����������*/
			string newStr;
			while ( strIter != str.end() && *strIter != ' ') {
				newStr += *strIter;
				strIter++;
			}
			/*��ѯ�ü�ֵ�Ƿ����ģʽ*/
			if (record.find(*patIter) == record.end()) {/*����ѯ�����˼�*/
				/*����������Ӧ��ֵΪ�����ַ������򲻷���ģʽ*/
				for (unordered_map<char, string>::iterator iter = record.begin(); iter != record.end(); iter++) {
					if (iter->second == newStr)
						return false;
				}
				/*�������ڴ˼�-ֵ�ԣ��򽫴˼�-ֵ�Լ����ֵ���*/
				record[*patIter] = newStr;

			}
			else {
				/*�����ѯ���˼�����鿴��ֵ�Ƿ����ģʽ*/
				if (record[*patIter] != newStr)
					return false;
			}

			patIter++;
			if (strIter != str.end())
				strIter++;
		}

		if (patIter != pattern.end() || strIter != str.end())
			return false;

		return true;
	}
};

int main() {
	Solution solution;
	string pattern = "abba";
	string str = "dog cat cat dog";
	if (solution.wordPattern(pattern, str))
		cout << "���ϵ���ģʽ" << endl;
	else
		cout << "�����ϵ���ģʽ" << endl;

	system("pause");
	return 0;
}