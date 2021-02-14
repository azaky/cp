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
#include <limits>
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

/* -------------- end of azaky's template -------------- */

#define MAXN 100100

struct node{
	int l, r;
} trie[40*MAXN];

int ntc, n, a[MAXN], nt;
vector<pii> adj[MAXN];

void dfs(int v, int par, int val){
	FORIT(it,adj[v]){
		if (it->A != par){
			dfs(it->A, v, val ^ it->B);
		}
	}
	a[nt++] = val;
}

int main(){
	scanf("%d",&ntc);
	while (ntc--){
		scanf("%d",&n);
		REP(i,n) adj[i].clear();
		REP(i,n-1){
			int u, v, w;
			scanf("%d%d%d",&u,&v,&w);
			u--; v--;
			adj[u].PB(MP(v,w));
			adj[v].PB(MP(u,w));
		}
		nt = 0;
		dfs(0,-1,0);
		//create trie
		int ntrie = 0;
		trie[ntrie].l = trie[ntrie].r = -1;
		REP(i,nt){
			int now = 0;
			REPD(j,32){
				if (a[i] & (1 << j)){
					/* creates right subtree */
					if (trie[now].r != -1) now = trie[now].r;
					else {
						++ntrie;
						trie[now].r = ntrie;
						trie[ntrie].l = trie[ntrie].r = -1;
						now = ntrie;
					}
				}
				else {
					/* creates left subree */
					if (trie[now].l != -1) now = trie[now].l;
					else {
						++ntrie;
						trie[now].l = ntrie;
						trie[ntrie].l = trie[ntrie].r = -1;
						now = ntrie;
					}
				}
			}
		}
		//do queries
		int ans = 0;
		REP(i,nt){
			int now = 0, v = 0;
			REPD(j,32){
				if (a[i] & (1 << j)){
					/* find left subtree */
					if (trie[now].l != -1){
						now = trie[now].l;
						v ^= (1 << j);
					}
					else {
//						assert(trie[now].r != -1);
						now = trie[now].r;
					}
				}
				else {
					/* find right subtree */
					if (trie[now].r != -1){
						now = trie[now].r;
						v ^= (1 << j);
					}
					else {
//						assert(trie[now].l != -1);
						now = trie[now].l;
					}
				}
			}
			MX(ans,v);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
