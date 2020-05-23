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

int ntc, n, adj[30][30], used[30], v[30];
char w[11111][22];

void fill(int u, int tipe){
	if (v[u]) return;
	v[u] = tipe;
	if (tipe == 1) REP(i,26) if (adj[u][i]) fill(i,tipe);
	if (tipe == -1) REP(i,26) if (adj[i][u]) fill(i,tipe);
}
bool pre(int x, int y){
	if (x == y) return true;
	if (v[x]) return false;
	bool ret = false;
	REP(i,26) if (adj[x][i]) ret |= pre(i,y);
	return ret;
}

int main(){
	scanf("%d",&ntc);
	REP(itc,ntc){
		scanf("%d",&n);
		REP(i,n) scanf("%s",w[i]);
		REP(i,26) REP(j,26) adj[i][j] = 0;
		REP(i,26) used[i] = 0;
		REP(i,n){
			int len = strlen(w[i]);
			REP(j,len) used[w[i][j]-'a'] = 1;
		}
		int total = 0; REP(i,26) total += used[i];
		REP(i,n-1){
			int j = i+1, li = strlen(w[i]), lj = strlen(w[j]);
			for (int k = 0; k < li && k < lj; ++k){
				if (w[i][k] == w[j][k]) continue;
				adj[w[i][k]-'a'][w[j][k]-'a'] = 1;
				break;
			}
		}
/*
		REP(i,26) if (used[i]){
			printf("%c ",i+'a');
			REP(j,26) if (used[j]) printf("%d ",adj[i][j]);
			printf("\n");
		}
*/
		string ans;
		while (SZ(ans) < total){
//			REP(i,26) if (used[i]) printf("%c",i+'a');puts("");
			int next = -1;
			REP(k,26){
				if (!used[k]) continue;
				REP(i,26) v[i] = 0;
				v[k] = 0; fill(k,1);
				v[k] = 0; fill(k,-1);
				bool IsCut = true;
				REP(i,26) if (used[i] && i != k && v[i] == 0) IsCut = false;
				if (!IsCut) continue;
				if (next == -1) next = k;
				else{
					REP(i,26) v[i] = 0;
					if (pre(k,next)) next = k;
				}
			}
//			printf("NEXT = %d\n",next);
			if (next == -1){
				while (SZ(ans) < total) ans += '?';
				break;
			}
			REP(i,26) v[i] = 0;
			fill(next,-1);
			REP(i,26) if (v[i] == -1 && i != next){
				ans += '?';
				REP(j,26) adj[i][j] = adj[j][i] = 0;
				used[i] = 0;
			}
			ans += next + 'a';
			REP(i,26) adj[i][next] = adj[next][i] = 0;
			used[next] = 0;
//			printf("%s\n",ans.c_str());
		}
		printf("%s\n",ans.c_str());
	}
	return 0;
}
