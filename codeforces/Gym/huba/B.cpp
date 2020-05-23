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

#define MAXN 10100
int ntc, n, m, p[MAXN], occupied[MAXN], a, b;

int findSet(int x){
	return x == p[x] ? p[x] : p[x] = findSet(p[x]);
}
void unionSet(int x, int y){
	p[findSet(x)] = findSet(y);
}

int main(){
	scanf("%d",&ntc);
	while (ntc--){
		scanf("%d%d",&m,&n);
		REP(i,n) p[i] = i;
		REP(i,n) occupied[i] = 0;
		bool bener = true;
		REP(i,m){
			scanf("%d%d",&a,&b);
			if (!occupied[a]){
				occupied[a] = 1;
				unionSet(a,b);
			}
			else {
				if (occupied[findSet(b)]){
					bener = false;
				}
				else {
					occupied[findSet(b)] = 1;
				}
			}
		}
		if (bener) puts("successful hashing"); else puts("rehash necessary");
	}
	
	return 0;
}
