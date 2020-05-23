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

int ntc, n, m;
db water, a[111][111];

int main(){
	while (cin >> n >> m && n && m && ++ntc){
		FOR(i,1,n) FOR(j,1,m) scanf("%lf",&a[i][j]);
		scanf("%lf",&water);
		water /= 100.;
		/* n m kecil, brute aja lah ya */
		db level = 1e100, gone = 0;
		FOR(i,1,n) FOR(j,1,m) MN(level,a[i][j]);
		while (water > 0){
			db minh = 1e100, occ = 0;
			FOR(i,1,n) FOR(j,1,m){
				if (a[i][j] == minh) occ += 1.;
				else if (a[i][j] < minh){
					minh = a[i][j];
					occ = 1.;
				}
			}
			if (occ == 0){
				puts("ciyus dikit lah mas!");
			}
			else if (occ == (db)(n*m)){
				//fill all with water!
				level += water / occ;
				water -= water;
			}
			else {
				db minh2 = 1e100;
				FOR(i,1,n) FOR(j,1,m){
					if (a[i][j] < minh2 && a[i][j] != minh) minh2 = a[i][j];
				}
				db add = min(minh2-minh,water/occ);
				level += add;
				water -= add * occ;
				FOR(i,1,n) FOR(j,1,m){
					if (a[i][j] == minh) a[i][j] = minh2;
				}
			}
			gone = occ;
		}
		printf("Region %d\n",ntc);
		printf("Water level is %.2lf meters.\n",level);
		printf("%.2lf percent of the region is under water.\n",100.*gone /(db)(m*n));
		puts("");
	}
	
	return 0;
}
