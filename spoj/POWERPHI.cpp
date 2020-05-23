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

const db phi = (1. + sqrt(5))/2.;

#define MOD 1000000007LL

struct matrix{
	ll a[2][2];
};
matrix product(matrix a, matrix b){
	matrix res;
	REP(i,2) REP(j,2) res.a[i][j] = 0;
	REP(k,2) REP(i,2) REP(j,2) res.a[i][j] = (res.a[i][j] + a.a[i][k]*b.a[k][j])%MOD;
	return res;
}
matrix power(matrix x, ll n){
	if (n == 1) return x;
	matrix res = power(x,n/2);
	res = product(res,res);
	if (n%2) res = product(res,x);
	return res;
}

ll fibo(ll n, ll f0, ll f1){
	if (n == 0) return f0;
	if (n == 1) return f1;
	matrix h;
	h.a[0][0] = 1; h.a[0][1] = 1;
	h.a[1][0] = 1; h.a[1][1] = 0;
	h = power(h,n);
	return (h.a[1][0]*f1 + h.a[1][1]*f0)%MOD;
}

int main(){
	int ntc, n;
	
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d",&n);
		if (n == 0) puts("1");
		else if (n == 1) puts("2");
		else printf("%I64d\n",fibo((int)n,2,1));
	}
	
	return 0;
}
