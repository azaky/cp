#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <cassert>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime()	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back
#define LLD "%I64d"

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

/* -------------- end of azaky's template -------------- */

#define MAXN 200200
int n, m, pos[MAXN], ans[MAXN], BIT[MAXN];
vector <pair<int,pii> > q;

void add(int k){for (int x = k; x <= n; x += (x & -x)) ++BIT[x];}
int query(int k){int sum = 0; for (int x = k; x; x -= (x & -x)) sum += BIT[x]; return sum;}

int main(){
	scanf("%d%d",&n,&m);
	REP(i,n){
		int x;
		scanf("%d",&x);
		pos[x] = i+1;
	}
	for (int i=1; i <= n; ++i){
		for (int j=i; j <= n; j += i){
			q.PB(MP(-min(pos[i],pos[j]),MP(0,max(pos[i],pos[j]))));
		}
	}
	FOR(i,1,m){
		int x, y;
		scanf("%d%d",&x,&y);
		q.PB(MP(-x,MP(i,y)));
	}
	sort(ALL(q));
	REP(i,SZ(q)){
		int l = -q[i].A, r = q[i].B.B, t = q[i].B.A;
		if (!t){
//			printf("ADD [%d][%d]\n",l,r);
			add(r);
		}
		else{
//			printf("QUERY [%d][%d]\n",l,r);
			ans[t] = query(r)-query(l-1);
		}
	}
	FOR(i,1,m) printf("%d\n",ans[i]);
	
	return 0;
}
