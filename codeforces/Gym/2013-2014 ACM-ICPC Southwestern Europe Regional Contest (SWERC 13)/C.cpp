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

struct place {
	db floor;
	db x, y;
};

db sqr(db a) {return a*a;}
db jarak (place &A, place &B) {
	return sqrt(25. * sqr(A.floor-B.floor) + sqr(A.x-B.x) + sqr(A.y-B.y));
}

#define MAXN 1100

place p[MAXN];
int n, m, q, a, b, prev[MAXN];
db d[MAXN];
vector<pair<int, db> > adj[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	REP(i, n) {
		scanf("%lf%lf%lf", &p[i].floor, &p[i].x, &p[i].y);
	}
	REP(i, m) {
		int x, y;
		char temp[20];
		scanf("%d%d%s", &x, &y, temp);
		if (strcmp(temp, "walking") == 0 || strcmp(temp, "stairs") == 0) {
			adj[x].PB(MP(y, jarak(p[x], p[y])));
			adj[y].PB(MP(x, jarak(p[x], p[y])));
		}
		else if (strcmp(temp, "lift") == 0) {
			adj[x].PB(MP(y, 1.));
			adj[y].PB(MP(x, 1.));
		}
		else if (strcmp(temp, "escalator") == 0) {
			adj[x].PB(MP(y, 1.));
			adj[y].PB(MP(x, jarak(p[x], p[y]) * 3.));
		}
		else assert(false);
	}
	scanf("%d", &q);
	FOR(itc, 1, q) {
		scanf("%d%d", &a, &b);
		priority_queue<pair<db, int> > pq;
		pq.push(MP(0., a));
		REP(i, n) {
			d[i] = 1e100;
		}
		d[a] = 0.;
		while (!pq.empty()) {
			int v = pq.top().B;
			db di = -pq.top().A;
			pq.pop();
			if (v == b) break;
			
			FORIT(it, adj[v]) {
				if (d[it->A] > di + it->B) {
					d[it->A] = di + it->B;
					prev[it->A] = v;
					pq.push(MP(-d[it->A], it->A));
				}
			}
		}
		vector<int> path;
		int v = b;
		path.PB(v);
		while (v != a) {
			v = prev[v];
			path.PB(v);
		}
		reverse(ALL(path));
		FORIT(it, path) {
			if (it != path.begin()) printf(" ");
			printf("%d", *it);
		}
		printf("\n");
	}
	
	return 0;
}
