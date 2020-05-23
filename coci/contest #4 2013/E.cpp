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

#define INF 1000000000
#define MAXN 111
int n, a[MAXN], ans[MAXN], c[MAXN];
set<int> s;

vector<int> criticalPoints (int t) {
	vector<int> res;
	int x, tx;
	for (x = 1; ; ++x) {
		if (t/x == t/(x+1)) break;
		res.PB(x);
	}
	tx = t/x;
	FOR(i,0,tx) {
		res.PB(t/(i+1) + 1);
	}
	return res;
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	
	sort(a+1,a+1+n);
	
	FOR(i,1,n) {
	//	printf("%d-th set %d inserted!\n",i,a[i]);
		vector<int> numbers = criticalPoints(a[i]);
		FORIT(it,numbers) s.insert(*it);
	}
	
	printf("size = %d\n",SZ(s));
	
	FOR(i,1,n) ans[i] = INF;
	
	set<int>::iterator awal, akhir;
	awal = s.begin(); akhir = s.end();
	for (; awal != akhir; awal++) {
		FOR(i,1,n) c[i] = a[i]/(*awal);
		int cot = 0, last = -1;
		FOR(i,1,n) {
			if (c[i] != last) {
				MN(ans[cot],*awal);
				cot = 0;
			}
			last = c[i];
			cot++;
		}
		MN(ans[cot],*awal);
	}
	
	FOR(i,1,n) {
		if (ans[i] == INF) printf("-1\n"); else printf("%d\n",ans[i]);
	}
	
	return 0;
}
