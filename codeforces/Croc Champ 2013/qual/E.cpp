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
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

const int MAXN = 333333;
int n, len, t[MAXN], p[MAXN], pp[MAXN], vnow, found[MAXN];
string s[MAXN];
char w[MAXN], c[MAXN];
vector<int> adj[MAXN], padj[MAXN];

void build(int v, int par){
	if (v != 1){
		REP(i,(int)s[v].length()){
			p[++vnow] = par;
			c[vnow] = s[v][i];
			par = vnow;
		}
	}
	REP(i,(int)padj[v].size()) build(padj[v][i],par);
}

void search(int v, int k){
	if (w[k] == c[v]){
		if (k == len-2) found[v] = 1;
		REP(i,(int)adj[v].size()) search(adj[v][i],k+1);
	}
	else {
		if (t[k] > -1) search(v,t[k]);
		else REP(i,(int)adj[v].size()) search(adj[v][i],0);
	}
}

int main(){
	scanf("%d",&n);
	FOR(i,2,n) cin >> pp[i] >> s[i];
	scanf("%s",w);
	len = strlen(w);
	w[len++] = '?';
	
	// failure table
	{
		int pos = 2, cnd = 0;
		t[0] = -1; t[1] = 0;
		while (pos < len){
			if (w[pos-1] == w[cnd]) t[pos++] = ++cnd;
			else if (cnd > 0) cnd = t[cnd];
			else t[pos++] = 0;
		}
	}
	//REP(i,len) printf(" %c",w[i]); puts("");
	//REP(i,len) printf("%2d",t[i]); puts("");
	
	//build the tree
	FOR(i,2,n) padj[pp[i]].pb(i);
	vnow = 1;
	build(1,1);
	FOR(i,1,vnow) adj[p[i]].pb(i);
	//FOR(i,1,vnow) printf("%2d: [%2d][%c]\n",i,p[i],c[i]);
	
	//do the KMP
	search(1,0);
	int ans = 0;
	FOR(i,1,vnow) if (found[i]) ans++;
	printf("%d\n",ans);
	
	return 0;
}
