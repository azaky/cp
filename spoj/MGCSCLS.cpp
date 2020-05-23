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
#define REPD(i,n) for (int i = n-i; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) (s.find(a) != s.end())

/* -------------- end of azaky's template -------------- */

#define INF 1000000
#define LIM 62500
#define MAXK 27
#define MAXN 51

int n,l,p,ans;
vector<int> LHS(2*LIM+5), RHS(2*LIM+5);
int can[MAXK][2*LIM+5], w[MAXK][MAXN];

void calc(int mode){
	int k;
	if (mode == 1) k = l; else k = p;
	FOR(i,1,k) FORD(j,n,1) scanf("%d",&w[i][j]);
	FOR(i,-LIM,LIM) can[k+1][i+LIM] = i == 0 ? k*n : INF;
	FORD(i,k,1){
		FOR(j,-LIM,LIM) can[i][j+LIM] = INF;
		int total = 0;
		FOR(j,1,n) total += w[i][j];
		FOR(j,0,n){
			total -= w[i][j];
			FOR(p,-LIM,LIM) if (can[i+1][p+LIM] != INF) can[i][p+total+LIM] = min(can[i][p+total+LIM],can[i+1][p+LIM]-n+j);
		}
	}
	if (mode == 1){
		FOR(i,-LIM,LIM) LHS[i+LIM] = INF;
		FOR(i,1,k) FOR(j,-LIM,LIM) LHS[j+LIM] = min(LHS[j+LIM],can[i][j+LIM]);
		LHS[LIM] = min(LHS[LIM],k*n);
	}
	else{
		FOR(i,-LIM,LIM) RHS[i+LIM] = INF;
		FOR(i,1,k) FOR(j,-LIM,LIM) RHS[j+LIM] = min(RHS[j+LIM],can[i][j+LIM]);
		RHS[LIM] = min(RHS[LIM],k*n);
	}
	/*
	printf("========\n");
	FOR(i,-LIM,LIM) if (t[i+LIM] != INF) printf("%d %d\n",i,t[i+LIM]);
	printf("========\n");
	*/
}

int main(){
	scanf("%d%d%d",&n,&l,&p);
	calc(1);
	calc(2);
	ans = INF;
	FOR (i,-LIM,LIM) if (LHS[i+LIM]+RHS[i+LIM] < ans) ans = LHS[i+LIM]+RHS[i+LIM];
	printf("%d\n",ans);
	return 0;
}
