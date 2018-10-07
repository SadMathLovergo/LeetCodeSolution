#include <vector>
#include <algorithm>
using namespace std;

/*��45�� ��Ծ��Ϸ2*/
/*ʹ�ö�̬�滮*/
class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() <= 1)
			return 0;

		/*[beginIndex,endIndex]��Ҫ����С��Ծ����ΪcurStep-1*/
		int beginIndex = 0;
		int endIndex = 0;
		int curStep = 1;

		while (true) {
			/*�ҵ���Ҫ��С��Ծ����ΪcurStep������[nextBeginIndex,nextEndIndex]*/
			int nextBeginIndex = endIndex + 1;
			int nextEndIndex = nextBeginIndex;
			/*��[beginIndex,endIndex]������б���*/
			for (int i = beginIndex; i <= endIndex; i++) {
				int jumpSize = nums[i];

				if (i + jumpSize >= nums.size() - 1)
					return curStep;
				/*�ҵ���һ��������Ҷˣ���[beginIndex,endIndex]������������Զ�ľ���*/
				nextEndIndex = max(nextEndIndex, i + jumpSize);
			}
			beginIndex = nextBeginIndex;
			endIndex = nextEndIndex;
			curStep++;
		}
	}
};