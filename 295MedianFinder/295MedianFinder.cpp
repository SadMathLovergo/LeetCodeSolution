#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class MedianFinder {
private:
	vector<int> leftHeap;
	vector<int> rightHeap;
public:
	/** initialize your data structure here. */
	MedianFinder() {
		leftHeap.clear();
		rightHeap.clear();
	}

	void addNum(int num) {
		if (leftHeap.size() == rightHeap.size()) {
			leftHeap.push_back(num);
			push_heap(leftHeap.begin(), leftHeap.end(), less<int>());

			int num = leftHeap[0];
			pop_heap(leftHeap.begin(), leftHeap.end(), less<int>());

			leftHeap.pop_back();

			rightHeap.push_back(num);
			push_heap(rightHeap.begin(), rightHeap.end(), greater<int>());
		}
		else {
			rightHeap.push_back(num);
			push_heap(rightHeap.begin(), rightHeap.end(), greater<int>());

			int num = rightHeap[0];
			pop_heap(rightHeap.begin(), rightHeap.end(), greater<int>());
			rightHeap.pop_back();

			leftHeap.push_back(num);
			push_heap(leftHeap.begin(), leftHeap.end(), less<int>());
		}
	}

	double findMedian() {
		if (rightHeap.size() == 0)
			throw new exception;
		if (leftHeap.size() == rightHeap.size())
			return (double)(leftHeap[0] + rightHeap[0]) / 2;
		else
			return rightHeap[0];
	}
};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder obj = new MedianFinder();
* obj.addNum(num);
* double param_2 = obj.findMedian();
*/