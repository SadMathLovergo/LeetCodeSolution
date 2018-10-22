#include <string>
#include <iostream>
using namespace std;

//第165题 比较版本号
//解题思路：利用递归函数进行递归比较
class Solution {
private:
	int compareVersion(string version1, int index1, string version2, int index2) {
		//若两个版本号均已无法读取，则意味着两个版本号相等
		if (index1 >= version1.length() && index2 >= version2.length())
			return 0;

		int endIndex1 = index1;
		int endIndex2 = index2;

		while (endIndex1 < version1.length() && version1[endIndex1] != '.')
			endIndex1++;
		while (endIndex2 < version2.length() && version2[endIndex2] != '.')
			endIndex2++;

		int versionNum1 = 0;
		int versionNum2 = 0;

		if (endIndex1 == index1) {//version1此次已经无法读取
			versionNum2 = stoi(version2.substr(index2, endIndex2 - index2));
			if (endIndex2 >= version2.length())//若version2此次已经读完
				return versionNum2 == 0 ? 0 : -1;
			else
				return versionNum2 != 0 ? -1 : compareVersion(version1, endIndex1, version2, endIndex2 + 1);
		}
		else if (endIndex2 == index2) {//version2此次已经无法读取
			versionNum1 = stoi(version1.substr(index1, endIndex1 - index1));
			if (endIndex1 >= version1.length())//若version1此次已经读完
				return versionNum1 == 0 ? 0 : 1;
			else
				return versionNum1 != 0 ? 1 : compareVersion(version1, endIndex1 + 1, version2, endIndex2);
		}
		else {//都可以读取
			versionNum1 = stoi(version1.substr(index1, endIndex1 - index1));
			versionNum2 = stoi(version2.substr(index2, endIndex2 - index2));
		}


		if (versionNum1 < versionNum2)
			return -1;
		else if (versionNum1 > versionNum2)
			return 1;
		else
			return compareVersion(version1, endIndex1 + 1, version2, endIndex2 + 1);
	}

public:
	int compareVersion(string version1, string version2) {
		return compareVersion(version1, 0, version2, 0);
	}
};