#include <string>
using namespace std;

//�㷨��Ҫ�Ż�
class Solution {
private:
	bool Match(string& s, string& p, int sIndex, int pIndex) {
		//��ģ���ַ����Ѿ�ƥ�����
		if (pIndex >= p.length())
			return sIndex == s.length();
		//��ģ���ַ����Ѿ�ƥ�䵽���һλ
		if ((pIndex + 1) == p.length())
			return (sIndex + 1) == s.length() && (s[sIndex] == p[pIndex] || p[pIndex] == '.');
		//���ַ����Ѿ�ƥ�����
		if (sIndex == s.length())
			return p[pIndex + 1] == '*'&&Match(s, p, sIndex, pIndex + 2);
		//��ģ���ַ�����һ���ַ�Ϊ'*'
		if (p[pIndex + 1] == '*') {
			//����ǰ�ַ�ƥ��
			if (s[sIndex] == p[pIndex] || p[pIndex] == '.')
				//'*'ƥ��0��
				return Match(s, p, sIndex, pIndex + 2) ||
				//'*'ƥ����
				Match(s, p, sIndex + 1, pIndex) ||
				//'*'ƥ��1��
				Match(s, p, sIndex + 1, pIndex + 2);
			//����ǰ�ַ���ƥ��
			return Match(s, p, sIndex, pIndex + 2);
		}
		//��ģ���ַ�����һ����Ϊ'*'�����ַ�ƥ��
		if (s[sIndex] == p[pIndex] || p[pIndex] == '.')
			return Match(s, p, sIndex + 1, pIndex + 1);
		//���ַ���ƥ��
		return false;
	}

public:
	bool isMatch(string s, string p) {
		return Match(s, p, 0, 0);
	}
};