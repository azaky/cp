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
	#define GetTime	fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);
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

const int MAXN = 511111;
struct Node{
	int xl, xr;
	vector<int> y;
} node[4*MAXN];

int ntc, n, a[MAXN], b[MAXN], c[MAXN], pos[MAXN], posa[MAXN], posb[MAXN], posc[MAXN], BIT[MAXN];
PII p[MAXN];
pair<PII,int> x[MAXN];

int presum(int k){int ret=0; for(int x=k;x>0;x-=(x&-x))ret+=BIT[x]; return ret;}
int sum(int l, int r){return presum(r)-presum(l-1);}
void update(int k){for(int x=k;x<=n;x+=(x&-x))++BIT[x];}

void build(int v, int l, int r){
	node[v].xl = x[l].fi.fi; node[v].xr = x[r].fi.fi;
	if (l == r){
		node[v].y.clear();
		node[v].y.pb(x[l].fi.se);
	}
	else {
		build(2*v,l,(l+r)/2); build(2*v+1,(l+r+2)/2,r);
		node[v].y.resize(r-l+1);
		merge(ALL(node[2*v].y),ALL(node[2*v+1].y),node[v].y.begin());
	}
}
int query(int v, int l, int r, PII P){
	if (P.fi < node[v].xl) return 0;
	if (node[v].xr <= P.se) return sum(l,l+(lower_bound(ALL(node[v].y),P.se)-node[v].y.begin())-1);
	return query(2*v,l,(l+r)/2,P)+query(2*v,(l+r+2)/2,r,P);
}

int main(){
	ntc = 1;
	FOR(itc,1,ntc){
		scanf("%d",&n);
		FOR(i,1,n) scanf("%d",&a[i]);
		FOR(i,1,n) scanf("%d",&b[i]);
		FOR(i,1,n) scanf("%d",&c[i]);
		FOR(i,1,n) posa[a[i]] = i;
		FOR(i,1,n) b[i] = posa[b[i]], c[i] = posa[c[i]];
		FOR(i,1,n) posb[b[i]] = posc[c[i]] = i;
		
		FOR(i,1,n) p[posa[i]] = mp(posb[i],posc[i]);
		
		//FOR(i,1,n) printf("(%d,%d)\n",p[i].fi,p[i].se);
		
		//initialization
		int ans = 0;
		FOR(i,1,n) x[i].fi = p[i], x[i].se = i;
		
		sort(x+1,x+n+1);
		
		//FOR(i,1,n) printf("[%d,%d]\n",x[i].fi.fi,x[i].fi.se);
		
		FOR(i,1,n) pos[x[i].se] = i;
		build(1,1,n);
		FOR(i,0,n) BIT[i] = 0;
		
		
		//calculation
		FOR(i,1,n){
			if (query(1,1,n,p[i]) == 0) ++ans;
			update(pos[i]);
			//printf("ANS AFTER UPDATING (%d,%d) = %d\n",x[pos[i]].fi.fi,x[pos[i]].fi.se,ans);
		}
		printf("%d\n",ans);
	}	
	
	GetTime;
	
	return 0;
}
