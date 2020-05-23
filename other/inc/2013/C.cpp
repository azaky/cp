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
/** Maximum Flow **/
/* complexity : O(|V|*(|V|+|E|)) */
void augment(int v, int minEdge, int res[][222], int &s, int &f, vector<int> &p){
	if (v == s) { f = minEdge;return; }
	else if (p[v] != -1) { 
		augment(p[v],min(minEdge,res[p[v]][v]),res,s,f,p); res[p[v]][v]-= f; res[v][p[v]] += f; 
	}
}
int maxFlow(int n, int source, int target, int res[][222]) {
	int mf = 0;
#ifndef INF
	const int INF = 1000000000;
#endif
	while (1) {
		int f = 0;
		vector<int> dist(n+5,INF); dist[source] = 0; queue<int> q; q.push(source);
		vector<int> p;
		p.assign(n+5,-1);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == target) break;
			for (int v = 0; v < n; v++)
				if (res[u][v] > 0 && dist[v] == INF)
					dist[v] = dist[u]+ 1, q.push(v), p[v] = u;
		}
		augment(target,INF,res,source,f,p);
		if (f == 0) break;
		mf += f;
	}
	return mf;
}

#define MAXN 222
int ntc, n, s[MAXN], e[MAXN], t[MAXN][MAXN], adj[MAXN][MAXN];

int main(){
	scanf("%d",&ntc);
    FOR(itc,1,ntc){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d%d",&s[i],&e[i]);
        vector<pii> edge;
        RESET(adj,0);
        FOR(i,1,n){
            FOR(j,1,n){
                scanf("%d",&t[i][j]);
                if (e[i]+t[i][j] <= s[j]){
                    adj[i][j+n]++;
                }
            }
        }
        FOR(i,1,n) adj[0][i]++;
        FOR(i,n+1,2*n) adj[i][2*n+1]++;
        printf("Case #%d: %d\n",itc,n-maxFlow(2*n+2,0,2*n+1,adj));
    }
	
	return 0;
}
