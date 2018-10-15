#include <vector>
using namespace std;

/*��96�� ��ͬ�Ķ���������*/
//����˼·�����͵Ķ�̬�滮��Ŀ
//����ÿһ������1~n��n���ڵ�Ķ������������ԣ����������������������ڷֱ𽫽ڵ�i��Ϊ���ڵ�ʱ�Ķ�������������֮��
//���ڵ�i��Ϊ���ڵ�ʱ���������������������ڽڵ�1~�ڵ�i-1���ܹ��ɵĶ������������������Խڵ�i+1~�ڵ�n���ܹ��ɵĶ���������������
class Solution {
public:
	int numTrees(int n) {
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;

		//�趨��ʼֵ
		vector<int> memo(n + 1, 0);
		memo[0] = 1;
		memo[1] = 1;
		memo[2] = 2;

		//����1~i��i���ڵ����ܹ��ɵĶ���������������
		for (int i = 3; i <= n; i++) {
			//��rootΪ���ڵ�ʱ�����ܹ��ɵĶ���������������
			for (int root = 1; root <= i; root++)
				memo[i] += memo[root - 1] * memo[i - root];
		}

		return memo[n];
	}
};