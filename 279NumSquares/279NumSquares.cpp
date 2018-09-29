#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		assert(n > 0);

		queue<pair<int, int>> QueueRecord;
		QueueRecord.push(make_pair(n, 0));

		vector<bool> Visited(n + 1, false);
		Visited[n] = true;

		while (!QueueRecord.empty()) {
			pair<int, int> newPair = QueueRecord.front();
			QueueRecord.pop();

			int num = newPair.first;
			int step = newPair.second;

			if (num == 0)
				return step;

			for (int i = 1; ; i++) {
				int result = num - i * i;
				if (result < 0)
					break;
				if (result == 0)
					return step + 1;
				if (!Visited[result]) {
					QueueRecord.push(make_pair(result, step + 1));
					Visited[result] = true;
				}
			}
		}
		throw invalid_argument("No Solution.");
	}
};