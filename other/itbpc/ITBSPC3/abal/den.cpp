#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
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
	#define GetTime	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

//abbreviations
typedef long long LL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LLD "%I64d"

//prefefined macros
#define REP(i,n) for (int i = 0; i < n; ++i)
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

int n, v;
vector<int> adj[1000];
map<PII,bool> con;
map<int,bool> visit;

bool glitch(int v){
	REP(i,(int)adj[v].size()){
		if (adj[v][i] > n) return false;
		if (!con[mp(adj[v][i],v)]) return false;
	}
	return true;
}
void dfs(int v){
	if (visit[v]){puts("Bug!"); exit(0); }
	visit[v] = true;
	REP(i,(int)adj[v].size()) dfs(adj[v][i]);
}

int main(){
	cin >> n;
	FOR(i,1,n){
		while (cin >> v){
			if (v == -1) break;
			assert(1 <= v && v <= n);
			adj[i].pb(v);
			con[mp(i,v)] = true;
		}
	}
	//ngecek glitch
	FOR(i,1,n) if (glitch(i)){
		puts("Glitch!"); return 0;
	}
	//ngecek bug
	FOR(i,1,n){
		visit.clear();
		dfs(i);
	}
	//topo sort
	vector<int> S;
	vector<int> L;
	FOR(i,1,n) if (adj[i].empty()) S.pb(i);
	bool inL[1000];
	
	while (!S.empty()){
		v = S[S.size()-1]; S.pop_back(); L.pb(v); inL[v] = true;
		REP(i,(int)adj[v].size()){
			int u = adj[v][i];
			//if (u > n) continue;
			bool yes = true;
			REP(i,(int)adj[u].size()){
				if (adj[u][i] <= n){
					if (!inL[adj[u][i]]) yes = false;
				}
			}
			if (yes) S.pb(u);
		}
	}
	
	REP(i,(int)L.size()) printf("%d\n",L[i]);
	
	return 0;
}
