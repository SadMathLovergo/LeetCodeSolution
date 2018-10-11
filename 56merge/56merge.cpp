#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

/*��56�� �ϲ�����*/
/*����˼·���Ƚ����䰴startֵ��������Ȼ����кϲ�*/

bool compare(Interval& interval1, Interval& interval2) {
	if (interval1.start != interval2.start)
		return interval1.start < interval2.start;
	else
		return interval1.end < interval2.end;
}

class Solution {
private:
	void pushInterval(vector<Interval>& memo, Interval& interval) {
		if (!memo.empty() && interval.start <= memo.back().end)
			memo.back().end = max(interval.end, memo.back().end);
		else
			memo.push_back(interval);
	}

public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> memo;//memo�����Ѿ��ϲ������䣬�������Ծɰ���start�������У������������以������

		sort(intervals.begin(), intervals.end(), compare);

		for (int i = 0; i < intervals.size(); i++)
			pushInterval(memo, intervals[i]);

		return memo;
	}
};