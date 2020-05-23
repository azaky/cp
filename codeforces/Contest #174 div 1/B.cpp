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

#define MAXN 222222
int n, a[MAXN], ith, visit[MAXN][3], end[2*MAXN];
PII pos[MAXN][3];
vector<LL> cycle[2*MAXN];

void fill(int v, int type, int k){
	if (v <= 0 || v > n){
		end[ith] = 0;
		return;
	}
	if (v == 1){
		end[ith] = type;
		return;
	}
	if (visit[v][type]){
		if (pos[v][type].fi == ith) end[ith] = -1;
		else {
			int jth = pos[v][type].fi, kth = pos[v][type].se;
			cycle[ith].pb(cycle[ith].back()+cycle[jth].back()-cycle[jth][kth-1]);
			end[ith] = end[jth];
		}
		return;
	}
	pos[v][type] = mp(ith,k);
	visit[v][type] = 1;
	cycle[ith].pb(cycle[ith].back()+a[v]);
	if (type == 1) fill(v+a[v],2,k+1); else fill(v-a[v],1,k+1);
}


int main(){
	cin >> n;
	FOR(i,2,n) cin >> a[i];
	ith = 0;
	FOR(i,2,n){
		if (!visit[i][1]){
			ith++;
			cycle[ith].pb(0);
			fill(i,1,1);
		}
		if (!visit[i][2]){
			ith++;
			cycle[ith].pb(0);
			fill(i,2,1);
		}
	}
	FOR(i,1,n-1){
		a[1] = i;
		int t = pos[i+1][2].fi, u = pos[i+1][2].se;
		//printf("CYCLE: [%d][%d]\n",u,end[t]);
		//FOR(j,1,(int)cycle[t].size()-1) printf("%I64d ",cycle[t][j]); printf("\n");
		if (end[t] == -1 || end[t] == 1){
			puts("-1"); continue;
		}
		if (end[t] == 0){
			cout << cycle[t].back()-cycle[t][u-1]+i << endl;
			continue;
		}
		if (end[t] == 2){
			cout << cycle[t].back()-cycle[t][u-1]+2*i << endl;
			continue;
		}
	}
	
	return 0;
}
