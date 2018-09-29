#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
	queue<int> memory;
	void splitNestedInteger(const vector<NestedInteger> &nestedList, queue<int>& queueMemory) {
		for (vector<NestedInteger>::const_iterator iter = nestedList.begin(); iter != nestedList.end(); iter++) {
			if (iter->isInteger()) {
				queueMemory.push(iter->getInteger());
			}
			else {
				splitNestedInteger(iter->getList(), queueMemory);
			}
		}
	}
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		splitNestedInteger(nestedList, memory);
	}

	int next() {
		int ret = memory.front();
		memory.pop();
		return ret;
	}

	bool hasNext() {
		return !memory.empty();
	}
};

/**
* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();
*/