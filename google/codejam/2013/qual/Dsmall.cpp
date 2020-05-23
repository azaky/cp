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

const int MAXN = 21;
const int MAXK = 41;
int ntc, k, n, startkey[MAXK], door[MAXN], nkey[MAXN], visit[MAXN], keyhave[MAXK], prev[1 << MAXN], done[1 << MAXN];
vector<int> key[MAXN], ans;

int main(){
	map<int,int> power;
	REP(i,20) power[1<<i] = i;
	
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d%d",&k,&n);
		REP(i,k) scanf("%d",&startkey[i]);
		REP(i,n){
			scanf("%d%d",&door[i],&nkey[i]);
			key[i].clear();
			REP(j,nkey[i]){
				int t; scanf("%d",&t);
				key[i].pb(t);
			}
		}
		/* normalizing keys */
		map<int,bool> keyexist;
		REP(i,k) keyexist[startkey[i]] = true;
		REP(i,n) REP(j,(int)key[i].size()) keyexist[key[i][j]] = true;
		REP(i,n) keyexist[door[i]] = true;
		map<int,int> keyhash;
		int now = 0, cot = 0;
		FOR(i,1,200) if (EXIST(i,keyexist)) keyhash[i] = ++now, ++cot;
		REP(i,k) startkey[i] = keyhash[startkey[i]];
		REP(i,n) REP(j,(int)key[i].size()) key[i][j] = keyhash[key[i][j]];
		REP(i,n) door[i] = keyhash[door[i]];
		
		//printf("AFTER HASHING...\n");
		//REP(i,k) printf("%d ",startkey[i]); puts("");
		//REP(i,n){printf("%d %d ",door[i],nkey[i]); REP(j,nkey[i]) printf("%d ",key[i][j]); puts("");}
		
		RESET(done,0);
		queue<int> Q;
		Q.push(0);
		while (!Q.empty()){
			int s = Q.front(); Q.pop();
			//printf("QUEUE = %d\n",s);
			//REP(i,n) if (s & (1 << i)) printf("%d ",power[1 << i]+1); printf("\n");
			REP(i,n) visit[i] = (s & (1 << i)) ? 1 : 0;
			FOR(i,1,40) keyhave[i] = 0;
			REP(i,k) keyhave[startkey[i]]++;
			REP(i,n) if (visit[i]){
				keyhave[door[i]]--;
				REP(j,(int)key[i].size()) keyhave[key[i][j]]++;
			}
			FOR(i,1,40) assert(keyhave[i] >= 0);
			REP(i,n){
				if (visit[i]) continue;
				if (keyhave[door[i]] == 0) continue;
				if (done[s|(1<<i)]) continue;
				done[s|(1<<i)] = 1;
				prev[s|(1<<i)] = s;
				Q.push(s|(1<<i));
			}
		}
		printf("Case #%d:",itc);
		if (!done[(1<<n)-1]) printf(" IMPOSSIBLE\n");
		else {
			ans.clear();
			int s = (1<<n)-1;
			while (s != 0){
				ans.pb(power[s^prev[s]]);
				s = prev[s];
			}
			REPD(i,n) printf(" %d",ans[i]+1);
			printf("\n");
		}
	}
	
	return 0;
}
