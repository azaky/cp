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
	#define GetTime()	fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
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
int n, m, a[MAXN], hl[MAXN], hr[MAXN], dl[MAXN], dr[MAXN], q, x, ans[MAXN];
vector<int> tree[4*MAXN], _h[MAXN];

void build(int v, int l, int r){
	tree[v].clear();
	if (l == r){
		FORIT(it,_h[l]) tree[v].PB(*it);
		sort(ALL(tree[v]));
	}
	else {
		int vl = v<<1, vr = vl|1, mid = (l+r)>>1;
		build(vl,l,mid); build(vr,mid+1,r);
		tree[v].resize(SZ(tree[vl])+SZ(tree[vr]));
		merge(ALL(tree[vl]),ALL(tree[vr]),tree[v].begin());
	}
}

int query(int v, int l, int r, int sa, int sb, int ea, int eb){
	if (r < sa || sb < l) return 0;
	else if (sa <= l && r <= sb) return upper_bound(ALL(tree[v]),eb) - lower_bound(ALL(tree[v]),ea);
	else return query(v<<1,l,(l+r)>>1,sa,sb,ea,eb) + query((v<<1)|1,(l+r+2)>>1,r,sa,sb,ea,eb);
}

int findL(int x){return x == dl[x] ? x : findL(dl[x]);}
int findR(int x){return x == dr[x] ? x : findR(dr[x]);}
void mergeL(int x, int y){dl[findL(x)] = findL(y);}
void mergeR(int x, int y){dr[findR(x)] = findR(y);}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,m) scanf("%d%d",&hl[i],&hr[i]);
	//build segment tree
	FOR(i,1,m) _h[hl[i]].PB(hr[i]);
	build(1,1,n);
	//initiate DSU
	FOR(i,1,n) dl[i] = dr[i] = i;
	//do queries
	scanf("%d",&q);
	FOR(iq,1,q){
		scanf("%d",&x);
		x += ans[iq-1];
		a[x] --;
		ans[iq] = ans[iq-1];
		if (a[x] == 0){
			if (a[x-1] == 0 && x != 1) mergeL(x,x-1);
			if (a[x+1] == 0 && x != n) mergeR(x,x+1);
			if (a[x+1] == 0 && x != n) mergeL(x+1,x);
			if (a[x-1] == 0 && x != 1) mergeR(x-1,x);
			ans[iq] += query(1,1,n,findL(x),x,x,findR(x));
		}
		printf("%d\n",ans[iq]);
	}
	GetTime();
	return 0;
}
