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

#define MAXN 111
#define MOD  999983LL

struct Matrix{
	LL N;
	LL M[MAXN][MAXN];
};

Matrix product(Matrix A, Matrix B){
	int N = A.N;
	Matrix ret;
	ret.N = N;
	FOR(i,1,N) FOR(j,1,N) ret.M[i][j] = 0;
	FOR(i,1,N) FOR(j,1,N) FOR(k,1,N) ret.M[i][j] = (ret.M[i][j] + A.M[i][k] * B.M[k][j]) % MOD;
	return ret;
}
Matrix power(Matrix A, int T){
	if (T == 1) return A;
	Matrix ret = power(A,T>>1);
	ret = product(ret,ret);
	if (T&1) ret = product(ret,A);
	return ret;
}

int main(){
	int n, m, t, q, a, b;
	int adj[MAXN][MAXN];
	
	cin >> n >> m >> t >> q;
	
	assert(1 <= m && m <= n*(n-1)/2);
	assert(2 <= n && n <= 100);
	assert(1 <= q && q <= 5000);
	assert(1 <= t && t <= 1000000);
	
	REP(i,m){
		cin >> a >> b;
		assert(1 <= a && a <= n && 1 <= b && b <= n && a != b);
		assert(adj[a][b] == 0);
		adj[a][b] = adj[b][a] = 1;
	}
	Matrix NumPath;
	NumPath.N = n;
	FOR(i,1,n) FOR(j,1,n) NumPath.M[i][j] = (LL)adj[i][j];
	NumPath = power(NumPath,t);
	
	REP(i,q){
		cin >> a >> b;
		cout << NumPath.M[a][b] << endl;
	}
	
	return 0;
}
