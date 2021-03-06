#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <iostream>
using namespace std;

class Solution {
private:
	vector<vector<string>> resVec;//保存路径结果
	vector<string> pathMemo;//使用DFS时，记录当前路径
	vector<int> lengthMemo;//记录wordList中每个单词到startWord的最短路径长度，若不存在到startWord的路径，或者最短路径长度大于等于endWord到startWord的最短路径长度，则为0

	//判断这两个单词是否只差一个字母
	bool isSimilarWord(string word1, string word2) {
		int difNum = 0;
		for (int i = 0; i < word1.size(); i++)
			if (word1[i] != word2[i]) {
				difNum++;
				if (difNum > 1)
					return false;
			}
		if (difNum == 1)
			return true;
		return false;
	}

	//采用广度优先遍历的方法寻找从wordList[startIndex]到wordList[endIndex]的最短路径长度
	int BFS(int startIndex, int endIndex, vector<vector<bool>>& simWordRecord) {
		queue<pair<int, int>> pathMemory;//(位置，当前步数)
		//先将wordList[startIndex]压入队列中
		pathMemory.push(make_pair(startIndex, 1));

		while (!pathMemory.empty()) {
			int curIndex = pathMemory.front().first;
			int curLength = pathMemory.front().second;
			pathMemory.pop();
			//对与wordList[curIndex]相连的单词进行遍历
			for (int i = 0; i < simWordRecord.size(); i++)
				//若wordList[curIndex]与wordList[i]相连，且wordList[i]还没有被遍历，或者为同一轮对wordList[i]的遍历
				if (simWordRecord[curIndex][i] && (lengthMemo[i] == 0 || lengthMemo[i] == (curLength + 1))) {
					if (i == endIndex) {
						lengthMemo[i] = curLength + 1;
						return curLength + 1;
					}
					pathMemory.push(make_pair(i, curLength + 1));
					lengthMemo[i] = curLength + 1;
					simWordRecord[curIndex][i] = false;
					simWordRecord[i][curIndex] = false;
				}
		}

		return 0;
	}

	//在使用BFS求出最短路径长度后，使用深度优先遍历查找从wordList[startIndex]到wordList[endIndex]的最短路径序列
	//使用递归回溯的方法
	//curLength为当前startIndex在整个路径序列中的位置
	//pathLength为最短路径的长度
	void DFS(int startIndex, int endIndex, int curLength, int pathLength, vector<vector<bool>>& simWordRecord, vector<string>& wordList) {
		pathMemo.push_back(wordList[startIndex]);
		if (curLength == pathLength) {
			//若已经得到一条从startIndex到endIndex的路径
			if (startIndex == endIndex) {
				resVec.push_back(pathMemo);
			}
			pathMemo.pop_back();
			return;
		}
		for (int i = 0; i < wordList.size(); i++) {
			//若该遍历wordList[i]与wordList[startIndex]相连，且wordList[i]在最短路径位置上，则进行对wordList[i]继续进行DFS
			if (simWordRecord[startIndex][i] && lengthMemo[i] == curLength + 1) {
				simWordRecord[startIndex][i] = false;
				simWordRecord[i][startIndex] = false;
				DFS(i, endIndex, curLength + 1, pathLength, simWordRecord, wordList);
				simWordRecord[startIndex][i] = true;
				simWordRecord[i][startIndex] = true;
			}
		}
		pathMemo.pop_back();
	}

public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		resVec.clear();
		pathMemo.clear();

		if (wordList.empty())
			return resVec;

		//判断wordList中是否有endWord，并找出endWord的索引
		int endWordIndex = -1;
		for (int i = 0; i < wordList.size(); i++)
			if (endWord == wordList[i]) {
				endWordIndex = i;
				break;
			}
		if (endWordIndex == -1)
			return resVec;

		//将beginWord压入wordList中
		wordList.push_back(beginWord);
		int n = wordList.size();

		lengthMemo = vector<int>(n, 0);
		lengthMemo[n - 1] = 1;

		//用于记录每两个单词是否可以转化
		vector<vector<bool>> simWordRecord(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (isSimilarWord(wordList[i], wordList[j])) {
					simWordRecord[i][j] = true;
					simWordRecord[j][i] = true;
				}
			}
		}

		//保留一份记录的备份
		vector<vector<bool>> recordBackup(simWordRecord.begin(), simWordRecord.end());
		//采用广度优先遍历的方式，寻找最短路径的长度
		int pathLength = BFS(n - 1, endWordIndex, simWordRecord);
		DFS(n - 1, endWordIndex, 1, pathLength, recordBackup, wordList);

		return resVec;
	}
};

