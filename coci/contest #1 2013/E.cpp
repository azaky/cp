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
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
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

#define MAXP 2000200
int next[MAXP], np, p[100], k[100], n, c[MAXP];

void findfactors(int _np, int _f){
	if (_np == np){
		c[_f] ++;
	}
	else {
		FOR(i,0,k[_np]){
			findfactors(_np+1,_f);
			_f *= p[_np];
		}
	}
}

int main(){
	//sieve
	REP(i,MAXP) next[i] = i;
	for (int i = 2; i*i < MAXP; ++i){
		if (next[i] == i){
			for (int j = i*i; j < MAXP; j += i){
				next[j] = i;
			}
		}
	}
	
	scanf("%d",&n);
	REP(i,n){
		int x;
		scanf("%d",&x);
		np = 0;
		while (x != 1){
			p[np] = next[x]; k[np] = 0;
			while (x % p[np] == 0){
				k[np]++;
				x /= p[np];
			}
			np++;
		}
		findfactors(0,1);
	}
	
	ll ans = 0;
	FOR(i,1,2000000){
		if (c[i] > 1){
			MX(ans,(ll)i*c[i]);
		}
	}
	cout << ans << endl;
	GetTime();
	
	return 0;
}
