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

#define MAXN 200200

int n, m, p, q, c;
vector<int> adj[MAXN];
int path[MAXN << 1], visited[MAXN << 1];

int hubahuba = 0;
map<pii, int> huba;
pii revcodes[MAXN << 1];

int code(pii x) {
	if (huba.count(x)) {
		return huba[x];
	} else {
		revcodes[hubahuba] = x;
		return huba[x] = hubahuba++;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	REP(i, m) {
		scanf("%d%d%d", &p, &q, &c);
		adj[p].PB(code(MP(q, c)));
		adj[q].PB(code(MP(p, c)));
	}

	deque<int> dq;
	FORIT(it, adj[1]) {
		path[*it] = 1;
		dq.push_back(*it);
	}

	int ans = -1;
	while (!dq.empty()) {
		int top = dq.front(); dq.pop_front();
		int cost = path[top];
		int v = revcodes[top].A, x = revcodes[top].B;
		if (v == n) {
			ans = cost;
			break;
		}
		if (visited[top]) {
			continue;
		}
		visited[top] = 1;
		FORIT(it, adj[v]) {
			int dest = revcodes[*it].B;
			if (x == dest) {
				if (path[*it] == 0 || cost < path[*it]) {
					path[*it] = cost;
					dq.push_front(*it);
				}
			} else {
				if (path[*it] == 0 || cost + 1 < path[*it]) {
					path[*it] = cost + 1;
					dq.push_back(*it);
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
