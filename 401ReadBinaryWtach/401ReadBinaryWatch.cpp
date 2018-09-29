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

	//�ܹ�Ҫ��fireNum���ƣ��Ѿ�����curFire���ƣ���ǰ������������ΪcurIndex�ĵƣ���ǰ��ֵΪcurNum
	void countHourCombination(int fireNum, int curFire, int curIndex, int curNum, vector<string>& memory) {
		if (fireNum == curFire) {//�Ѿ������㹻�ĵ�
			memory.push_back(to_string(curNum));
			return;
		}
		if (curIndex >= 4)//�ѱ��������еĵƣ���û�����㹻�ĵ�
			return;
		countHourCombination(fireNum, curFire, curIndex + 1, curNum, memory);//��ǰ�Ʋ��������еݹ�
		int nextNum = curNum + pow(2, curIndex);
		if (nextNum > 11)
			return;
		countHourCombination(fireNum, curFire + 1, curIndex + 1, nextNum, memory);//��ǰ���������еݹ�
	}
	//�ܹ�Ҫ��fireNum���ƣ��Ѿ�����curFire���ƣ���ǰ������������ΪcurIndex�ĵƣ���ǰ��ֵΪcurNum
	void countMinuteCombination(int fireNum, int curFire, int curIndex, int curNum, vector<string>& memory) {
		if (fireNum == curFire) {//�Ѿ������㹻�ĵ�
			string str = curNum >= 10 ? to_string(curNum) : '0' + to_string(curNum);
			memory.push_back(str);
			return;
		}
		if (curIndex >= 6)//�ѱ��������еĵƣ���û�����㹻�ĵ�
			return;
		countMinuteCombination(fireNum, curFire, curIndex + 1, curNum, memory);//��ǰ�Ʋ��������еݹ�
		int nextNum = curNum + pow(2, curIndex);
		if (nextNum > 59)
			return;
		countMinuteCombination(fireNum, curFire + 1, curIndex + 1, nextNum, memory);//��ǰ���������еݹ�
	}

	//Сʱ����fireNum����������
	void countHourCombination(int fireNum) {
		if (fireNum > 4)
			return;
		vector<string> curMemory;
		countHourCombination(fireNum, 0, 0, 0, curMemory);
		hourMemory.push_back(curMemory);
	}

	//���ӵ���fireNum����������
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

		int hourMaxNum = (num >= 4) ? 4 : num;			//Сʱ�������������
		int hourMinNum = (num <= 6) ? 0 : num - 6;		//Сʱ����������С��
		int minuteMaxNum = (num >= 6) ? 6 : num;		//���ӵ������������
		int minuteMinNum = (num <= 4) ? 0 : num - 4;	//���ӵ���������С��

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