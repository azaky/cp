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

#define MAXN 200200
#define MAXK 333
#define INF 1000000000

int ntc, n, k, child[MAXN][30], par[MAXN];
int cot[MAXN], totalcot[MAXN];
int dp[MAXN][MAXK], memo[MAXN][MAXK];
vector<int> adj[MAXN];
char s[MAXN];

void dfs(int v) {
	totalcot[v] = cot[v];
	FORIT(it, adj[v]) {
		dfs(*it);
		totalcot[v] += totalcot[*it];
	}
}

int calc(int v, int k) {
	if (k == 0) {
		return 0;
	}
	if (k > totalcot[v]) {
		return INF;
	}
	if (memo[v][k]) {
		return dp[v][k];
	}
	memo[v][k] = 1;

	// no reason to not take anything from current node
	int oldk = k;
	k = max(0, k - cot[v]);
	int idp[k + 1], temp[k + 1];
	idp[0] = 0;
	FOR(i, 1, k) {
		idp[i] = INF;
	}
	if (SZ(adj[v]) > 1) {
		FORIT(it, adj[v]) {
			FOR(i, 0, k) {
				temp[i] = calc(*it, i);
			}
			FORD(i, k, 0) {
				FOR(j, 0, i) {
					MN(idp[i], idp[i - j] + temp[j]);
				}
			}
		}
	} else if (SZ(adj[v]) == 1) {
		idp[k] = calc(adj[v][0], k);
	}
	// printf("dp[%d][%d] = %d\n", v, oldk, 1 + idp[k]);
	return dp[v][oldk] = 1 + idp[k];
}

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &k);

		// clear everything
		RESET(child, -1);
		RESET(cot, 0);
		RESET(memo, 0);

		int nnode = 1;
		REP(is, n) {
			scanf("%s", s);
			int curnode = 0;
			int len = strlen(s);
			REP(i, len) {
				if (child[curnode][s[i] - 'a'] == -1) {
					// create new node
					adj[curnode].PB(nnode);
					par[nnode] = curnode;
					child[curnode][s[i] - 'a'] = nnode;
					// printf("node %d: %c par(%d)\n", nnode, s[i], curnode);
					nnode++;
				}
				curnode = child[curnode][s[i] - 'a'];
			}
			cot[curnode]++;
		}

		dfs(0);

		fprintf(stderr, "Case #%d: n = %d, k = %d, nnode = %d\n", itc, n, k, nnode);
		printf("Case #%d: %d\n", itc, (calc(0, k) - 1) * 2 + k);
		fprintf(stderr, "Case #%d: %d\n", itc, (calc(0, k) - 1) * 2 + k);

		REP(i, nnode) {
			adj[i].clear();
		} 
	}

	return 0;
}