#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
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

vector<pii> normalize(vector<int> a){
	sort(ALL(a));
	vector<pii> ans;
	ans.clear();
	int cot = 0, lastid = -1;
	REP(i,SZ(a)){
		if (a[i] == lastid) cot++;
		else {
			if (cot) ans.PB(MP(lastid,cot));
			cot = 1;
			lastid = a[i];
		}
	}
	if (cot) ans.PB(MP(lastid,cot));
	return ans;
}

#define INF 1000000000
#define LIM 314000000
#define MAXN 200200

int n, m;
int vis1[MAXN], vis2[MAXN], vis3[MAXN], dp2[MAXN], dp3[MAXN];
bool dp1[MAXN];
vector<vector<pii> > split[MAXN];
vector<int> hehe;

bool dfs1(int v){
	if (vis1[v]) return dp1[v] = false;
	vis1[v] = 1;
	bool ret = false;
	REP(i,SZ(split[v])){
		bool term = true;
		REP(j,SZ(split[v][i])){
			if (split[v][i][j].A != -2) term = (term && dfs1(split[v][i][j].A));
		}
		ret = (ret || term);
	}
	return dp1[v] = ret;
}

int dfs2(int v){
	if (vis2[v]) return dp2[v] = INF;
	vis2[v] = 1;
	int diamond = 0;
	REP(i,SZ(split[v])){
		int now = 0;
		REP(j,SZ(split[v][i])){
			if (split[v][i][j].A == -2) now += split[v][i][j].B;
			else {
				int haha = dfs2(split[v][i][j].A);
				if (haha == INF) now = INF;
				else now = (int)min((ll)LIM,(ll)now+(ll)split[v][i][j].B*haha);
			}
		}
		diamond = max(now,diamond);
	}
	return dp2[v] = diamond;
}

int dfs3(int v){
	if (vis3[v]) return dp3[v] = INF;
	vis3[v] = 1;
	int diamond = 0;
	REP(i,SZ(split[v])){
		int now = 0;
		REP(j,SZ(split[v][i])){
			if (split[v][i][j].A == -2) now += split[v][i][j].B;
			else {
				int haha = dfs3(split[v][i][j].A);
				if (haha == INF) now = INF;
				else now = (int)min((ll)LIM,(ll)now+(ll)split[v][i][j].B*haha);
			}
		}
		if (diamond == 0) diamond = now; else diamond = min(diamond,now);
	}
	return dp3[v] = diamond;
}
	
int main(){
	scanf("%d%d",&m,&n);
	REP(i,m){
		int _id, _l, hoho;
		scanf("%d%d",&_id,&_l);
		--_id;
		hehe.clear();
		REP(j,_l){
			scanf("%d",&hoho);
			--hoho;
			hehe.PB(hoho);
		}
		split[_id].PB(normalize(hehe));
	}
	REP(i,n) if (!vis1[i]) dfs1(i);
//	REP(i,n) printf("IsTerminated[%d] = %d\n",i+1,dp1[i]);
	REP(i,n) if (!vis2[i]) dfs2(i);
	REP(i,n) if (!vis3[i]) dfs3(i);
	REP(i,n){
		if (!dp1[i]) puts("-1 -1");
		else printf("%d %d\n",dp3[i],dp2[i] == INF ? -2 : dp2[i]);
	}
	
	return 0;
}
