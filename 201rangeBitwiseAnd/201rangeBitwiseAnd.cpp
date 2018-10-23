#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��201�� ���ַ�Χ��λ��
//����˼·���ҵ���m��n�Ķ����ƣ��Ӹ�λ����λ����ͬ�Ĳ��֣�ʣ�²������㣬��Ϊ���յĽ��
//�����Ǵ���֮ǰ�ķ���̫����
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int i = 0;
		while (m != n) {
			m >>= 1;
			n >>= 1;
			i++;
		}
		return m << i;
	}
};

int main() {
	int res = Solution().rangeBitwiseAnd(5, 7);
	cout << res << endl;
	system("pause");
	return 0;
}