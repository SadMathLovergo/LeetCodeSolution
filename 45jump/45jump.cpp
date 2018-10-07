#include <vector>
#include <algorithm>
using namespace std;

/*第45题 跳跃游戏2*/
/*使用动态规划*/
class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() <= 1)
			return 0;

		/*[beginIndex,endIndex]需要的最小跳跃步数为curStep-1*/
		int beginIndex = 0;
		int endIndex = 0;
		int curStep = 1;

		while (true) {
			/*找到需要最小跳跃步数为curStep的区间[nextBeginIndex,nextEndIndex]*/
			int nextBeginIndex = endIndex + 1;
			int nextEndIndex = nextBeginIndex;
			/*对[beginIndex,endIndex]区间进行遍历*/
			for (int i = beginIndex; i <= endIndex; i++) {
				int jumpSize = nums[i];

				if (i + jumpSize >= nums.size() - 1)
					return curStep;
				/*找到下一个区间的右端，即[beginIndex,endIndex]所能跳到的最远的距离*/
				nextEndIndex = max(nextEndIndex, i + jumpSize);
			}
			beginIndex = nextBeginIndex;
			endIndex = nextEndIndex;
			curStep++;
		}
	}
};