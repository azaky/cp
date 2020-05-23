/* DELAPAN.3gp */
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
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

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

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of DELAPAN.3gp's template -------------- */

#define MAXN 2020

int ntc, n, a[MAXN], b[MAXN], ans[MAXN], v[MAXN];
vector<int> adj[MAXN], f;

void dfs(int x){
	if (v[x]) return;
	v[x] = 1;
	FORIT(it,adj[x]) dfs(*it);
	f.PB(x);
}

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d",&n);
		REP(i,n) scanf("%d",&a[i]);
		REP(i,n) scanf("%d",&b[i]);
		/* adding inequalities */
		REP(i,n) adj[i].clear();
		/* adj[i][j] means X[i] < X[j] */
		REP(i,n){
			REP(j,n){
				if (i < j && a[i] >= a[j]) adj[j].PB(i);
				if (i < j && b[i] <= b[j]) adj[i].PB(j);
			}
			REPD(j,i){
				if (a[j] == a[i]-1){
					adj[j].PB(i);
					break;
				}
			}
			FOR(j,i+1,n-1){
				if (b[j] == b[i]-1){
					adj[j].PB(i);
					break;
				}
			}
		}
		/* topological sort */
		f.clear();
		RESET(v,0);
		REP(i,n) dfs(i);
		REP(i,n) ans[f[i]] = i;
		/* print the answer */
		printf("Case #%d:",itc);
		REP(i,n) printf(" %d",ans[i]);
		printf("\n");
	}
		
	
	return 0;
}
