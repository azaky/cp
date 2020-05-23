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
#define F first
#define S second
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
#define MAXV 10000000

int vis[MAXN], memo[MAXN];
int meml[MAXN], memr[MAXN];

int solve(int n, int a, int b, int c) {
	int ret = MAXV;
	int l, r;
	if (n == 1) return 0;
	if (vis[n]) return memo[n];
	for (int i = 0; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			int tmp = 0;
			if ((i > 0) && (i < n))
				MX(tmp, a + solve(i, a, b, c));
			if ((j-i > 0) && (j-i < n))
				MX(tmp, b + solve(j-i, a, b, c));
			if ((n-j > 0) && (n-j < n))
				MX(tmp, c + solve(n-j, a, b, c));
			if (tmp > 0) {
				if (ret >= tmp) {
					MN(ret, tmp);
					l = i;
					r = j;
				}
			}
		}
	}
	vis[n] = 1; memo[n] = ret;
	meml[n] = l;
	memr[n] = r;
	return ret;
}

int main() {
	int ntc;
	scanf("%d", &ntc);
	for (int i = 0; i < ntc; ++i) {
		int n, a, b, c;
		vector<int> v;
		scanf("%d%d%d%d", &n, &a, &b, &c);
		v.PB(a); v.PB(b); v.PB(c);
		sort(ALL(v));
		a = v[0]; b = v[1]; c = v[2];
		RESET(vis, 0);
		printf("%d\n", solve(n, a, b, c));
		for (int i = 1; i <= n; ++i) 
			printf("%d: (%d, %d) taking %d %d %d for $%d from %d %d %d\n", 
					i, 
					meml[i], memr[i], meml[i], memr[i]-meml[i], i-memr[i],
					memo[i],
					a + memo[meml[i]], b + memo[memr[i]-meml[i]], c + memo[i-memr[i]]);
	}
}