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
#include <limits>
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
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

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

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define MAXN 1000100
int n, a, b, c, primitive[MAXN], involved[MAXN], occ[MAXN];

int main(){
	/* precompute */
	n = 1000000;
	FOR(i,1,n) occ[i] = MAXN;
	FOR(i,1,1000) FOR(j,i+1,1000){
		a = j*j - i*i;
		b = 2 * i * j;
		c = i*i + j*j;
		if (c > n) break;
		if ((__gcd(__gcd(a,b),c)) == 1){
			primitive[c] ++;
			MN(occ[a],c);
			MN(occ[b],c);
			MN(occ[c],c);
		}
	}
	FOR(i,1,n) primitive[i] += primitive[i-1];
	FOR(i,1,n){
		if (occ[i] == MAXN) continue;
		for (int j = 1; i*j <= n; ++j){
			MN(occ[i*j],j*occ[i]);
		}
	}
	FOR(i,1,n) if (occ[i] != MAXN) involved[occ[i]]++;
	FOR(i,1,n) involved[i] += involved[i-1];
	while (cin >> n) printf("%d %d\n",primitive[n],n-involved[n]);
	
	return 0;
}
