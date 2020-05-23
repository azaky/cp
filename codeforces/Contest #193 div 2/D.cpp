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

ll n, k, x, adj[2020][2020], c[2020][2020];

ll com(ll n, ll k){
	//return c[n-k][k]
	if (n < k || k < 0) return 0;
	if (n == k || k == 0) return 1;
	if (c[n-k][k] != 0) return c[n-k][k];
	return c[n-k][k] = com(n-1,k) + com(n-1,k-1);
}

int main(){
	cin >> n >> k;
	REP(i,n-1) FOR(j,i+1,n-1){
		scanf("%I64d",&adj[i][j]);
		adj[j][i] = adj[i][j];
	}
	REP(i,n) adj[i][i] = -1;
	ll tot = 0;
	REP(i,n){
		ll deg = 0, e = 0;
		REP(j,n) if (adj[i][j] != -1){
			deg++;
			e += adj[i][j];
		}
		tot += e * com(deg-1,k-1);
	}
//	cout << tot << endl;
//	cout << com(n,k) << endl;
	cout << tot/com(n,k) << endl;
//	cout << k*(n-k)*e/(n*(n-1LL)) << endl;
	
	return 0;
}
