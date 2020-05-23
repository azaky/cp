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

#define MAXN 100100
int n, k, trie[MAXN][30], par[MAXN];
vector<int> child[MAXN];
char s[MAXN];

int check(int v) {
	if (SZ(child[v]) == 0) {
		return 2;
	}
	int huba[4];
	REP(i, 4) huba[i] = 0;
	FORIT(it, child[v]) {
		int x = check(*it);
		//printf("huba(%d) = %d\n", *it, x);
		huba[x] = 1;
	}
	if (huba[3] || (huba[0] && huba[2])) {
		return 1;
	}
	if (huba[2]) {
		return 0;
	}
	if (huba[0]) {
		return 2;
	}
	if (huba[1]) {
		return 3;
	}
	assert(false);
}

int main(){
	scanf("%d%d", &n, &k);
	// phase 1
	int nnode = 1;
	RESET(trie, -1);
	RESET(par, -1);
	REP(i, n) {
		scanf("%s", s);
		int l = strlen(s);
		int x = 0;
		REP(j, l) {
			if (trie[x][s[j]-'a'] == -1) {
				child[x].PB(nnode);
				par[nnode] = x;
				trie[x][s[j]-'a'] = nnode++;
			}
			x = trie[x][s[j]-'a'];
		}
	}
	// phase 2
	int huba = check(0);
	// phase 3
	int winner = -1;
	if (huba == 0) {
		if (k % 2 == 0) {
			winner = 2;
		}
		else {
			winner = 1;
		}
	}
	if (huba == 1) {
		winner = 1;
	}
	if (huba == 2) {
		winner = 2;
	}
	if (huba == 3) {
		winner = 2;
	}
	//printf("huba = %d\n", huba);
	if (winner == 1) {
		puts("First");
	}
	else if (winner == 2) {
		puts("Second");
	}
	
	return 0;
}
