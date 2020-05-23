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

#define MAXN 50500

int ntc, n, v[MAXN];
ll vg[MAXN], vc[MAXN];
pair<ll, int> g[MAXN], c[MAXN];
vector<int> pg, pc;
ll ans;
pair<vector<int>, vector<int> > nans;
char name[MAXN][10];

void dfs(int ig, int ic, int jg, int jc) {
	if (ig == 3 && ic == 3) {
		ll cur = vg[pg[0]] * vg[pg[1]] * vg[pg[2]] + vc[pc[0]] * vc[pc[1]] * vc[pc[2]];
		if (cur > ans) {
			ans = cur;
			nans = MP(pg, pc);
		}
	} else {
		if (ig < 3) {
			int newjg = jg;
			while (v[g[newjg].B]) {
				newjg++;
			}
			v[g[newjg].B] = 1;
			pg[ig] = g[newjg].B;
			dfs(ig + 1, ic, newjg + 1, jc);
			v[g[newjg].B] = 0;
		}
		if (ic < 3) {
			int newjc = jc;
			while (v[c[newjc].B]) {
				newjc++;
			}
			v[c[newjc].B] = 1;
			pc[ic] = c[newjc].B;
			dfs(ig, ic + 1, jg, newjc + 1);
			v[c[newjc].B] = 0;
		}
	}
}

int main(){
	pg.resize(3); pc.resize(3);
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		REP(i, n) {
			scanf("%s%lld%lld", &name[i], &vg[i], &vc[i]);
			g[i] = MP(vg[i], i);
			c[i] = MP(vc[i], i);
		}
		sort(g, g + n); reverse(g, g + n);
		sort(c, c + n); reverse(c, c + n);

		ans = 0;
		dfs(0, 0, 0, 0);

		printf("%lld\n", ans);
		printf("%s %s %s\n", name[nans.A[0]], name[nans.A[1]], name[nans.A[2]]);
		printf("%s %s %s\n", name[nans.B[0]], name[nans.B[1]], name[nans.B[2]]);
	}
	
	return 0;
}
 	