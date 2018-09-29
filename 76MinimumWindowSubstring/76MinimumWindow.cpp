#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		int sFreq[256] = { 0 };
		int tFreq[256] = { 0 };
		int indexL = 0;		/*�ж�[indexL,indexR]������ַ���*/
		int indexR = t.size() - 1;
		vector<int> tChar;
		bool hasString = true;	/*��ǰ������ַ����Ƿ����������ĸ*/
		string res;

		for (int i = 0; i < t.size(); i++) {
			tFreq[t[i]]++;
		}

		for (int i = 0; i < t.size(); i++) {
			sFreq[s[i]]++;
		}
		/*����t��ӵ�е��ַ����ں���ļ���У�ֻ��Ҫ����t��ӵ�е��ַ�������������Ҫ��������tFreq�����sFreq����������ʱ��*/
		for (int i = 0; i < 256; i++) {
			if (tFreq[i] > 0)
				tChar.push_back(i);
		}

		while (indexR < s.size()) {
			hasString = true;
			/*��û�а���������ĸ����hasStringΪfalse*/
			for (int i = 0; i < tChar.size(); i++) {
				if (sFreq[tChar[i]] < tFreq[tChar[i]])
				{
					hasString = false;
					break;
				}
			}
			/*�������������ĸ���򻬶��������������������������*/
			if (hasString) {
				if (res.size() == 0 || (indexR - indexL + 1) < res.size())
					res = s.substr(indexL, indexR - indexL + 1);
				sFreq[s[indexL++]]--;
			}
			else
				sFreq[s[++indexR]]++;

		}

		return res;
	}
};

int main() {
	Solution solution;
	string s = "ADOBECODEBANC";
	string t = "ABC";
	string res = solution.minWindow(s, t);
	cout << res;
	system("pause");
	return 0;
}