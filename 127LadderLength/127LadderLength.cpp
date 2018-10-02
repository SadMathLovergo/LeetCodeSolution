#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <ctime>
using namespace std;

class Solution {
private:
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
	//采用广度优先遍历的方法寻找最短路径
	int BFS(int startIndex, int endIndex, vector<vector<bool>>& simWordRecord) {
		queue<pair<int, int>> pathMemory;//(位置，当前步数)
		pathMemory.push(make_pair(startIndex, 1));

		while (!pathMemory.empty()) {
			int curIndex = pathMemory.front().first;
			int curLength = pathMemory.front().second;
			pathMemory.pop();
			for (int i = 0; i < simWordRecord.size(); i++)
				if (simWordRecord[curIndex][i]) {
					if (i == endIndex)
						return curLength + 1;
					pathMemory.push(make_pair(i, curLength + 1));
					simWordRecord[curIndex][i] = false;
					simWordRecord[i][curIndex] = false;
				}
		}

		return 0;
	}

public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (wordList.empty())
			return 0;

		//判断wordList中是否有endWord，并找出endWord的索引
		int endWordIndex = -1;
		for (int i = 0; i < wordList.size(); i++)
			if (endWord == wordList[i]) {
				endWordIndex = i;
				break;
			}
		if (endWordIndex == -1)
			return 0;

		//将beginWord压入wordList中
		wordList.push_back(beginWord);
		int n = wordList.size();
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
		//采用广度优先遍历的方式，寻找最短路径
		return BFS(n - 1, endWordIndex, simWordRecord);
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
	int res = Solution().ladderLength(beginWord, endWord, wordList);
	clock_t endTime = clock();

	cout << res << endl;
	cout << "算法使用时间为" << double(endTime - startTime) / CLOCKS_PER_SEC * 1000 << " ms" << endl;

	system("pause");
	return 0;
}