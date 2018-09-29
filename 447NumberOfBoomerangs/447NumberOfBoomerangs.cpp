#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int res = 0;

		for (int i = 0; i < points.size(); i++) {

			unordered_map<int, int> record;
			for (int j = 0; j < points.size(); j++) {
				if (j != i)
					record[distance(points[i], points[j])]++;
			}

			for (unordered_map<int, int>::iterator iter = record.begin(); iter != record.end(); iter++) {
				res += iter->second*(iter->second - 1);
			}
		}

		return res;
	}

private:
	int distance(pair<int, int>& A, pair<int, int>& B) {
		return (A.first - B.first)*(A.first - B.first) + (A.second - B.second)*(A.second - B.second);
	}
};