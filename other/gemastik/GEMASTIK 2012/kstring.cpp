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
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	int time_void;
	#define GetTime time_void = clock();\
	printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
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

typedef struct trie *_trie;
struct trie{
	char ch;
	int total;
	_trie child[26];
};

_trie getnew(void){
	static _trie block;
	static int size = 0;
	if (size==0){
		block = (_trie)malloc(sizeof(*block)*128);
		size = 128;
	}
	size--;
	return block++;
}

string s;
char ch;
int n,k;

int main(){
	s = "";
	ch = getchar();
	while (ch != ' '){
		s = s + ch;
		ch = getchar();
	}
	scanf("%d",&k);
	n = s.length();
	//creating new trie
	_trie top = getnew();
	top->child[1] = NULL;
	
	
	

	
	return 0;
}
