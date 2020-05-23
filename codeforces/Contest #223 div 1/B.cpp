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

#define MAXN 7777
#define MAXX 200200
int n, m, q, size[7777], p[MAXX];
pair<int, pair<int,pii> > s[MAXN];

int calcr (int level, int v) {
	FOR(i,level+1,n) v += p[v];
	return v;
}

pii calc (int level, int v) {
	return MP(calcr(level,v-1)+1,calcr(level,v));
}

int main(){
	scanf("%d%d",&n,&m);
	
	//poweroftwo
	p[1] = 1;
	FOR(i,2,200000) {
		p[i] = p[i-1];
		if ((i & -i) == i) p[i]++;
	}
	
	//calculates base
	size[1] = 1;
	FOR(i,2,n) {
		size[i] = size[i-1] + p[size[i-1]];
	}
	
	//!
	q = 0;
	REP(i,m) {
		int tipe, l, r, x, t, v;
		scanf("%d",&tipe);
		if (tipe == 1) {
			scanf("%d%d%d%d",&t,&l,&r,&x);
			l = calc(t,l).A;
			r = calc(t,r).B;
			s[q++] = MP(x,MP(t,MP(l,r)));
			//printf("[%d..%d]\n",l,r);
		}
		else {
			scanf("%d%d",&t,&v);
			pii haha = calc(t,v);
			l = haha.A;
			r = haha.B;
			//printf("[%d..%d]\n",l,r);
			
			set<int> ans;
			REP(j,q) {
				if (s[j].B.B.B < l || r < s[j].B.B.A) continue;
				if (s[j].B.A < t) continue;
				ans.insert(s[j].A);
			}
			printf("%d\n",SZ(ans));
		}
	}
	
	return 0;
}
