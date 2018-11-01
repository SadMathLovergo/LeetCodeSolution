#include <iostream>
#include <algorithm>
using namespace std;

//第223题 矩形面积
//解题思路：这有个啥解题思路？
class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int OriArea = (C - A)*(D - B) + (G - E)*(H - F);

		if (A >= G || C <= E || B >= H || D <= F)
			return OriArea;

		return OriArea - (min(C, G) - max(A, E))*(min(D, H) - max(B, F));
	}
};