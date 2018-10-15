#include <vector>
#include <cmath>
using namespace std;

/*��89�� ���ױ���*/
//˼·������������˼·
//n+1λ�ĸ��ױ��룬����nλ�ĸ��ױ���Ļ����Ͻ������������2^n����nλ���ױ����ֵ����Ϊn+1λ���ױ����nλ�ĸ��ױ�����������ֵ
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> resVec;
		resVec.push_back(0);

		/*��i-1λ���ױ���Ļ����ϣ���iλ�ĸ��ױ�������������������resVec��*/
		for (int i = 0; i < n; i++) {
			int curSize = resVec.size();
			int oriNum = pow(2,i);
			int size = pow(2, i);//i+1λ�ĸ��ױ���������iλ�ĸ��ױ���������2^i��
			/*���������*/
			for (int j = 1; j <= size; j++)
				resVec.push_back(oriNum + resVec[curSize - j]);
		}

		return resVec;
	}
};