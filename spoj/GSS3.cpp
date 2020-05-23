#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
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
	int time_void;
	#define GetTime time_void = clock();\
	printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

inline int StringToInt(string s){
	int x;
	stringstream(s) >> x;
	return x;
}
inline string IntToString(int x){
	stringstream s;
	s << x;
	return s.str();
}
int max3(int a, int b, int c){
	if (a >= b && a >= c) return a;
	return b > c ? b : c;
}
int max4(int a, int b, int c, int d){
	if (a >= b && a >= c && a >= d) return a;
	if (b >= c && b >= d) return b;
	return c > d ? c : d;
}

/* -------------- end of azaky's template -------------- */

struct node{
	int l,r,sum,pre,su,mid;
};

const int maxn = 50500;
const int INF = 1000000000;
int n, a[maxn], q, x, y, task;
node tree[4*maxn],ans;

void calc(int v);
void update(int v, int x, int y);
node query(int v, int x, int y);

int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
	tree[1].l = 1; tree[1].r = n;
	calc(1);
	scanf("%d",&q);
	for (int i=1; i<=q; ++i){
		scanf("%d%d%d",&task,&x,&y);
		if (task == 0) update(1,x,y);
		  else printf("%d\n",query(1,x,y).mid);
	}
	return 0;
}

void calc(int v){
	if (tree[v].l == tree[v].r){
		tree[v].sum = tree[v].pre = tree[v].su = tree[v].mid = a[tree[v].l];
		return;
	}
	int m = (tree[v].l+tree[v].r)>>1;
	tree[2*v].l = tree[v].l; tree[2*v].r = m; tree[2*v+1].l = m+1; tree[2*v+1].r = tree[v].r;
	calc(2*v); calc(2*v+1);
	tree[v].sum = tree[2*v].sum+tree[2*v+1].sum;
	tree[v].pre = max(tree[2*v].sum+tree[2*v+1].pre,tree[2*v].pre);
	tree[v].su = max(tree[2*v].su+tree[2*v+1].sum,tree[2*v+1].su);
	tree[v].mid = max3(tree[2*v].mid,tree[2*v+1].mid,tree[2*v].su+tree[2*v+1].pre);
}
void update(int v, int x, int y){
	if (tree[v].r < x || tree[v].l > x) return;
	if (tree[v].l == tree[v].r){
		tree[v].sum = tree[v].pre = tree[v].su = tree[v].mid = y;
		return;
	}
	update(2*v,x,y); update(2*v+1,x,y);
	tree[v].sum = tree[2*v].sum+tree[2*v+1].sum;
	tree[v].pre = max(tree[2*v].sum+tree[2*v+1].pre,tree[2*v].pre);
	tree[v].su = max(tree[2*v].su+tree[2*v+1].sum,tree[2*v+1].su);
	tree[v].mid = max3(tree[2*v].mid,tree[2*v+1].mid,tree[2*v].su+tree[2*v+1].pre);
}
node query(int v, int x, int y){
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
