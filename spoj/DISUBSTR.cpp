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

#define MAXN 1110
char s[MAXN], suffix[MAXN];
int ntc, n, ntrie, node[MAXN*MAXN][30], ans;

void insert(char *s, int k){
	int now = 0;
	FOR(i,k,n-1){
		if (node[now][s[i]-'A'] == -1){
			node[now][s[i]-'A'] = ++ntrie;
			RESET(node[ntrie],-1);
		}
		now = node[now][s[i]-'A'];
	}
}
void dfs(int v){
	if (v != 0) ans++;
	REP(i,26) if (node[v][i] != -1) dfs(node[v][i]);
}

int main(){
	scanf("%d",&ntc);
	while (ntc--){
		scanf("%s",s);
		n = strlen(s);
		ntrie = 0;
		RESET(node[0],-1);
		REP(i,n){
			insert(s,i);
		}
		ans = 0;
		dfs(0);
		printf("%d\n",ans);
	}
	
	return 0;
}
