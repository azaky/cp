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

#define MAXN 1000000

int n;
int vis[MAXN+5][2], memo[MAXN+5][2];
char s[MAXN+5];

int dp(int v, int change) {
	if (v < 0) return 0;
	if (vis[v][change]) return memo[v][change];
	int ret = 0;
	if (change) {
		if (s[v] == 'B') ret = dp(v-1, change);
		else ret = 1+ min(dp(v-1, change), dp(v-1, !change));
	}
	else {
		if (s[v] == 'A') ret = dp(v-1, change);
		else ret = 1+ min(dp(v-1, change) , dp(v-1, !change));
	}
	vis[v][change] = 1;
	memo[v][change] = ret;
	return ret;
}

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	printf("%d\n", dp(n-1,0));
	
	return 0;
}
