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
#define ALL(a) a.begin(),a.end()
#define EXIST(a,s) (s.find(a) != s.end())

/* -------------- end of azaky's template -------------- */

struct point{int x,y;};
bool compx(const point &P1, const point &P2){if (P1.x < P2.x) return true; else return (P1.x == P2.x && P1.y < P2.y);}
struct node{int xl,xr; vector<int> v;};

const int maxn = 100100;
const int INF = 1000000001;
int n, a[10], px[maxn], py[maxn];
point p[maxn];
node tree[4*maxn];

void build(int v, int l, int r){
	tree[v].xl = p[l].x; tree[v].xr = p[r].x; tree[v].v.resize(r-l+1);
	if (l == r){*tree[v].v.begin() = p[l].y; return;}
	build(2*v,l,(l+r)/2); build(2*v+1,(l+r+2)/2,r);
	merge(ALL(tree[2*v].v),ALL(tree[2*v+1].v),tree[v].v.begin());
}
int query(int v, int xl, int xr, int yl, int yr){
	if (tree[v].xr < xl || tree[v].xl > xr) return 0;
	if (xl <= tree[v].xl && tree[v].xr <= xr) return upper_bound(ALL(tree[v].v),yr)-lower_bound(ALL(tree[v].v),yl);
	return query(2*v,xl,xr,yl,yr)+query(2*v+1,xl,xr,yl,yr);
}
int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,compx); build(1,1,n);
	FOR(i,1,n){px[i] = p[i].x; py[i] = p[i].y;}
	sort(py+1,py+n+1);
	FOR(i,1,9) scanf("%d",&a[i]);
	sort(a+1,a+10);
	do{
		int U = a[1]+a[2]+a[3];
		int L = a[1]+a[4]+a[7];
		int D = a[7]+a[8]+a[9];
		int R = a[3]+a[6]+a[9];
		int xl = px[L], xr = px[n-R+1], yl = py[D], yr = py[n-U+1];
		if (xl == px[L+1] || xr == px[n-R] || yl == py[D+1] || yr == py[n-U]) continue;
		if (query(1,-INF,xl,yr,INF) != a[1]) continue;
		if (query(1,xr,INF,yr,INF) != a[3]) continue;
		if (query(1,-INF,xl,-INF,yl) != a[7]) continue;
		if (query(1,xr,INF,-INF,yl) != a[9]) continue;
		printf("%.5lf %.5lf\n%.5lf %.5lf\n",(double)xl+.5,(double)xr-.5,(double)yl+.5,(double)yr-.5);
		exit(0);
	} while (next_permutation(a+1,a+10));
	puts("-1");
	return 0;
}
