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
#define REPD(i,n) for (int i = n-i; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) (s.find(a) != s.end())

/* -------------- end of azaky's template -------------- */

#define MAXN 100100
int n, a[MAXN], lis[MAXN], best[MAXN], ans[MAXN], cans, rmq[4*MAXN];

void build(int v, int l, int r){
	rmq[v] = 0;
	if (l != r) build(2*v,l,(l+r)/2), build(2*v+1,(l+r+2)/2,r);
}
void update(int v, int l, int r, int x, int y){
	if (x < l || r < x) return;
	if (l == r){
		rmq[v] = y;
		return;
	}
	update(2*v,l,(l+r)/2,x,y); update(2*v+1,(l+r+2)/2,r,x,y);
	rmq[v] = max(rmq[2*v],rmq[2*v+1]);
}
int query(int v, int l, int r, int x, int y){
	if (y < l || r < x) return 0;
	if (x <= l && r <= y) return rmq[v];
	return max(query(2*v,l,(l+r)/2,x,y),query(2*v+1,(l+r+2)/2,r,x,y));
}

int main(){
	FOR(itc,1,10){
		scanf("%d",&n);
		FOR(i,1,n) scanf("%d",&a[i]);
		build(1,1,n);
		int maxlis = 0;
		FOR(i,1,n){
			lis[i] = query(1,1,n,1,a[i])+1;
			maxlis = max(maxlis,lis[i]);
			update(1,1,n,a[i],lis[i]);
		}
		FOR(i,1,maxlis) best[i] = 0;
		best[maxlis+1] = n+1;
		cans = 0;
		FORD(i,n,1){
			if (a[i] < best[lis[i]+1]){
				ans[cans++] = a[i];
				best[lis[i]] = max(best[lis[i]],a[i]);
			}
		}
		sort(ans,ans+cans);
		printf("%d\n",cans);
		REP(i,cans-1) printf("%d ",ans[i]); printf("%d\n",ans[cans-1]);
	}
	return 0;
}
