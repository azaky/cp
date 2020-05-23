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

#define MAXN 100100
int n, a[MAXN], rmq[4*MAXN], lis[MAXN];

int RMQ(int v, int l, int r, int x, int y){
	if (r < x || y < l) return 0;
	if (x <= l && r <= y) return rmq[v];
	return max(RMQ(2*v,l,(l+r)/2,x,y),RMQ(2*v+1,(l+r+2)/2,r,x,y));
}
int update(int v, int l, int r, int x, int y){
	if (r < x || x < l) return rmq[v];
	if (l == r) return rmq[v] = y;
	return rmq[v] = max(update(2*v,l,(l+r)/2,x,y),update(2*v+1,(l+r+2)/2,r,x,y));
}

int main(){
	scanf("%d",&n);
	int ans = 0;
	REP(i,n){
		scanf("%d",&a[i]);
		lis[i] = RMQ(1,1,n,1,a[i]) + 1;
		MX(ans,lis[i]);
		update(1,1,n,a[i],lis[i]);
	}
	printf("%d\n",ans);
	
	return 0;
}
