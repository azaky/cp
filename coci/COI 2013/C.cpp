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

const int MAXN = (1 << 18);
int n, q, d[MAXN], pos[MAXN];
PII RMQ[4*MAXN];

void build(int v, int l, int r){
	if (l == r){
		RMQ[v] = mp(pos[l],pos[r]);
		return;
	}
	int mid = (l+r)>>1;
	build(2*v,l,mid); build((2*v)+1,mid+1,r);
	RMQ[v] = mp(min(RMQ[2*v].fi,RMQ[(2*v)+1].fi),max(RMQ[2*v].se,RMQ[(2*v)+1].se));
}
void update(int v, int l, int r, int x){
	if (r < x || x < l) return;
	if (l == r){
		RMQ[v] = mp(pos[l],pos[r]);
		return;
	}
	int mid = (l+r)>>1;
	update(2*v,l,mid,x); update((2*v)+1,mid+1,r,x);
	RMQ[v] = mp(min(RMQ[2*v].fi,RMQ[(2*v)+1].fi),max(RMQ[2*v].se,RMQ[(2*v)+1].se));
}
PII query(int v, int l, int r, int a, int b){
	if (r < a || b < l) return mp(n+1,0);
	if (a <= l && r <= b) return RMQ[v];
	int mid = (l+r)>>1;
	PII ansl = query(2*v,l,mid,a,b);
	PII ansr = query((2*v)+1,mid+1,r,a,b);
	return mp(min(ansl.fi,ansr.fi),max(ansl.se,ansr.se));
}

int main(){
	scanf("%d%d",&n,&q);
	FOR(i,1,n) scanf("%d",&d[i]), pos[d[i]] = i;
	//RMQ INITIALIZATION
	build(1,1,n);
	while (q--){
			//FOR(i,1,n) printf("%d ",pos[i]); printf("\n");
			//FOR(i,1,n) printf("%d ",query(1,1,n,i,i).fi); printf("\n");
			//FOR(i,1,n) printf("%d ",query(1,1,n,i,i).se); printf("\n");
		int task, a, b;
		scanf("%d%d%d",&task,&a,&b);
		if (task == 1){
			swap(d[a],d[b]);
			swap(pos[d[a]],pos[d[b]]);
			update(1,1,n,d[a]); update(1,1,n,d[b]);
		}
		if (task == 2){
			PII ans = query(1,1,n,a,b);
			puts(ans.se-ans.fi == b-a ? "YES" : "NO");
		}
	}
	
	return 0;
}
