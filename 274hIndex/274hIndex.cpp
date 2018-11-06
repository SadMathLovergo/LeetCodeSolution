#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

bool myLess(int m, int n) {
	return m > n;
}

//��274�⣺Hָ��
//����˼·�������鰴�������У��ҵ�citations[num]��ʹ�õ�i < numʱ��citations[i] >= num����i > = numʱ��citations[i] < num��num��ΪHָ��
class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end(), myLess);
		int i = 0;
		while (i < citations.size() && citations[i] >= i + 1)
			i++;
		return i;
	}
};

int main() {
	vector<int> citations{ 230,217,203,120,50,177,118,236,209,98,156,15,126,4,15,113,49,173,25,88,115,73,46,152,64,47,160,111,194,119,234,72,79,89,37,14,31,15,21,77,246,192,230,53,14,200,190,40,74,227 };
	cout << Solution().hIndex(citations) << endl;
	system("pause");
	return 0;
}