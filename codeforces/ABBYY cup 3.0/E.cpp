#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
	#define GetTime()	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
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

#define MOD 1000000000LL

struct matrix{
	ll a[2][2];
};
matrix product(matrix a, matrix b){
	matrix res;
	REP(i,2) REP(j,2) res.a[i][j] = 0;
	REP(k,2) REP(i,2) REP(j,2) res.a[i][j] = (res.a[i][j] + a.a[i][k]*b.a[k][j])%MOD;
	return res;
}
matrix power(matrix x, ll n){
	if (n == 1) return x;
	matrix res = power(x,n/2);
	res = product(res,res);
	if (n%2) res = product(res,x);
	return res;
}

ll fibo(ll n, ll f0, ll f1){
	if (n == 0) return f0;
	if (n == 1) return f1;
	matrix h;
	h.a[0][0] = 1; h.a[0][1] = 1;
	h.a[1][0] = 1; h.a[1][1] = 0;
	h = power(h,n);
	return (h.a[1][0]*f1 + h.a[1][1]*f0)%MOD;
}

struct node{
	ll f0, f1;
	ll f(ll n){
		return fibo(n,f0,f1);
	}
};
#define MAXN (1<<18)
node tree[MAXN << 2];
ll a[MAXN];
int n,m;

void build(int v, int l, int r){
	if (l == r){
		tree[v].f0 = 0;
		tree[v].f1 = a[l];
	}
	else {
		int mid = (l+r)/2;
		build(2*v,l,mid); build(2*v+1,mid+1,r);
		int k = mid-l+1;
		tree[v].f0 = (tree[2*v].f0 + tree[2*v+1].f(k)) % MOD;
		tree[v].f1 = (tree[2*v].f1 + tree[2*v+1].f(k+1)) % MOD;
	}
}

void update(int v, int l, int r, int x){
	if (r < x || x < l) return;
	if (l == r){
		tree[v].f0 = 0;
		tree[v].f1 = a[l];
	}
	else {
		int mid = (l+r)/2;
		update(2*v,l,mid,x); update(2*v+1,mid+1,r,x);
		int k = mid-l+1;
		tree[v].f0 = (tree[2*v].f0 + tree[2*v+1].f(k)) % MOD;
		tree[v].f1 = (tree[2*v].f1 + tree[2*v+1].f(k+1)) % MOD;
	}
}

ll query(int v, int l, int r, int x, int y){
	if (y < l || r < x) return 0;
	if (x <= l && r <= y) return tree[v].f(l-x+1);
	int mid = (l+r)/2;
	return (query(2*v,l,mid,x,y)+query(2*v+1,mid+1,r,x,y))%MOD;
}
int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%I64d",&a[i]);
	build(1,1,n);
	REP(itc,m){
		int tipe;
		scanf("%d",&tipe);
		if (tipe == 1){
			int x; ll v;
			scanf("%d%I64d",&x,&v);
			a[x] = v;
			update(1,1,n,x);
		}
		if (tipe == 2){
			int l, r;
			scanf("%d%d",&l,&r);
			printf("%I64d\n",query(1,1,n,l,r));
		}
		if (tipe == 3){
			int l, r, d;
			scanf("%d%d%d",&l,&r,&d);
			puts("au ah");
		}
	}
			
	return 0;
}
