#include <vector>
using namespace std;

//第275题：H指数2
//解题思路：给定数组已经按照升序排列，为了降低时间复杂度，采用二分搜索的思路来获得H指数
//关键在于找到分界点i
//若arr[i] <= arr.size()-(i+1)且arr[i+1] >= arr.size()-(i+1)，则H指数为arr.size()-(i+1)
class Solution {
public:
	int hIndex(vector<int>& citations) {
		//若数组为空
		if (citations.empty())
			return 0;
		//若数组只有一个元素
		if (citations.size() == 1)
			return citations[0] >= 1 ? 1 : 0;

		int LeftIndex = 0;
		int RightIndex = citations.size() - 1;
		int curIndex = LeftIndex + (RightIndex - LeftIndex) / 2;

		while (true) {
			//若CurIndex已经到达分界点
			if (citations[curIndex] <= (citations.size() - curIndex - 1) && citations[curIndex + 1] >= (citations.size() - curIndex - 1))
				return citations.size() - curIndex - 1;
			//根据情况压缩区间
			else if (citations[curIndex] > (citations.size() - curIndex - 1)) {
				RightIndex = curIndex - 1;
				if (RightIndex < LeftIndex)
					return citations.size();
			}
			//根据情况压缩区间
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