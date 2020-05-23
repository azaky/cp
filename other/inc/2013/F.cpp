/* DELAPAN.3gp */
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

/* -------------- end of DELAPAN.3gp's template -------------- */

#define MAXN 200000

int ntc,tc;
int n,k,dp;
int a[MAXN+5], bit[MAXN+5];

int bit_query(int x) {
	int ret = 0;
	for (; x > 0; x-=x&(-x)) {
		ret = max(ret,bit[x]);
	}
	return ret;
}

void bit_update(int x, int c) {
	for (; x <= n; x+=x&(-x)) {
		bit[x] = max(bit[x],c);
	}
}


int main(){
	scanf("%d", &ntc);
	for (int tc = 1; tc <= ntc; tc++) {
		scanf("%d %d", &n, &k);
		set<int> s;
		RESET(bit,0);
		int ans = 0; int ct = 0;
		for (int i = 0; i < n; i++) { scanf("%d", &a[i]); s.insert(a[i]); }
		FORIT(it,s) {
			++ct;
			for (int i = 0; i < n; i++) 
				if (a[i] == *it) a[i] = ct;
		}
		ct = 0;
		for (int i = 0; i < n; i = (i+1)%n) {
			//puts("A");
			if (!i) ++ct;
			//printf("%d %d\n", ct, k);
			if (ct > k) break;
			//puts("OY");
			dp = bit_query(a[i])+1;
			bit_update(a[i],dp);
			//printf("%d\n", dp);
			if (dp == k) { ans = ct; break; }
		}
		printf("Case #%d: %d\n",tc, ans);
		
	}
	
	return 0;
}
