#include <cstdio>
using namespace std;

int max(int a, int b){
	return a > b ? a : b;
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
int getint(){
	int ret = 0, mul = 1;
	char ch = getchar_unlocked();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar_unlocked();
	if (ch == '-'){
		mul = -1;
		ch = getchar_unlocked();
	}
	do ret = (ret<<1)+(ret<<3)+ch-'0';
	while ((ch = getchar_unlocked()) && ('0' <= ch && ch <= '9'));
	return ret*mul;
}

/* -------------- end of azaky's template -------------- */

struct node{
	int l,r,sum,pre,su,mid;
};

const int maxn = 50500;
const int INF = 1000000000;
int n, a[maxn], q, x, y;
node tree[4*maxn],ans;

void calc(int v);
node query(int v, int x, int y);

int main(){
	n = getint();
	for (int i=1; i<=n; ++i) a[i] = getint();
	tree[1].l = 1; tree[1].r = n;
	calc(1);
	q = getint();
	for (int i=1; i<=q; ++i){
		x = getint(); y = getint();
		ans = query(1,x,y);
		printf("%d\n",ans.mid);
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
