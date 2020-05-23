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
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

#define MAXN 1001000
#define MAXW 44444
LL w, h, wk, hk, n, _x, _y, _a, _b, _c, _d, a[MAXW];
pair<LL,LL> p[MAXN];
map <pair<LL,LL>,LL> MAP;
vector<LL> listx[MAXW];
struct node{
	LL le, ri, mi;
} tree[4*MAXW];

void build(LL v, LL l, LL r){
	tree[v].le = tree[v].ri = r-l+1;
	tree[v].mi = 0;
	if (l < r){
		build(2*v,l,(l+r)/2); build(2*v+1,(l+r+2)/2,r);
	}
}
void add(LL v, LL l, LL r, LL x, LL val){
	if (r < x || x < l) return;
	if (l == r){
		a[l] += val;
		if (a[l] != 0){
			tree[v].le = tree[v].ri = tree[v].mi = 0;
		}
		else {
			tree[v].le = tree[v].ri = 1;
			tree[v].mi = 0;
		}
		return;
	}
	add(2*v,l,(l+r)/2,x,val); add(2*v+1,(l+r+2)/2,r,x,val);
	int sl = ((l+r)/2) - l + 1, sr = r - ((l+r+2)/2) + 1;
	if (tree[2*v].le == sl && tree[2*v+1].ri == sr){
		tree[v].le = tree[v].ri = sl+sr;
		tree[v].mi = 0;
	}
	else if (tree[2*v].le == sl){
		tree[v].le = sl + tree[2*v+1].le;
		tree[v].ri = tree[2*v+1].ri;
		tree[v].mi = tree[2*v+1].mi;
	}
	else if (tree[2*v+1].ri == sr){
		tree[v].le = tree[2*v].le;
		tree[v].ri = tree[2*v].ri + sr;
		tree[v].mi = tree[2*v].mi;
	}
	else {
		tree[v].le = tree[2*v].le;
		tree[v].ri = tree[2*v+1].ri;
		tree[v].mi = tree[2*v].mi + tree[2*v+1].mi + max(0LL,tree[2*v].ri+tree[2*v+1].le-hk+1);
	}
}

LL query(LL v, LL l, LL r){
	//printf("QUERY\n");
	//printf("le = %I64d, ri = %I64d, mi = %I64d\n",tree[v].le,tree[v].ri,tree[v].mi);
	if (tree[v].le == r-l+1) return (r-l+1) - hk + 1;
	return max(0LL,tree[v].le-hk+1) + max(0LL,tree[v].ri-hk+1) + tree[v].mi;
}

int main(){
	int ntc; scanf("%d",&ntc);
	FOR(itc,1,ntc){
		cin >> w >> h >> wk >> hk >> n >> _x >> _y >> _a >> _b >> _c >> _d;
		p[0] = mp(_x,_y);
		FOR(i,1,n-1) p[i] = mp((p[i-1].fi*_a + p[i-1].se*_b + 1)%w,(p[i-1].fi*_c + p[i-1].se*_d + 1)%h);
		//REP(i,n) cout << p[i].fi << " " << p[i].se << endl;
		MAP.clear();
		REP(i,w) listx[i].clear();
		REP(i,n){
			if (MAP[p[i]]) continue;
			MAP[p[i]] = true;
			listx[p[i].fi].pb(p[i].se);
		}
		//clear and build the segment here
		RESET(a,0);
		build(1,0,h-1);
		REP(i,wk){
			REP(j,listx[i].size()){
				add(1,0,h-1,listx[i][j],+1);
				//REP(_j,h) printf("%d",a[_j]); printf("\n");
			}
		}
		LL ans = 0;
		FOR(i,wk-1,w-1){
			ans += query(1,0,h-1);
			REP(j,listx[i-wk+1].size()){
				add(1,0,h-1,listx[i-wk+1][j],-1);
			}
			REP(j,listx[i+1].size()){
				add(1,0,h-1,listx[i+1][j],+1);
			}
		}
		cout << "Case #" << itc << ": " << ans << endl;
	}
		
	
	return 0;
}
