#include <string>
#include <stack>
#include <vector>
using namespace std;

//整数转罗马数字
//解题思路：对每一位上的数字分别进行转换，每一位上的数字转换方法相同，唯一不同的是使用的罗马数字不同
class Solution {
private:
	//每一位上的罗马数字，由于千位上的数字小于4，因此使用三个相同的罗马数字
	vector<vector<char>> RomanChar{ 
		vector<char>{'I','V','X'},
		vector<char>{'X','L','C'},
		vector<char>{'C','D','M'},
		vector<char>{'M','M','M'} 
	};

	string formRoman(int num, vector<char> RomanChar) {
		string res;
		if (num < 4) {//num小于4
			while (num > 0) {
				res += RomanChar[0];
				num--;
			}
			return res;
		}
		else if (num == 4) {//num为4
			res += RomanChar[0];
			res += RomanChar[1];
			return res;
		}
		else if (num < 9) {//num大于4小于9
			res += RomanChar[1];
			while (num > 5) {
				res += RomanChar[0];
				num--;
			}
			return res;
		}
		else {//num为9
			res += RomanChar[0];
			res += RomanChar[2];
			return res;
		}
	}

	

public:
	string intToRoman(int num) {
		string resStr;//最后的罗马数字结果

		stack<int> numRecord;//保存每一位数字的堆栈

		/*将数字从低位到高位压入堆栈中*/
		while (num != 0) {
			numRecord.push(num % 10);
			num /= 10;
		}

		/*将每一位的数字转换为罗马数字*/
		while (!numRecord.empty()) {
			resStr += formRoman(numRecord.top(), RomanChar[numRecord.size()-1]);
			numRecord.pop();
		}

		return resStr;
	}
};