int main() {
	string beginWord = "cet";
	string endWord = "ism";
	vector<string> wordList{
		"kid","tag","pup","ail","tun","woo","erg","luz","brr",
		"gay","sip","kay","per","val","mes","ohs","now","boa",
		"cet","pal","bar","die","war","hay","eco","pub","lob",
		"rue","fry","lit","rex","jan","cot","bid","ali","pay",
		"col","gum","ger","row","won","dan","rum","fad","tut",
		"sag","yip","sui","ark","has","zip","fez","own","ump",
		"dis","ads","max","jaw","out","btu","ana","gap","cry",
		"led","abe","box","ore","pig","fie","toy","fat","cal",
		"lie","noh","sew","ono","tam","flu","mgm","ply","awe",
		"pry","tit","tie","yet","too","tax","jim","san","pan",
		"map","ski","ova","wed","non","wac","nut","why","bye",
		"lye","oct","old","fin","feb","chi","sap","owl","log",
		"tod","dot","bow","fob","for","joe","ivy","fan","age",
		"fax","hip","jib","mel","hus","sob","ifs","tab","ara",
		"dab","jag","jar","arm","lot","tom","sax","tex","yum",
		"pei","wen","wry","ire","irk","far","mew","wit","doe",
		"gas","rte","ian","pot","ask","wag","hag","amy","nag",
		"ron","soy","gin","don","tug","fay","vic","boo","nam",
		"ave","buy","sop","but","orb","fen","paw","his","sub",
		"bob","yea","oft","inn","rod","yam","pew","web","hod",
		"hun","gyp","wei","wis","rob","gad","pie","mon","dog",
		"bib","rub","ere","dig","era","cat","fox","bee","mod",
		"day","apr","vie","nev","jam","pam","new","aye","ani",
		"and","ibm","yap","can","pyx","tar","kin","fog","hum",
		"pip","cup","dye","lyx","jog","nun","par","wan","fey",
		"bus","oak","bad","ats","set","qom","vat","eat","pus",
		"rev","axe","ion","six","ila","lao","mom","mas","pro",
		"few","opt","poe","art","ash","oar","cap","lop","may",
		"shy","rid","bat","sum","rim","fee","bmw","sky","maj",
		"hue","thy","ava","rap","den","fla","auk","cox","ibo",
		"hey","saw","vim","sec","ltd","you","its","tat","dew",
		"eva","tog","ram","let","see","zit","maw","nix","ate",
		"gig","rep","owe","ind","hog","eve","sam","zoo","any",
		"dow","cod","bed","vet","ham","sis","hex","via","fir",
		"nod","mao","aug","mum","hoe","bah","hal","keg","hew",
		"zed","tow","gog","ass","dem","who","bet","gos","son",
		"ear","spy","kit","boy","due","sen","oaf","mix","hep",
		"fur","ada","bin","nil","mia","ewe","hit","fix","sad",
		"rib","eye","hop","haw","wax","mid","tad","ken","wad",
		"rye","pap","bog","gut","ito","woe","our","ado","sin",
		"mad","ray","hon","roy","dip","hen","iva","lug","asp",
		"hui","yak","bay","poi","yep","bun","try","lad","elm",
		"nat","wyo","gym","dug","toe","dee","wig","sly","rip",
		"geo","cog","pas","zen","odd","nan","lay","pod","fit",
		"hem","joy","bum","rio","yon","dec","leg","put","sue",
		"dim","pet","yaw","nub","bit","bur","sid","sun","oil",
		"red","doc","moe","caw","eel","dix","cub","end","gem",
		"off","yew","hug","pop","tub","sgt","lid","pun","ton",
		"sol","din","yup","jab","pea","bug","gag","mil","jig",
		"hub","low","did","tin","get","gte","sox","lei","mig",
		"fig","lon","use","ban","flo","nov","jut","bag","mir",
		"sty","lap","two","ins","con","ant","net","tux","ode",
		"stu","mug","cad","nap","gun","fop","tot","sow","sal",
		"sic","ted","wot","del","imp","cob","way","ann","tan",
		"mci","job","wet","ism","err","him","all","pad","hah",
		"hie","aim","ike","jed","ego","mac","baa","min","com",
		"ill","was","cab","ago","ina","big","ilk","gal","tap",
		"duh","ola","ran","lab","top","gob","hot","ora","tia",
		"kip","han","met","hut","she","sac","fed","goo","tee",
		"ell","not","act","gil","rut","ala","ape","rig","cid",
		"god","duo","lin","aid","gel","awl","lag","elf","liz",
		"ref","aha","fib","oho","tho","her","nor","ace","adz",
		"fun","ned","coo","win","tao","coy","van","man","pit",
		"guy","foe","hid","mai","sup","jay","hob","mow","jot",
		"are","pol","arc","lax","aft","alb","len","air","pug",
		"pox","vow","got","meg","zoe","amp","ale","bud","gee",
		"pin","dun","pat","ten","mob"
	};

	clock_t startTime = clock();
	vector<vector<string>> resVec = Solution().findLadders(beginWord, endWord, wordList);
	clock_t endTime = clock();

	for (int i = 0; i < resVec.size(); i++) {
		for (int j = 0; j < resVec[i].size() - 1; j++)
			cout << resVec[i][j] << "->";
		cout << resVec[i][resVec[i].size() - 1] << endl;
	}

	cout << "算法使用时间为" << double(endTime - startTime) / CLOCKS_PER_SEC * 1000 << " ms" << endl;

	system("pause");
	return 0;
}