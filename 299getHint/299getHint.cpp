#pragma once
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

//第299题 猜数字游戏
class Solution {
public:
	string getHint(string secret, string guess) {
		int Bulls = 0;
		int Cows = 0;

		unordered_map<char, int> SecretMap;
		unordered_map<char, int> GuessMap;

		for (int i = 0; i < secret.length(); i++) {
			if (secret[i] == guess[i])
				Bulls++;
			else {
				SecretMap[secret[i]]++;
				GuessMap[guess[i]]++;
			}
		}

		for (unordered_map<char, int>::iterator iter = SecretMap.begin(); iter != SecretMap.end(); iter++)
			Cows += min(iter->second, GuessMap[iter->first]);

		string ret;
		ret += to_string(Bulls) + 'A' + to_string(Cows) + 'B';
		return ret;
	}
};