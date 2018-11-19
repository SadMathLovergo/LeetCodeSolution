#pragma once

#include <vector>
#include <cassert>
using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

//第284题 顶端迭代器
//解题思路：我一开始把题目意思理解错了，没看到“只能使用Iterator接口的方法”
class PeekingIterator : public Iterator {
private:
	int nextNum;
	bool hasNextNum;

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		nextNum = Iterator::next();
		hasNextNum = Iterator::hasNext();
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		return nextNum;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		int retNum = nextNum;
		if (Iterator::hasNext())
			nextNum = Iterator::next();
		else
			hasNextNum = false;
		return retNum;
	}

	bool hasNext() const {
		return hasNextNum;
	}
};