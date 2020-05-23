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

int ntc, n;
pii room;
pair<pii,pii> r[111];

int main(){
	scanf("%d",&ntc);
	while (ntc--){
		scanf("%d%d",&room.A,&room.B);
		scanf("%d",&n);
		REP(i,n){
			scanf("%d%d%d%d",&r[i].A.A,&r[i].A.B,&r[i].B.A,&r[i].B.B);
		}
		bool disjoint = true;
		REP(i,n){
			FOR(j,i+1,n-1){
				if (!(r[i].B.A <= r[j].A.A || r[j].B.A <= r[i].A.A || r[i].B.B <= r[j].A.B || r[j].B.B <= r[i].A.B)) disjoint = false;
			}
		}
		if (!disjoint){
			puts("NONDISJOINT");
			continue;
		}
		bool contained = true;
		REP(i,n){
			if (r[i].A.A < 0 || r[i].B.A > room.A || r[i].A.B < 0 || r[i].B.B > room.B) contained = false;
		}
		if (!contained){
			puts("NONCONTAINED");
			continue;
		}
		ll total = 0;
		REP(i,n) total += (ll)(r[i].B.A - r[i].A.A) * (r[i].B.B - r[i].A.B);
		if (total == (ll)room.A * room.B){
			puts("OK");
		}
		else {
			puts("NONCOVERING");
		}
	}
	
	return 0;
}
