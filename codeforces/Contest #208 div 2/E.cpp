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

const int next[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
const int MAXN = 1010;

int n, m, a[MAXN][MAXN], node[MAXN][MAXN], vis[MAXN][MAXN], deg[MAXN][MAXN];
vector<pair<pii,int> > adj[MAXN][MAXN];
vector<pii> nodes;

void dfs(int i, int j){
	vis[i][j] = 1;
	FORIT(it,adj[i][j]){
		if (!vis[(it->A).A][(it->A).B]) dfs((it->A).A,(it->A).B);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
	//find nodes
	FOR(i,1,n) FOR(j,1,m){
		if (!a[i][j]) continue;
		int vert = a[i-1][j] + a[i+1][j];
		int hori = a[i][j-1] + a[i][j+1];
		deg[i][j] = vert + hori;
		if (deg[i][j] == 2 && (vert == 0 || hori == 0)) continue;
		node[i][j] = 1;
		nodes.PB(MP(i,j));
	}
	//find deg
	int odd = 0;
	FORIT(it,nodes){
		int i = it->A, j = it->B;
		if (deg[i][j] % 2 == 1) odd++;
	}
	if (odd > 2){
		puts("-1"); return 0;
	}
	//connect
	FORIT(it,nodes){
		int i = it->A, j = it->B;
		//to four directions
		REP(d,4){
			if (!a[i+next[d][0]][j+next[d][1]]) continue;
			int r = i + next[d][0], c = next[d][1] + j, dist = 1;
			while (!node[r][c]) {
				r += next[d][0];
				c += next[d][1];
				dist++;
			}
			adj[i][j].PB(MP(MP(r,c),dist));
		}
	}
	//seek for connectivity
	dfs(nodes[0].A,nodes[0].B);
	FORIT(it,nodes){
		int i = it->A, j = it->B;
		if (!vis[i][j]){
			puts("-1"); return 0;
		}
	}
	//find answer
	int ans = 0;
	FORIT(it,nodes){
		int i = it->A, j = it->B;
		FORIT(ii,adj[i][j]){
			ans = __gcd(ans,ii->B);
		}
	}
	if (ans == 1 || ans == 0){
		puts("-1"); return 0;
	}
	FOR(i,2,ans) if (ans % i == 0) printf("%d ",i);
	puts("");
	return 0;
}
