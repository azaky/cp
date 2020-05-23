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

#define MAXS 100001
struct Node{int l,r,p;} node[4*MAXS];
int ntc, k, a[MAXS+1], n, v, pos, ans, t;
char s[100], dummy;

void build(int v, int l, int r){
	node[v].l = l; node[v].r = r; node[v].p = l;
	if (l == r) return;
	build(2*v,l,(l+r)/2); build(2*v+1,(l+r+2)/2,r);
}
int query(int v, int k){
	if (node[v].l == node[v].r) return node[v].l;
	if (a[node[2*v].p] >= k) return query(2*v,k); else return query(2*v+1,k);
}
void update(int v, int pos, int k){
	if (node[v].r < pos || pos < node[v].l || node[v].l == node[v].r) return;
	update(2*v,pos,k); update(2*v+1,pos,k);
	node[v].p = a[node[2*v].p] >= a[node[2*v+1].p] ? node[2*v].p : node[2*v+1].p;
}

int main(){
	scanf("%d",&ntc);
	while (ntc--){
		scanf("%d",&k);
		FOR(i,1,MAXS) a[i] = k;
		build(1,1,MAXS);
		scanf("%d",&n);
		REP(i,n){
			scanf("\n%[^\n]",s);
			if (s[0] != 'b'){
				sscanf(s,"%d",&v);
				pos = query(1,v);
				a[pos] -= v;
				update(1,pos,v);
			}
			else {
				sscanf(s,"%c %d %d",&dummy,&t,&v);
				REP(j,t){
					pos = query(1,v);
					a[pos] -= v;
					update(1,pos,v);
				}
				i += t-1;
			}
		}
		ans = 0;
		FOR(i,1,MAXS){
			if (a[i] == k){
				printf("%d %d\n",i-1,ans);
				break;
			}
			ans += a[i];
		}
	}
	
	return 0;
}
