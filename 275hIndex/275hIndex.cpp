#include <vector>
using namespace std;

//��275�⣺Hָ��2
//����˼·�����������Ѿ������������У�Ϊ�˽���ʱ�临�Ӷȣ����ö���������˼·�����Hָ��
//�ؼ������ҵ��ֽ��i
//��arr[i] <= arr.size()-(i+1)��arr[i+1] >= arr.size()-(i+1)����Hָ��Ϊarr.size()-(i+1)
class Solution {
public:
	int hIndex(vector<int>& citations) {
		//������Ϊ��
		if (citations.empty())
			return 0;
		//������ֻ��һ��Ԫ��
		if (citations.size() == 1)
			return citations[0] >= 1 ? 1 : 0;

		int LeftIndex = 0;
		int RightIndex = citations.size() - 1;
		int curIndex = LeftIndex + (RightIndex - LeftIndex) / 2;

		while (true) {
			//��CurIndex�Ѿ�����ֽ��
			if (citations[curIndex] <= (citations.size() - curIndex - 1) && citations[curIndex + 1] >= (citations.size() - curIndex - 1))
				return citations.size() - curIndex - 1;
			//�������ѹ������
			else if (citations[curIndex] > (citations.size() - curIndex - 1)) {
				RightIndex = curIndex - 1;
				if (RightIndex < LeftIndex)
					return citations.size();
			}
			//�������ѹ������
			else {
				LeftIndex = curIndex + 1;
				if (LeftIndex > RightIndex)
					return 0;
			}

			curIndex = LeftIndex + (RightIndex - LeftIndex) / 2;
			if (curIndex == citations.size() - 1)
				return 0;
		}
		
	}
};