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
	#define GetTime()	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back
#define LLD "%I64d"

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

/* -------------- end of azaky's template -------------- */

#define EPS 1e-7
#define INF 1000000000
#define MAXN 444

struct circle{
	double x, y, r;
};
double circle_distance(circle a, circle b){
	double ret = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)) - a.r - b.r;
	return ret < 0. ? 0. : ret;
}

int n, k, ntc, p[MAXN], v[MAXN];
double d[MAXN][MAXN];
circle c[MAXN];
vector<int> adj[MAXN];

int jalan(double m){
	//build graph
	REP(i,n){
		adj[i].clear();
		p[i] = i ? INF : 0;
		v[i] = 0;
	}
	REP(i,n) REP(j,n) if (i!=j && d[i][j] < m + EPS) adj[i].PB(j);
	while(true){
		int now = -1;
		REP(i,n) if (!v[i] && p[i] != INF){
			if (now == -1) now = i;
			else if (p[i] < p[now]) now = i;
		}
		if (now == -1) break;
		v[now] = 1;
		FORIT(it,adj[now]) MN(p[*it],p[now]+1);
	}
	return p[n-1];
}

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d%d",&n,&k);
		REP(i,n) scanf("%lf%lf%lf",&c[i].x,&c[i].y,&c[i].r);
		REP(i,n) REP(j,n) d[i][j] = circle_distance(c[i],c[j]);
		double l = 0., r = d[0][n-1];
		while (r-l > EPS){
//			printf("L = %.5lf, R = %.5lf\n",l,r);
			double m = (l+r)/2.;
			if (jalan(m) <= k) r = m; else l = m;
		}
//		assert(jalan(r) <= k);
		printf("%.2lf\n",r);
	}
	
	return 0;
}
