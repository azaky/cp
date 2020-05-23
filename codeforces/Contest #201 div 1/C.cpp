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

#define INF 1001001000
#define MAXN 1001000

int a, b, s[MAXN], f[MAXN], d, n, _n, x[MAXN], RMQ[4*MAXN];

int query(int v, int l, int r, int x, int y){
	if (r < x || y < l) return INF;
	if (x <= l && r <= y) return RMQ[v];
	int mid = (l+r)>>1;
	return min(query(2*v,l,mid,x,y),query(2*v+1,mid+1,r,x,y));
}
void update(int v, int l, int r, int x, int y){
	if (r < x || x < l) return;
	if (l == r){
		assert(l == x);
		RMQ[v] = y;
		return;
	}
	int mid = (l+r)>>1;
	update(2*v,l,mid,x,y); update(2*v+1,mid+1,r,x,y);
	RMQ[v] = min(RMQ[2*v],RMQ[2*v+1]);
}

int main(){
    scanf("%d",&_n);
    map<int,int> ada;
    REP(i,_n){
		int _x; scanf("%d",&_x);
		if (!ada[_x]){
			ada[_x] = 1;
			x[n++] = _x;
		}
	}
	scanf("%d%d",&a,&b);
	d = a-b;
	FOR(i,0,d) f[i] = 1;
	REP(i,n){
		int p = (b/x[i])*x[i];
		if (p < b) p += x[i];
		for (; p <= a; p += x[i]) MX(f[p-b],x[i]-1);
	}
	s[d] = 0;
	REPD(i,d){
//		printf("query(%d,%d) = %d\n",i+1,min(i+f[i],d),query(1,1,d,i+1,min(i+f[i],d)));
		s[i] = 1 + query(1,1,d,i+1,min(i+f[i],d));
		update(1,1,d,i,s[i]);
//		printf("s[%d] = %d\n",i+b,s[i]);
//		printf("f[%d] = %d\n",i+b,f[i]);
	}
	printf("%d\n",s[0]);
		
    
    return 0;
}
