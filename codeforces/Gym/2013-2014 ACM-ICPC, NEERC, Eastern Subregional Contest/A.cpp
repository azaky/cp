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

#define EPS 1e-6

int nl, nr, nc;
pair<double,double> pl[100005], pr[100005], pc[100005];
set<double> pos;

double ans;

int main(){
	scanf("%d", &nl);
	REP(i, nl){
		scanf("%lf %lf", &pl[i].B, &pl[i].A);
		pos.insert(pl[i].A);
	}
	scanf("%d", &nr);
	REP(i, nr){
		scanf("%lf %lf", &pr[i].B, &pr[i].A);
		pos.insert(pr[i].A);
	}
	scanf("%d", &nc);
	REP(i, nc){
		scanf("%lf %lf", &pc[i].B, &pc[i].A);
		if (pl[0].A <= pc[i].A && pc[i].A <= pl[nl-1].A) {
			pos.insert(pc[i].A);
		} 
	}
	sort(pl,pl+nl);
	sort(pr,pr+nr);
	sort(pc,pc+nc);
	
	int il, ir, ic;
	il = ir = ic = 0;
	
	ans = 1e90;
	FORIT(it, pos){
		double y = *it;
		while (il < nl && pl[il].A < y) il++;
		while (ir < nr && pr[ir].A < y) ir++;
		while (ic < nc && pc[ic].A < y) ic++;
		
		double lx, rx;
		
		if (fabs(pl[il].A - y) < EPS){
			lx = pl[il].B;
		} else if (fabs(pl[il].A - pl[il-1].A) < EPS){
			lx = pl[il].B;
		} else {
			double dx = pl[il].B - pl[il-1].B;
			double dy = pl[il].A - pl[il-1].A;
			
			lx = ((dx/dy)* (y - pl[il-1].A)) + pl[il-1].B;
		}
		
		if (fabs(pr[ir].A - y) < EPS){
			rx = pr[ir].B;
		} else if (fabs(pr[ir].A - pr[ir-1].A) < EPS){
			rx = pr[ir].B;
		} else {
			double dx = pr[ir].B - pr[ir-1].B;
			double dy = pr[ir].A - pr[ir-1].A;
			
			rx = ((dx/dy) * (y - pr[ir-1].A)) + pr[ir-1].B;
		}		
		
		vector<double> vx;
		vx.PB(lx);
		while (ic < nc && fabs(pc[ic].A - y) < EPS){
			if (pc[ic].B > rx+EPS) break;
			if (pc[ic].B > vx.back()+EPS) vx.PB(pc[ic].B);
			ic++;
		}
		if (rx > vx.back()+EPS) vx.PB(rx);
		
		double maxwidth = 0.;
		REP(i, SZ(vx)-1){
			MX(maxwidth, vx[i+1]-vx[i]);
		}
		MN(ans,maxwidth);
	}
	
	printf("%.17lf\n", ans);
	
	return 0;
}
