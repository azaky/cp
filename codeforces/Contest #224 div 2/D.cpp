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

#define MAXN 2020
char s[MAXN], board[MAXN][MAXN];
int n, m, visited[MAXN][MAXN], realans, d[MAXN][MAXN];

vector<pii> adj[MAXN][MAXN];

vector<int> ans;

queue<pii> q;

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) {
		scanf("%s",s);
		FOR(j,1,m) board[i][j] = s[j-1];
	}
	
	FOR(i,1,n) FOR(j,1,m) {
		if (board[i][j-1] == '>') adj[i][j].PB(MP(i,j-1));
		if (board[i][j+1] == '<') adj[i][j].PB(MP(i,j+1));
		if (board[i-1][j] == 'v') adj[i][j].PB(MP(i-1,j));
		if (board[i+1][j] == '^') adj[i][j].PB(MP(i+1,j));
	}
	
	FOR(i,1,n) FOR(j,1,m) {
		if (visited[i][j]) continue;
		
		if (board[i][j] != '#') continue;
		
		visited[i][j] = 1;
		
		FORIT(x, adj[i][j]) {
			while (!q.empty()) q.pop();
			
			q.push(MP(x->A,x->B));
			d[x->A][x->B] = 0;
			int last = 0;
			
			while (!q.empty()) {
				pii now = q.front(); q.pop();
				visited[now.A][now.B] = 1;
				last = d[now.A][now.B];
				
				FORIT(it,adj[now.A][now.B]) {
					if (visited[it->A][it->B]) {
						puts("-1");
						return 0;
					}
					q.push(MP(it->A,it->B));
					d[it->A][it->B] = last + 1;
				}
			}
			
			ans.PB(last + 1);
		}
	}
	
	FOR(i,1,n) FOR(j,1,m) {
		if (!visited[i][j]) {
			puts("-1");
			return 0;
		}
	}
	
	sort(ALL(ans));
	reverse(ALL(ans));
	
	if (SZ(ans) == 0) {
		realans = 0;
	}
	else if (SZ(ans) == 1) {
		realans = max (0, ans[0] + ans[0] - 1);
	}
	else {
		realans = ans[0] + max(ans[0] - 1, ans[1]);
	}
	
	printf("%d\n",realans);
	
	return 0;
}
