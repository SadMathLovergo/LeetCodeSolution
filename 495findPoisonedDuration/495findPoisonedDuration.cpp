#include <vector>
using namespace std;

/*µÚ495Ìâ ÌáÄª¹¥»÷*/
class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		if (timeSeries.empty() || duration == 0)
			return 0;

		int res = 0;
		for (int i = 0; i < timeSeries.size() - 1; i++) {
			int dur = timeSeries[i + 1] - timeSeries[i];
			if (dur >= duration)
				res += duration;
			else
				res += (dur);
		}
		res += duration;

		return res;
	}
};