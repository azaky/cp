#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <limits>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

struct node {
	vector<int> item;
	int child[4];
} trie[1000100];
int nnode, n;

char temp[1000100];

int vans = 0;
vector<pii> ans;

void dfs(int v, int p, int depth) {
	if (v == -1) return;
	
	REP(i, 4) {
		dfs(trie[v].child[i], v, depth + 1);
	}
	
	REP(i, SZ(trie[v].item)) {
		if (i == SZ(trie[v].item) - 1) {
			if (p != -1) {
				trie[p].item.PB(trie[v].item[i]);
			}
		}
		else {
			ans.PB(MP(trie[v].item[i], trie[v].item[i+1]));
			vans += depth;
			i++;
		}
	}
}

int main(){
	// initiate trie
	RESET(trie[0].child, -1);
	nnode = 1;
	
	// read inputs and insert them into trie
	scanf("%d", &n);
	REP(i, n) {
		scanf("%s", temp);
		int v = 0;
		int len = strlen(temp);
		REP(j, len) {
			int x = -1;
			switch (temp[j]) {
				case 'A': x = 0; break;
				case 'C': x = 1; break;
				case 'G': x = 2; break;
				case 'T': x = 3; break;
				default: assert(false);
			}
			if (trie[v].child[x] == -1) {
				trie[v].child[x] = nnode;
				RESET(trie[nnode].child, -1);
				nnode ++;
			}
			v = trie[v].child[x];
		}
		trie[v].item.PB(i+1);
	}
	
	// calculate answer
	dfs(0, -1, 0);
	
	// print answer
	printf("%d\n", vans);
	FORIT(it, ans) {
		printf("%d %d\n", it->A, it->B);
	}
	
	return 0;
}
