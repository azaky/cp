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

int ntc, n, m, a[111][111];

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d%d",&n,&m);
		FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
		priority_queue <pair<int,PII> > pq;
		FOR(i,1,n) FOR(j,1,m) pq.push(mp(-a[i][j],mp(i,j)));
		set<PII> row[111],col[111];
		FOR(i,1,n) FOR(j,1,m){
			row[i].insert(mp(-a[i][j],j));
			col[j].insert(mp(-a[i][j],i));
		}
		bool possible = true;
		while (!pq.empty()){
			int v = -pq.top().fi;
			PII pos = pq.top().se;
			pq.pop();
			
			//printf("NOW V = %d AT [%d][%d]\n",v,pos.fi,pos.se);
			
			if (-v != (*row[pos.fi].begin()).fi && -v != (*col[pos.se].begin()).fi){
				possible = false;
				break;
			}
			assert(EXIST(mp(-v,pos.se),row[pos.fi]) && EXIST(mp(-v,pos.fi),col[pos.se]));
			row[pos.fi].erase(mp(-v,pos.se));
			col[pos.se].erase(mp(-v,pos.fi));
		}
		printf("Case #%d: %s\n",itc,possible ? "YES" : "NO");
	}
	
	return 0;
}
