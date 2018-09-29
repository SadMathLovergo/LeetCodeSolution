#include <vector>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
	const string numStr[10] = {
		" ",
		"",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz"
	};

	vector<string> vec;

	vector<string> letterCombinations(string digits) {
		vec.clear();
		if (digits == "")
			return vec;

		letterCombinations(digits, 0, "");
		return vec;
	}


private:
	void letterCombinations(const string& digits, int index, const string& s) {
		if (index == digits.size()) {
			vec.push_back(s);
			return;
		}

		char c = digits[index];
		assert(c >= '0' && c <= '9' && c != '1');

		string letters = numStr[c - '0'];
		for (int i = 0; i < letters.size(); i++)
			letterCombinations(digits, index + 1, s + letters[i]);
		return;
	}
};