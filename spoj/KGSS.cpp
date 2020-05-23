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

/* -------------- end of azaky's template -------------- */

#define maxn 111111
#define INF 1000000000

struct node{int m /* max */, m2;} tree[4*maxn];
int n, a[maxn], q, x, y;
char task;

void build(int v, int l, int r, int x){
	if (x != 0 && (r < x || x < l)) return;
	if (l == r){
		tree[v].m = a[l]; tree[v].m2 = -INF;
		return;
	}
	build(2*v,l,(l+r)/2,x); build(2*v+1,(l+r+2)/2,r,x);
	if (tree[2*v].m > tree[2*v+1].m){
		tree[v].m = tree[2*v].m;
		if (tree[2*v].m2 > tree[2*v+1].m) tree[v].m2 = tree[2*v].m2; else tree[v].m2 = tree[2*v+1].m;
	}
	else{
		tree[v].m = tree[2*v+1].m;
		if (tree[2*v+1].m2 > tree[2*v].m) tree[v].m2 = tree[2*v+1].m2; else tree[v].m2 = tree[2*v].m;
	}
}
node query(int v, int l, int r, int x, int y){
	node ret;
	if (r < x || y < l){ret.m = ret.m2 = -INF; return ret;}
	if (x <= l && r <= y) return tree[v];
	node left = query(2*v,l,(l+r)/2,x,y), right = query(2*v+1,(l+r+2)/2,r,x,y);
	if (left.m > right.m){
		ret.m = left.m;
		if (left.m2 > right.m) ret.m2 = left.m2; else ret.m2 = right.m;
	}
	else{
		ret.m = right.m;
		if (right.m2 > left.m) ret.m2 = right.m2; else ret.m2 = left.m;
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	build(1,1,n,0);
	scanf("%d",&q);
	REP(i,q){
		scanf("\n%c %d %d",&task,&x,&y);
		if (task == 'Q'){
			node ans = query(1,1,n,x,y);
			printf("%d\n",ans.m+ans.m2);
		}
		else{
			a[x] = y;
			build(1,1,n,x);
		}
	}
	
	return 0;
}
