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

#define MAXK 55
#define MAXN 111

struct fibo {
	ll x, y, xy, yx, xx, yy;
	int start, end;
} f[MAXK];

ll k, x, n, m;

int main(){
	scanf("%I64d%I64d%I64d%I64d",&k,&x,&n,&m);
	
	f[1].x = 1; f[1].start = f[1].end = 1;
	f[2].y = 1; f[2].start = f[2].end = -1;
	
	FOR(i,3,k){
		f[i].x = f[i-2].x + f[i-1].x;
		f[i].y = f[i-2].y + f[i-1].y;
		f[i].start = f[i-2].start;
		f[i].end = f[i-1].end;
		f[i].xy = f[i-2].xy + f[i-1].xy + (f[i-2].end == 1 && f[i-1].start == -1);
		f[i].yx = f[i-2].yx + f[i-1].yx + (f[i-2].end == -1 && f[i-1].start == 1);
		f[i].xx = f[i-2].xx + f[i-1].xx + (f[i-2].end == 1 && f[i-1].start == 1);
		f[i].yy = f[i-2].yy + f[i-1].yy + (f[i-2].end == -1 && f[i-1].start == -1);
		
	}
	
	//printf("x = %I64d, y = %I64d, xy = %I64d, yx = %I64d\n",f[k].x, f[k].y, f[k].xy, f[k].yx);
	
	FOR(f1a,-1,1) FOR(f1b,-1,1) FOR(f2a,-1,1) FOR(f2b,-1,1) {
		if (n == 1 && f1a != f1b) continue;
		if (m == 1 && f2a != f2b) continue;
		ll xy = (f1b == 1 && f2a == -1) ? 1 : 0;
		ll yx = (f2b == 1 && f1a == -1) ? 1 : 0;
		ll xx = (f1b == 1 && f1a == -1) ? 1 : 0;
		ll yy = (f2b == 1 && f2a == -1) ? 1 : 0;
		ll _n = n, _m = m;
		if (f1a) _n--;
		if (f1b && n != 1) _n--;
		if (f2a) _m--;
		if (f2b && m != 1) _m--;
		
		xy *= f[k].xy;
		yx *= f[k].yx;
		xx *= f[k].xx;
		yy *= f[k].yy;
		
		FOR(ac1,0,_n/2) FOR(ac2,0,_m/2) {
			ll _x = ac1 * f[k].x + ac2 * f[k].y + xy + yx + xx + yy;
			if (_x == x){
				//printing f[1]
				switch (f1a){
					case -1: printf("C"); break;
					case 0: break;
					case 1: printf("A"); break;
				}
				REP(i,ac1) printf("AC");
				REP(i,_n - ac1 - ac1) printf("X");
				if (n != 1){
					switch (f1b){
						case -1: printf("C"); break;
						case 0: break;
						case 1: printf("A"); break;
					}
				}
				puts("");
				//printing f[1]
				switch (f2a){
					case -1: printf("C"); break;
					case 0: break;
					case 1: printf("A"); break;
				}
				REP(i,ac2) printf("AC");
				REP(i,_m - ac2 - ac2) printf("X");
				if (m != 1){
					switch (f2b){
						case -1: printf("C"); break;
						case 0: break;
						case 1: printf("A"); break;
					}
				}
				puts("");
				
				//printf("[%d..%d], [%d..%d], %I64d, %I64d\n",f1a,f1b, f2a, f2b, _n, _m);
				
				return 0;
			}
		}
	}
	
	puts("Happy new year!");
	
	return 0;
}
