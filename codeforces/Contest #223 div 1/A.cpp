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

struct stage {
	int tipe;
	ll x, y;
} s[MAXN];

int n, m;
ll len[MAXN], ans[MAXN];

ll solve (ll x, int pos) {
	//printf("x = %I64d, pos = %d\n",x, pos);
	if (s[pos].tipe == 1){
		return s[pos].x;
	}
	else {
		x = x % s[pos].x;
		if (x == 0) x = s[pos].x;
		
		int next = lower_bound(len, len+1+m, x) - len;
		return solve (x - len[next-1], next);
	}
}

int main(){
	scanf("%d",&m);
	FOR(i,1,m) {
		scanf("%d",&s[i].tipe);
		if (s[i].tipe == 1) {
			scanf("%I64d",&s[i].x);
			len[i] = len[i-1] + 1;
		}
		else {
			scanf("%I64d%I64d",&s[i].x,&s[i].y);
			len[i] = len[i-1] + s[i].x * s[i].y;
		}
	}
	
	//FOR(i,1,m) printf("%I64d ",len[i]); printf("\n");
	
	scanf("%d",&n);
	int pos = 1;
	REP(i,n) {
		ll x;
		scanf("%I64d",&x);
		while (len[pos] < x) pos++;
		printf("%I64d",solve(x - len[pos-1], pos));
		if (i < n-1) printf(" "); else printf("\n");
	}
	
	return 0;
}
