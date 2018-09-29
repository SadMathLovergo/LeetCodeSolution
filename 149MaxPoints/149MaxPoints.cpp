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
			//[Point(points�еĵ�)������Ϣ,���Point��points[i]б����ͬ�ĵ������(������Point����)]
			//unordered_map��key���ʹ���Զ������Ͷ���ԭʼ���ͣ�����Ҫ�ṩhashʵ�֣��������ʹ��map
			//�������ڲ����޸�Point�����Բ�������Point��<����������Բ�����Point��Ϊmap��key��ֻ��ʹ��vector<int>���洢Point
			map<vector<int>, int> record;
			int samePoints = 0;//��points[i]������ͬ�ĵ��������������points[i]����
			int verticalPoints = 0;//��points[i]��ֱ�ĵ㣬������points[i]����
			//��ʣ�µĵ���б���
			for (int j = i + 1; j < points.size(); j++) {
				if (points[i].x == points[j].x) {
					if (points[i].y == points[j].y)
						samePoints++;
					else
						verticalPoints++;
				}
				else {//�Ȳ���ֱҲ�����
					bool hasSlope = false;
					//�鿴�Ƿ����Ѵ���record�еĵ㵽points[i]��б�����
					for (map<vector<int>, int>::iterator iter = record.begin(); iter != record.end(); iter++) {
						long long res = (long long)(points[j].y - iter->first[1])*(iter->first[0] - points[i].x) - (long long)(points[j].x - iter->first[0])*(iter->first[1] - points[i].y);
						if (res == 0) {
							iter->second++;
							hasSlope = true;
							break;
						}
					}//���û�У�����������map��
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