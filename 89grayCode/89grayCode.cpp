#include <vector>
#include <cmath>
using namespace std;

/*第89题 格雷编码*/
//思路：不可描述的思路
//n+1位的格雷编码，可在n位的格雷编码的基础上进行逆遍历，用2^n加上n位格雷编码的值，即为n+1位格雷编码比n位的格雷编码多出来的数值
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> resVec;
		resVec.push_back(0);

		/*在i-1位格雷编码的基础上，将i位的格雷编码计算出来，并保存至resVec中*/
		for (int i = 0; i < n; i++) {
			int curSize = resVec.size();
			int oriNum = pow(2,i);
			int size = pow(2, i);//i+1位的格雷编码数量比i位的格雷编码数量多2^i个
			/*进行逆遍历*/
			for (int j = 1; j <= size; j++)
				resVec.push_back(oriNum + resVec[curSize - j]);
		}

		return resVec;
	}
};