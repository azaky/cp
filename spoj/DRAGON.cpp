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

const int MAXN = 333;
const int INF = 1000000000;
int n,m,k,L[MAXN],R[MAXN],cost[MAXN],visit[MAXN][MAXN][2][2],dp[MAXN][MAXN][2][2],adj[MAXN][MAXN];
int cot,sizeL[MAXN],sizeR[MAXN],size[MAXN];

void build(int v, int par, int w){
	cost[v] = w;
	int size = 0;
	FOR(i,1,n) if (adj[v][i] == -1) ++size;
	if (size == 1) return;
	int now = -1;
	FOR(i,1,n){
		if (adj[v][i] == -1 || i == par) continue;
		if (now == -1) L[v] = now = i;
		else R[now] = i, now = i;
		build(i,v,adj[v][i]);
	}
}
int calc(int v, int k, int par, int self){
	if (v == 0) return k?INF:0;
	if (visit[v][k][par][self]) return dp[v][k][par][self]; visit[v][k][par][self] = 1;
	int &ret = dp[v][k][par][self];
	ret = INF;
	for(int l=0,r=k-self;l<=k-self;++l,--r){
		if (size[L[v]] < l || size[R[v]] < r) continue;
		ret = min(ret,min(calc(L[v],l,self,0),calc(L[v],l,self,1))+min(calc(R[v],r,par,0),calc(R[v],r,par,1)));
	}
	ret = ret + (((m==2)?!(par^self):(par&self))?cost[v]:0);
	return ret;
}
void jalan(int v){
	int temp = cot;
	++cot;
	if (L[v] != 0) jalan(L[v]);
	if (R[v] != 0) jalan(R[v]);
	size[v] = cot-temp;
}

int main(){
	int ntc = 10;
	FOR(itc,1,ntc){
		scanf("%d%d%d",&n,&m,&k);
		RESET(adj,-1);
		FOR(i,1,n-1){
			int a,b,w;
			scanf("%d%d%d",&a,&b,&w);
			adj[a][b] = adj[b][a] = w;
		}
		if (k + (m-1) > n){
			puts("-1"); continue;
		}
		//forming LC-RS Tree
		FOR(i,1,n) L[i] = R[i] = 0;
		build(1,0,0);
		cot = 0;
		jalan(1);
		//hehe
		RESET(visit,0);
		printf("%d\n",calc(1,k,0,1));
	}
	
	return 0;
}
