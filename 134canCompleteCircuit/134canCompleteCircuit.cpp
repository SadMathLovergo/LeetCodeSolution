#include <vector>
using namespace std;

/*��134�� ����վ*/
//����˼·���������Ϻ󣬻��˼·
//���Ӽ���վi��������վ���޷��������վj��jΪ��һ���޷�����ļ���վ�������i��j֮���κ�һ������վ���������޷�����j
//�����м���վ���͵��ܺʹ��������͵��ܺͣ����Ȼ��һ������վ������һȦ
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int startPort = 0;	//��ʼ����վ
		int totalGas = 0;	//�ӵ�0������վ��ʼ������ǰ����վ��ʣ����
		int curGas = 0;		//��ǰ��ʣ����

		for (int i = 0; i < gas.size(); i++) {
			//���ӵ�startPort������վ�޷�����i+1������վ����ӵ�i+1���ڵ㿪ʼ���¼���
			if ((curGas += gas[i] - cost[i]) < 0) {
				startPort = i + 1;
				totalGas += curGas;
				curGas = 0;
			}
		}

		return (totalGas + curGas) >= 0 ? startPort : -1;
	}
};