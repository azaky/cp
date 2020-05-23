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

#define MAXN 111111
int low[MAXN], num[MAXN], par[MAXN], bridge[MAXN], dfsNumberCounter;
int lvl[MAXN], idc[MAXN], nc, vis[MAXN];
int n, m;
vector<pii> adj[MAXN];
vector<int> adjc[MAXN];
pii edge[MAXN];

void dfs1(int u){
	low[u] = num[u] = dfsNumberCounter++;
	FORIT(j,adj[u]){
		if (num[j->A] == -1){
			par[j->A] = u;
			dfs1(j->A);
			if (low[j->A] > num[u]){
				bridge[j->B] = 1;
			}
			low[u] = min(low[u],low[j->A]);
		}
		else if (j->A != par[u]){
			low[u] = min(low[u],num[j->A]);
		}
	}
}

void fill(int v){
	if (vis[v]) return;
	vis[v] = 1;
	idc[v] = nc;
	FORIT(i,adj[v]){
		if (!bridge[i->B]){
			fill(i->A);
		}
	}
}

void dfs2(int v, int p, int l){
	lvl[v] = l;
	FORIT(i,adjc[v]){
		if (*i != p){
			dfs2(*i,v,l+1);
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d%d",&n,&m);
	REP(i,m){
		int x, y;
		scanf("%d%d",&x,&y);
		--x; --y;
		adj[x].PB(MP(y,i));
		adj[y].PB(MP(x,i));
		edge[i] = MP(x,y);
	}
	//find bridge
	dfsNumberCounter = 0;
	RESET(num,-1);
	RESET(low,0);
	RESET(par,0);
	REP(i,n){
		if (num[i] == -1){
			dfs1(i);
		}
	}
	//delete multiple edge
	map<pii,int> udah;
	REP(i,m){
		udah[MP(edge[i].A,edge[i].B)] ++;
		udah[MP(edge[i].B,edge[i].A)] ++;
	}
	REP(i,m){
		if (udah[MP(edge[i].A,edge[i].B)] > 1){
			bridge[i] = 0;
		}
	}
//	REP(i,m) if (bridge[i]) printf("[%d,%d]\n",edge[i].A,edge[i].B);
	//find SCC
	RESET(vis,0);
	nc = 0;
	REP(i,n){
		if (!vis[i]){
			fill(i);
			nc++;
		}
	}
	REP(i,m){
		if (bridge[i]){
			int x = idc[edge[i].A], y = idc[edge[i].B];
			adjc[x].PB(y);
			adjc[y].PB(x);
		}
	}
	//find diameter
	dfs2(0,0,-1);
	int ans1 = 0;
	REP(i,nc){
		if (lvl[i] > lvl[ans1]){
			ans1 = i;
		}
	}
	dfs2(ans1,0,-1);
	int ans2 = 0;
	REP(i,nc){
		if (lvl[i] > lvl[ans2]){
			ans2 = i;
		}
	}
	REP(i,n) if (idc[i] == ans1){
		printf("%d ",i+1);
		break;
	}
	REP(i,n) if (idc[i] == ans2){
		printf("%d\n",i+1);
		break;
	}
	
	return 0;
}
