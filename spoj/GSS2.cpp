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

LL max3(LL a, LL b, LL c){
	if (a >= b && a >= c) return a;
	return b > c ? b : c;
}

/* -------------- end of azaky's template -------------- */

const int MAXQ = 111111;
const int MAXN = 111111;
const int MAXA = 222222;
const LL ADD = 100005LL;
const LL INF = 1000000000000000LL;

struct Query{
	LL tipe, x, y, i;
};
bool comp(const Query &a, const Query &b){
	if (a.y == b.y) return a.tipe < b.tipe; else return a.y < b.y;
}

LL n, nq, nt, ans[MAXQ], bit[MAXN+1], pos[MAXA], a[MAXN];
Query q[MAXN+MAXQ+1];

struct node{
	LL l,r,sum,pre,su,mid;
} tree[4*MAXN];

void build(LL v, LL l, LL r){
	tree[v].l = l; tree[v].r = r;
	if (l == r) return;
	build(2*v,l,(l+r)/2); build(2*v+1,(l+r+2)/2,r);
}
void update(LL v, LL x){
	if (tree[v].r < x || x < tree[v].l) return;
	if (tree[v].l == tree[v].r){
		tree[v].sum = tree[v].pre = tree[v].su = tree[v].mid = a[tree[v].l];
		return;
	}
	LL m = (tree[v].l+tree[v].r)>>1;
	tree[2*v].l = tree[v].l; tree[2*v].r = m; tree[2*v+1].l = m+1; tree[2*v+1].r = tree[v].r;
	update(2*v,x); update(2*v+1,x);
	tree[v].sum = tree[2*v].sum+tree[2*v+1].sum;
	tree[v].pre = max(tree[2*v].sum+tree[2*v+1].pre,tree[2*v].pre);
	tree[v].su = max(tree[2*v].su+tree[2*v+1].sum,tree[2*v+1].su);
	tree[v].mid = max3(tree[2*v].mid,tree[2*v+1].mid,tree[2*v].su+tree[2*v+1].pre);
}
node query(LL v, LL x, LL y){
	node ret;
	if (tree[v].r < x || tree[v].l > y){
		ret.sum = 0;
		ret.pre = ret.su = ret.mid = -INF;
		return ret;
	}
	if (x <= tree[v].l && tree[v].r <= y) return tree[v];
	node kiri = query(2*v,x,y);
	node kanan = query(2*v+1,x,y);
	ret.sum = kiri.sum+kanan.sum;
	ret.pre = max(kiri.pre,kiri.sum+kanan.pre);
	ret.su = max(kanan.su,kiri.su+kanan.sum);
	ret.mid = max3(kiri.mid,kanan.mid,kiri.su+kanan.pre);
	return ret;
}

int main(){
	//scanf(LLD,&n);
	cin >> n;
	build(1,1,n);
	FOR(i,1,n){
		q[nt].tipe = 1;
		//scanf(LLD,&q[nt].x);
		cin >> q[nt].x;
		q[nt].y = i;
		nt++;
	}
	//scanf(LLD,&nq);
	cin >> nq;
	FOR(i,1,nq){
		q[nt].tipe = 2;
		//scanf(LLD LLD,&q[nt].x,&q[nt].y);
		cin >> q[nt].x >> q[nt].y;
		q[nt].i = i;
		nt++;
	}
	sort(q,q+nt,comp);
	REP(i,nt){
		if (q[i].tipe == 1){
			if (pos[q[i].x+ADD]){
				a[pos[q[i].x+ADD]] = 0;
				update(1,pos[q[i].x+ADD]);
			}
			pos[q[i].x+ADD] = q[i].y;
			a[pos[q[i].x+ADD]] = q[i].x;
			update(1,pos[q[i].x+ADD]);
		}
		else ans[q[i].i] = query(1,q[i].x,q[i].y).mid;
	}
	FOR(i,1,nq) cout << ((ans[i] < 0) ? 0 : ans[i]) << endl;
	return 0;
}
