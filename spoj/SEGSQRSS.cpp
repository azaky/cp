#include <cstdio>
using namespace std;

typedef long long LL;

LL getLL(){
	LL ret = 0, mul = 1LL;
	char ch = getchar_unlocked();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar_unlocked();
	if (ch == '-'){
		mul = -1LL;
		ch = getchar_unlocked();
	}
	do ret = (ret<<1)+(ret<<3)+ch-'0';
	while ((ch = getchar_unlocked()) && ('0' <= ch && ch <= '9'));
	return ret*mul;
}

struct node{
	LL l,r;
	LL sum, add, flag, sqr;
};

const LL maxn = 100100;
LL tc, itc;
LL n, q, a[maxn], task, x, y, add;
node tree[4*maxn];

void build(LL v);
void push(LL v, LL flag, LL add);
void update(LL v);
void update(LL v, LL x, LL y, LL flag, LL num);
LL query(LL v, LL x, LL y);

int main(){
	tc = getLL();
	for (itc = 1; itc <= tc; ++itc){
		printf("Case %I64d:\n",itc);
		n = getLL(); q = getLL();
		for (LL i=1; i <= n; ++i) a[i] = getLL();
		tree[1].l = 1; tree[1].r = n;
		build(1);
		for (LL i=0; i<q; ++i){
			task = getLL(); x = getLL(); y = getLL();
			if (task < 2) update(1,x,y,task+1,getLL());
				else printf("%I64d\n",query(1,x,y));
		}
	}
	return 0;
}
void build(LL v){
	LL l = tree[v].l, r = tree[v].r;
	if (l == r){
		tree[v].sum = a[l];
		tree[v].sqr = a[l]*a[l];
		tree[v].add = tree[v].flag = 0;
		return;
	}
	tree[2*v].l = l; tree[2*v].r = (l+r)>>1;
	tree[2*v+1].l = 1 + ((l+r)>>1); tree[2*v+1].r = r;
	build(2*v); build(2*v+1);
	tree[v].sum = tree[2*v].sum + tree[2*v+1].sum;
	tree[v].sqr = tree[2*v].sqr + tree[2*v+1].sqr;
	tree[v].add = tree[v].flag = 0;
}
void push(LL v, LL flag, LL add){
	if (flag == 1){
		tree[v].flag = flag;
		tree[v].add = add;
	}
	else tree[v].add += add;
	if (!tree[v].flag) tree[v].flag = 2;
}
void update(LL v){
	LL add = tree[v].add, range = tree[v].r - tree[v].l + 1;
	if (tree[v].flag == 1){ // same numbers
		tree[v].sum = add*range;
		tree[v].sqr = add*add*range;
	}
	else { // increment values with add
		tree[v].sqr += add*(2*tree[v].sum+add*range);
		tree[v].sum += add*range;
	}
	push(2*v,tree[v].flag,add); push(2*v+1,tree[v].flag,add);
	tree[v].flag = tree[v].add = 0;
}
void update(LL v, LL x, LL y, LL flag, LL add){
	if (tree[v].r < x || tree[v].l > y) return;
	if (tree[v].flag) update(v);
	if (x <= tree[v].l && tree[v].r <= y){
		tree[v].flag = flag; tree[v].add = add;
		update(v);
		return;
	}
	update(2*v,x,y,flag,add); update(2*v+1,x,y,flag,add);
	tree[v].sum = tree[2*v].sum+tree[2*v+1].sum;
	tree[v].sqr = tree[2*v].sqr+tree[2*v+1].sqr;
}
LL query(LL v, LL x, LL y){
	if (tree[v].r < x || tree[v].l > y) return 0;
	if (tree[v].flag) update(v);
	if (x <= tree[v].l && tree[v].r <= y) return tree[v].sqr;
	return query(2*v,x,y)+query(2*v+1,x,y);
}
