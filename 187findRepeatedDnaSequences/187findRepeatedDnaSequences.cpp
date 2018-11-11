#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//��187�� �ظ���DNA����
//����˼·��λ��������ã�����λ�����������ַ���
//��"00"������A����"01"������C����"10"������G����"11"������T
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<char, int> temp{ {'A',0},{ 'C',1 },{ 'G',2 },{ 'T',3 } };
		//��¼�Ѿ����ڵ��ַ�����Ӧ��λ������
		unordered_set<int> memo;
		//�����ظ���DNA�����ַ���
		unordered_set<string> res;

		int num = 0;
		int i = 0;
		for (; i < 9; i++)//�Ƚ�ǰ9λ��ת�������������
			num = num << 2 | temp[s[i]];

		while (i < s.size()) {
			//ÿ�μ����µ��ַ���ת�������ֻ���ǰ2λȥ�����Ѻ�18λ������λ��Ȼ����һ���ַ���Ӧ����ֵ�����ĩβ����
			num = ((num & 0x3ffff) << 2) | temp[s[i++]];
			if (memo.find(num) == memo.end())
				memo.insert(num);
			else
				res.insert(s.substr(i - 10, 10));
		}

		return vector<string>(res.begin(), res.end());
	}
};