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

const int MAXN = 111111;
int n, m, a[MAXN], b[MAXN], task, x, y, k, flag[4*MAXN];
PII node[4*MAXN];

void update(int v, int l, int r, int aa, int bb){
	if (r < aa || bb < l) return;
	if (aa <= l && r <= bb){
		node[v] = mp(x,y);
		flag[v] = 1;
		return;
	}
	if (flag[v]){
		flag[v] = 0;
		flag[2*v] = flag[2*v+1] = 1;
		node[2*v] = node[2*v+1] = node[v];
	}
	int mid = (l+r)>>1;
	update(2*v,l,mid,aa,bb); update(2*v+1,mid+1,r,aa,bb);
}
PII query(int v, int l, int r, int x){
	if (l == r) return node[v];
	if (flag[v]){
		flag[v] = 0;
		flag[2*v] = flag[2*v+1] = 1;
		node[2*v] = node[2*v+1] = node[v];
	}
	int mid = (l+r)>>1;
	if (x <= mid) return query(2*v,l,mid,x); else return query(2*v+1,mid+1,r,x);
}
	
int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,n) scanf("%d",&b[i]);
	
	FOR(q,1,m){
		scanf("%d",&task);
		if (task == 1){
			scanf("%d%d%d",&x,&y,&k);
			update(1,1,n,y,y+k-1);
		}
		else {
			scanf("%d",&x);
			PII ans = query(1,1,n,x);
			if (ans.fi == 0) printf("%d\n",b[x]); else printf("%d\n",a[ans.fi+x-ans.se]);
		}
	}
	
	
	return 0;
}
