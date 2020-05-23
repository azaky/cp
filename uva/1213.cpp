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

#define MAXP 1120
int p[MAXP+10], dp[MAXP+10][20][200], v[MAXP+10][20][200];

int calc(int n, int k, int np){
	if (n < 0 || k < 0) return 0;
	if (v[n][k][np]) return dp[n][k][np];
	v[n][k][np] = 1;
	if (n == 0) return dp[n][k][np] = (k == 0) ? 1 : 0;
	if (k == 0) return dp[n][k][np] = (n == 0) ? 1 : 0;
	if (np == 0) return dp[n][k][np] = 0;
	return dp[n][k][np] = calc(n,k,np-1)+calc(n-p[np],k-1,np-1);
}

int main(){
	int IsPrime[MAXP+10];
	RESET(IsPrime,1);
	IsPrime[1] = 0;
	for (int i = 2; i*i <= MAXP; ++i){
		if (IsPrime[i]){
			for (int j = 2; i*j <= MAXP; ++j){
				IsPrime[i*j] = false;
			}
		}
	}
	int np = 0;
	FOR(i,1,MAXP) if (IsPrime[i]) p[++np] = i;
	
	int n, k;
	while (scanf("%d%d",&n,&k) == 2){
		if (n == 0 && k == 0) return 0;
		printf("%d\n",calc(n,k,np));
	}
	
	return 0;
}
