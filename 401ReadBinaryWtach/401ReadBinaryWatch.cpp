#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<string> resVec;
	vector<vector<string>> hourMemory;
	vector<vector<string>> minuteMemory;

	//总共要亮fireNum个灯，已经亮了curFire个灯，当前遍历到了序列为curIndex的灯，当前数值为curNum
	void countHourCombination(int fireNum, int curFire, int curIndex, int curNum, vector<string>& memory) {
		if (fireNum == curFire) {//已经亮了足够的灯
			memory.push_back(to_string(curNum));
			return;
		}
		if (curIndex >= 4)//已遍历完所有的灯，但没有亮足够的灯
			return;
		countHourCombination(fireNum, curFire, curIndex + 1, curNum, memory);//当前灯不亮，进行递归
		int nextNum = curNum + pow(2, curIndex);
		if (nextNum > 11)
			return;
		countHourCombination(fireNum, curFire + 1, curIndex + 1, nextNum, memory);//当前灯亮，进行递归
	}
	//总共要亮fireNum个灯，已经亮了curFire个灯，当前遍历到了序列为curIndex的灯，当前数值为curNum
	void countMinuteCombination(int fireNum, int curFire, int curIndex, int curNum, vector<string>& memory) {
		if (fireNum == curFire) {//已经亮了足够的灯
			string str = curNum >= 10 ? to_string(curNum) : '0' + to_string(curNum);
			memory.push_back(str);
			return;
		}
		if (curIndex >= 6)//已遍历完所有的灯，但没有亮足够的灯
			return;
		countMinuteCombination(fireNum, curFire, curIndex + 1, curNum, memory);//当前灯不亮，进行递归
		int nextNum = curNum + pow(2, curIndex);
		if (nextNum > 59)
			return;
		countMinuteCombination(fireNum, curFire + 1, curIndex + 1, nextNum, memory);//当前灯亮，进行递归
	}

	//小时灯亮fireNum个的组合情况
	void countHourCombination(int fireNum) {
		if (fireNum > 4)
			return;
		vector<string> curMemory;
		countHourCombination(fireNum, 0, 0, 0, curMemory);
		hourMemory.push_back(curMemory);
	}

	//分钟灯亮fireNum个的组合情况
	void countMinuteCombination(int fireNum) {
		if (fireNum > 6)
			return;
		vector<string> curMemory;
		countMinuteCombination(fireNum, 0, 0, 0, curMemory);
		minuteMemory.push_back(curMemory);
	}
	
public:
	vector<string> readBinaryWatch(int num) {
		resVec.clear();
		hourMemory.clear();
		minuteMemory.clear();

		if (num > 10 || num < 0)
			return resVec;

		int hourMaxNum = (num >= 4) ? 4 : num;			//小时灯能亮的最大数
		int hourMinNum = (num <= 6) ? 0 : num - 6;		//小时灯能亮的最小数
		int minuteMaxNum = (num >= 6) ? 6 : num;		//分钟灯能亮的最大数
		int minuteMinNum = (num <= 4) ? 0 : num - 4;	//分钟灯能亮的最小数

		for (int i = hourMinNum; i <= hourMaxNum; i++) {
			countHourCombination(i);
		}

		for (int i = minuteMinNum; i <= minuteMaxNum; i++) {
			countMinuteCombination(i);
		}

		vector<vector<string>>::iterator hourIter = hourMemory.begin();
		vector<vector<string>>::reverse_iterator minuteIter = minuteMemory.rbegin();
		for (; hourIter != hourMemory.end(); ) {
			for (int i = 0; i < hourIter->size(); i++) {
				for (int j = 0; j < minuteIter->size(); j++) {
					resVec.push_back(hourIter->at(i) + ':' + minuteIter->at(j));
				}
			}


			hourIter++;
			minuteIter++;
		}

		return resVec;
	}
};