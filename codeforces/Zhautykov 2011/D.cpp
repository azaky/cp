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

#define MAXN 100001
struct Node{
	int mn,mx,add;
} node[8*MAXN];

void update(int v, int l, int r, int x, int y, int add){
	if (r < x || y < l){
		node[v].mn += node[v].add; node[v].mx += node[v].add;
		node[2*v].add += node[v].add; node[2*v+1].add += node[v].add;
		node[v].add = 0;
	}
	else if (x <= l && r <= y){
		node[v].add += add;
		node[v].mn += node[v].add; node[v].mx += node[v].add;
		node[2*v].add += node[v].add; node[2*v+1].add += node[v].add;
		node[v].add = 0;
	}
	else {
		node[2*v].add += node[v].add; node[2*v+1].add += node[v].add;
		node[v].add = 0;
		update(2*v,l,(l+r)/2,x,y,add); update(2*v+1,(l+r+2)/2,r,x,y,add);
		node[v].mx = max(node[2*v].mx,node[2*v+1].mx);
		node[v].mn = min(node[2*v].mn,node[2*v+1].mn);
	}
}

int n, r, s;

int main(){
	//freopen("stones.in","r",stdin);
	//freopen("stones.out","w",stdout);
	
	scanf("%d",&n);
	REP(i,n){
		scanf("%d%d",&r,&s);
		update(1,1,n,1,r,s == 1 ? 1 : -1);
		if (node[1].mn >= 0 && node[1].mx >= 0) puts(">");
		else if (node[1].mn <= 0 && node[1].mx <= 0) puts("<");
		else puts("?");
	}
	
	return 0;
}
