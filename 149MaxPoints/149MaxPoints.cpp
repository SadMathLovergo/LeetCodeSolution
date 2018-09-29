#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point>& points) {
		if (points.size() < 3)
			return points.size();

		vector<int> resVec;
		for (int i = 0; i < points.size(); i++) {
			//[Point(points中的点)坐标信息,与此Point到points[i]斜率相同的点的数量(包含此Point本身)]
			//unordered_map的key如果使用自定义类型而非原始类型，必须要提供hash实现，因此这里使用map
			//并且由于不能修改Point，所以不能重载Point的<运算符，所以不能用Point作为map的key，只能使用vector<int>来存储Point
			map<vector<int>, int> record;
			int samePoints = 0;//与points[i]坐标相同的点的数量，不包括points[i]本身
			int verticalPoints = 0;//与points[i]垂直的点，不包括points[i]本身
			//对剩下的点进行遍历
			for (int j = i + 1; j < points.size(); j++) {
				if (points[i].x == points[j].x) {
					if (points[i].y == points[j].y)
						samePoints++;
					else
						verticalPoints++;
				}
				else {//既不垂直也不相等
					bool hasSlope = false;
					//查看是否与已存入record中的点到points[i]的斜率相等
					for (map<vector<int>, int>::iterator iter = record.begin(); iter != record.end(); iter++) {
						long long res = (long long)(points[j].y - iter->first[1])*(iter->first[0] - points[i].x) - (long long)(points[j].x - iter->first[0])*(iter->first[1] - points[i].y);
						if (res == 0) {
							iter->second++;
							hasSlope = true;
							break;
						}
					}//如果没有，则将这个点放入map中
					if (!hasSlope) {
						record.insert(make_pair(vector<int>{points[j].x, points[j].y}, 1));
					}
				}
			}
			int temp = 0;
			for (map<vector<int>, int>::iterator iter = record.begin(); iter != record.end(); iter++)
				temp = max(temp, iter->second);
			temp = max(verticalPoints, temp);
			resVec.push_back(temp + samePoints + 1);
		}

		int res = 0;
		for (int i = 0; i < points.size(); i++)
			res = max(res, resVec[i]);
		return res;
	}
};

int main() {
	vector<Point> points{ Point(0,0),Point(1,65536), Point(65536,0) };
	int res = Solution().maxPoints(points);
	cout << res << endl;
	system("pause");
	return 0;
}