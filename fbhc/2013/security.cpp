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
#include <cassert>
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

#define MAXN 111
int m, l, used[MAXN], p[MAXN];
vector<int> adj[MAXN];
string _a, _b, a[MAXN], b[MAXN], ans;
bool found;

bool comp(const int &x, const int &y){
	return b[x] < b[y];
}
bool match(string x, string y){
	REP(i,x.length()) if (x[i] != y[i] && x[i] != '?' && y[i] != '?') return false;
	return true;
}
string combine(string x, string y){
	string ret = x;
	REP(i,x.length()){
		if (x[i] == '?' && y[i] == '?') ret[i] = 'a';
		else if (x[i] == '?') ret[i] = y[i];
	}
	return ret;
}
void dfs(int k){
	if (found) return;
	if (k == m){
		REP(i,m) ans += combine(a[i],b[p[i]]);
		found = true;
		return;
	}
	int tried[MAXN];
	REP(i,m) tried[i] = 0;
	REP(i,adj[k].size()){
		if (i > 0){
			if (b[adj[k][i]] == b[adj[k][i-1]] && tried[i-1]){
				tried[i] = 1;
				continue;
			}
		}
		if (!used[adj[k][i]]){
			used[adj[k][i]] = 1;
			p[k] = adj[k][i];
			dfs(k+1);
			used[adj[k][i]] = 0;
			tried[i] = 1;
		}
	}
}

int main(){
	int ntc; scanf("%d",&ntc);
	FOR(itc,1,ntc){
		cin >> m >> _a >> _b;
		assert((int)_a.length() % m == 0);
		l = _a.length() / m;
		REP(i,m){
			a[i] = _a.substr(i*l,l);
			b[i] = _b.substr(i*l,l);
		}
		//REP(i,m) printf("[%s]",a[i].c_str()); puts("");
		REP(i,m) adj[i].clear();
		REP(i,m) REP(j,m){
			if (match(a[i],b[j])){
				adj[i].pb(j);
				//printf("%d -> %d\n",i,j);
			}
		}
		REP(i,m) sort(ALL(adj[i]),comp);
		RESET(used,0);
		
		ans = ""; found = false;
		dfs(0);
		if (!found) ans = "IMPOSSIBLE";
		
		cout << "Case #" << itc << ": " << ans << endl;
	}
	
	return 0;
}
