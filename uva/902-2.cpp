#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
	#define GetTime int time_void = clock(); printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

inline int StringToInt(string s){
	int x;
	stringstream(s) >> x;
	return x;
}
inline string IntToString(int x){
	stringstream s;
	s << x;
	return s.str();
}

/* -------------- end of azaky's template -------------- */

struct _trie{
	//char ch;
	int occ;
	int child[30];
};

vector <_trie> trie;
_trie init;

string line,s,ans,temp;
int len, now, nans, n, k, size;

int main(){
	init.occ = 0;
	for (int i=0; i<26; ++i) init.child[i] = -1;
	while (1){
		getline(cin,line);
		if (line.length()==0) break;
		k = n = 0;
		while (line[k] < '0' || line[k] > '9') ++k;
		while ('0' <= line[k] && line[k] <= '9'){
			n = 10*n + (int)line[k] - 48;
			++k;
		}
		s = ""; len = 0;
		while (line[k] == ' ') ++k;
		while ('a' <= line[k] && line[k] <= 'z'){
			s += line[k++]; ++len;
		}
		while (!trie.empty()) trie.pop_back();
		trie.push_back(init);
		//size = 1;
		nans = 0;
		for (int i=len-n; i >= 0; --i){
		//for (int i=0; i+n <= len; ++i){
			now = 0; temp = "";
			for (int j=0; j<n; ++j){
				temp += s[i+j];
				k = (int)s[i+j] - (int)'a';
				if (trie[now].child[k] < 0){
					trie.push_back(init);
					//trie[size].ch = s[i+j];
					trie[now].child[k] = (int)trie.size()-1;
				}
				now = trie[now].child[k];
				++trie[now].occ;
				debug("TRIE[%d]:%c %d\n",now,s[i+j],trie[now].occ);
			}
			debug("SUBSTRING %s\n",temp.c_str());
			if (trie[now].occ >= nans){
				nans = trie[now].occ;
				ans = temp;
			}
		}
		printf("%s\n",ans.c_str());
	}
	return 0;
}
