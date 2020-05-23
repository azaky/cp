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

struct Query{int xl, xr;};
struct Node{int t, add;};

#define MAXY 30030
int n, xl, xr, yl, yr, ans;
vector<Query> q0[MAXY+5], q1[MAXY+5];
Node node[8*MAXY];

void update(int v, int l, int r, int x, int y, int val){
	if (x <= l && r <= y){
		node[v].t = val == 1 ? r-l+1 : 0;
		node[v].add = 0;
		node[2*v].add = node[2*v+1].add = val;
	}
	else if (r < x || y < l){
		if (node[v].add == 1) node[v].t = r-l+1;
		if (node[v].add == -1) node[v].t = 0;
		node[2*v].add = node[2*v+1].add = node[v].add;
		node[v].add = 0;
	}
	else {
		node[2*v].add = node[2*v+1].add = node[v].add;
		node[v].add = 0;
		update(2*v,l,(l+r)/2,x,y,val); update(2*v+1,(l+r+2)/2,r,x,y,val);
		node[v].t = node[2*v].t + node[2*v+1].t;
	}
	//printf("NODE [%d], [%d .. %d], t = [%d]\n",v,l,r,node[v].t);
}

void print(Query q, int y, int v){
	//printf("[%d .. %d] at %d, val = %d\n",q.xl,q.xr,y,v);
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
		Query temp = (Query){xl+1,xr};
		q1[yl + 1].pb(temp);
		q0[yr + 1].pb(temp);
	}
	FOR(y,1,MAXY){
		REP(i,(int)q0[y].size()) update(1,1,MAXY,q0[y][i].xl,q0[y][i].xr,-1), print(q0[y][i],y,-1);
		REP(i,(int)q1[y].size()) update(1,1,MAXY,q1[y][i].xl,q1[y][i].xr,1), print(q1[y][i],y,1);
		ans += node[1].t;
		if (node[1].t != 0) printf("at [%d] : ans = %d\n",y,ans);
	}
	printf("%d\n",ans);
	return 0;
}
