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

#define MAXN 2222
#define INF 1000000

struct Point{
	int x, y;
};

bool comp(const PII &a, const PII &b){
	if (a.se == 0) return false; else if (b.se == 0) return true;
	return (LL)(a.fi*b.se - a.se*b.fi)*(LL)(a.se*b.se) < 0;
}
bool same(const PII &a, const PII &b){
	return a.fi*b.se == a.se*b.fi;
}

bool used[MAXN][MAXN];

int main(){
	int n;
	LL ans = 0;
	Point p[MAXN];
	
	cin >> n;
	
	assert(3 <= n && n <= 2000);
	
	FOR(i,1,n) cin >> p[i].x >> p[i].y;
	FOR(i,1,n){
		assert(0 <= p[i].x && p[i].x <= 2000);
		assert(0 <= p[i].y && p[i].y <= 2000);
		assert(!used[p[i].x][p[i].y]);
		used[p[i].x][p[i].y] = true;
		
		PII grad[MAXN];
		
		FOR(j,1,n) grad[j > i ? j-1 : j] = mp(p[i].y-p[j].y,p[i].x-p[j].x);
		sort(grad+1,grad+n,comp);
		
		LL cot = 0;
		FOR(j,1,n-1){
			cot++;
			if (same(grad[j],grad[j+1])) continue;
			ans += cot*(cot-1)/2;
			cot = 0;
		}
		ans += cot*(cot-1)/2;
	}
	cout << ans/3 << endl;
	
	return 0;
}
