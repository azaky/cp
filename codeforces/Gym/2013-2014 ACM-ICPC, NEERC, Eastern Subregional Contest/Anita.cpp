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
int nl, nr, nc;
pii pl[MAXN], pr[MAXN], pc[MAXN];
set<int> pos;
map<int, vector<int> > cam;

int main(){
	scanf("%d", &nl);
	REP(i, nl) {
		scanf("%d%d", &pl[i].A, &pl[i].B);
		pos.insert(pl[i].B);
	}
	scanf("%d", &nr);
	REP(i, nr) {
		scanf("%d%d", &pr[i].A, &pr[i].B);
		pos.insert(pr[i].B);
	}
	scanf("%d", &nc);
	REP(i, nc) {
		scanf("%d%d", &pc[i].A, &pc[i].B);
		if (pc[i].B >= pl[0].B && pc[i].B <= pl[nl-1].B) {
			pos.insert(pc[i].B);
		}
		cam[pc[i].B].PB(pc[i].A);
	}
	
	int il = 0, ir = 0;
	db ans = 1e30;
	FORIT(it, pos) {
		int y = *it;
		
		while (pl[il].B < y) il++;
		while (pr[ir].B < y) ir++;
		assert(il < nl && ir < nr);
		
		db xl, xr;
		if (pl[il].B == y) {
			xl = (db)pl[il].A;
		}
		else {
			if (pl[il].B == pl[il-1].B) {
				xl = (db)pl[il].A;
			}
			else {
				xl = (db)pl[il].A + (db)(pl[il].A - pl[il-1].A) * (db)(y - pl[il].B) / (db)(pl[il].B - pl[il-1].B);
			}
		}
		if (pr[ir].B == y) {
			xr = (db)pr[ir].A;
		}
		else {
			if (pr[ir].B == pr[ir-1].B) {
				xr = (db)pr[ir].A;
			}
			else {
				xr = (db)pr[ir].A + (db)(pr[ir].A - pr[ir-1].A) * (db)(y - pr[ir].B) / (db)(pr[ir].B - pr[ir-1].B);
			}
		}
		
		vector<db> p;
		p.PB(xl);
		p.PB(xr);
		vector<int> c = cam[y];
		FORIT(it, c) {
			db _y = (db)*it;
			if (xl < _y && _y < xr) {
				p.PB(_y);
			}
		}
		sort(ALL(p));
		db _ans = 0;
		REP(i, SZ(p)-1) {
			MX(_ans, p[i+1]-p[i]);
		}
		MN(ans, _ans);
	}
	
	printf("%.17lf\n", ans);
	
	return 0;
}
