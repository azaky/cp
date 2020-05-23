#include <cstdio>
using namespace std;

#define FOR(i,a,b) for (int i = a; i <= b; ++i)

#define getchar_unlocked getchar
int getint(){
	int ret = 0;
	char ch = getchar_unlocked();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar_unlocked();
	do ret = (ret<<1)+(ret<<3)+ch-'0';
	while ((ch = getchar_unlocked()) && ('0' <= ch && ch <= '9'));
	return ret;
}

int min(int a, int b){if (a < b) return a; return b;}

/* -------------- end of azaky's template -------------- */

#define MAXN 33333

struct Node{
	int rmq, add;
} node[8*MAXN];

int n, nq, a[MAXN], sum[MAXN], k;

void build(int v, int l, int r){
	node[v].add = 0;
	if (l == r) node[v].rmq = sum[l];
		else {
			build(2*v, l, (l+r)/2); build(2*v+1,(l+r+2)/2,r);
			node[v].rmq = min(node[2*v].rmq, node[2*v+1].rmq);
		}
}
void update(int v, int l, int r, int x, int y, int add){
	if (r < x || y < l){
		node[v].rmq += node[v].add;
		node[2*v].add += node[v].add; node[2*v+1].add += node[v].add;
		node[v].add = 0;
	}
	else if (x <= l && r <= y){
		node[v].add += add;
		node[v].rmq += node[v].add;
		node[2*v].add += node[v].add; node[2*v+1].add += node[v].add;
		node[v].add = 0;
	}
	else {
		node[2*v].add += node[v].add; node[2*v+1].add += node[v].add;
		node[v].add = 0;
		update(2*v,l,(l+r)/2,x,y,add); update(2*v+1,(l+r+2)/2,r,x,y,add);
		node[v].rmq = min(node[2*v].rmq,node[2*v+1].rmq);
	}
}

int main(){
	FOR(itc,1,10){
		printf("Test %d:\n",itc);
		n = getint();
		FOR(i,1,n){
			char ch = getchar_unlocked();
			while (ch != '(' && ch != ')') ch = getchar_unlocked();
			a[i] = ch == '(' ? 1 : -1;
		}
		FOR(i,1,n) sum[i] = sum[i-1] + a[i];
		build(1,1,n);
		nq = getint();
		FOR(i,1,nq){
			k = getint();
			if (k == 0){
				if (sum[n] == 0 && node[1].rmq >= 0) puts("YES"); else puts("NO");
			}
			else {
				update(1,1,n,k,n,(-2) * a[k]);
				sum[n] += (-2) * a[k];
				a[k] *= -1;
			}
		}
	}
	return 0;
}
