#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
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

#define INF 1000000000
#define MAXN 111

int ntc, n, m, z, p[MAXN], v[MAXN];
vector<int> adj[MAXN];

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d%d%d",&n,&m,&z);
		z--;
		REP(i,n){
			adj[i].clear();
			p[i] = i != z ? INF : 0;
			v[i] = 0;
		}
		REP(i,m){
			int x, y;
			scanf("%d%d",&x,&y);
			x--; y--;
			adj[x].PB(y); adj[y].PB(x);
		}
		while(true){
			int now = -1;
			REP(i,n) if (!v[i] && p[i] != INF){
				if (now == -1) now = i;
				else if (p[i] < p[now]) now = i;
			}
			if (now == -1) break;
			v[now] = 1;
			FORIT(it,adj[now]) MN(p[*it],p[now]+1);
		}
		printf("%d\n",1+*max_element(p,p+n));
	}
	
	return 0;
}
