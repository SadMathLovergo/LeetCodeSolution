#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		string::iterator sIter = s.begin();
		string::iterator tIter = t.begin();
		unordered_map<char, char> record;
		while (sIter != s.end()) {
			/*������в����ҵ��˼�*/
			if (record.find(*sIter) == record.end()) {
				/*�鿴��ֵ�����������Ƿ��Ѿ�����*/
				for (unordered_map<char, char>::iterator iter = record.begin(); 
					iter != record.end(); iter++) {
					/*����ֵ���������д��ڣ��򷵻�false*/
					if (iter->second == *tIter)
						return false;
				}
				/*�������ڣ����½��˼�ֵ��*/
				record[*sIter] = *tIter;
			}
			/*������ҵ��˼�*/
			else
			{
				if (record[*sIter] != *tIter)
					return false;
			}

			sIter++;
			tIter++;
		}
		return true;
	}
};