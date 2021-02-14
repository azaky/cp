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

typedef pair<PII,PII> PI;
int random(int r){return rand()%r;}
int random(int l, int r){return rand()%(r-l+1)+l;}

const int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

#define MAXN 111
int n, m, k, a[MAXN][MAXN];
vector<PI> all, ans;
int V[MAXN][MAXN][10];

void tukar(PI x){swap(a[x.fi.fi][x.fi.se],a[x.se.fi][x.se.se]);}

int change(PI x){
	int r1 = x.fi.fi, c1 = x.fi.se, r2 = x.se.fi, c2 = x.se.se;
	int v1 = abs(a[r1][c1]-a[r1][c1-1])
	       + abs(a[r1][c1]-a[r1][c1+1])
	       + abs(a[r1-1][c1]-a[r1][c1])
	       + abs(a[r1+1][c1]-a[r1][c1])
	       + abs(a[r2][c2]-a[r2][c2-1])
	       + abs(a[r2][c2]-a[r2][c2+1])
	       + abs(a[r2-1][c2]-a[r2][c2])
	       + abs(a[r2+1][c2]-a[r2][c2]);
	int v2 = abs(a[r2][c2]-a[r1][c1-1])
	       + abs(a[r2][c2]-a[r1][c1+1])
	       + abs(a[r1-1][c1]-a[r2][c2])
	       + abs(a[r1+1][c1]-a[r2][c2])
	       + abs(a[r1][c1]-a[r2][c2-1])
	       + abs(a[r1][c1]-a[r2][c2+1])
	       + abs(a[r2-1][c2]-a[r1][c1])
	       + abs(a[r2+1][c2]-a[r1][c1])
	       + 2*abs(a[r1][c1]-a[r2][c2]);
	return v2-v1;
}

int main(){
	srand(time(NULL));
	
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
	
	priority_queue <pair<int,PI> > PQ;
	map <PI,int> MAP;
	
	/* Initialization */
	FOR(i,1,n) FOR(j,1,m){
		if (j < m){
			PI temp = mp(mp(i,j),mp(i,j+1));
			V[i][j][2] = change(temp);
			PQ.push(mp(-change(temp),temp));
			MAP[temp] = change(temp);
		}
		if (i < n){
			PI temp = mp(mp(i,j),mp(i+1,j));
			V[i][j][1] = change(temp);
			PQ.push(mp(-change(temp),temp));
			MAP[temp] = change(temp);
		}
	}
	
	int step;
	for(step = 0; step < k; ++step){
		/* modify MAP */
		if (step){
			int r = ans.back().fi.fi, c = ans.back().fi.se;
			FOR(i,r-3,r+2) FOR(j,c-3,c+2){
				if (i < 1 || i > n || j < 1 || j > m) continue;
				if (j < m){
					PI temp = mp(mp(i,j),mp(i,j+1));
					V[i][j][2] = change(temp);
					PQ.push(mp(-change(temp),temp));
					MAP[temp] = change(temp);
				}
				if (i < n){
					PI temp = mp(mp(i,j),mp(i+1,j));
					V[i][j][1] = change(temp);
					PQ.push(mp(-change(temp),temp));
					MAP[temp] = change(temp);
				}
			}
		}
		
		do {
			PI temp = PQ.top().se;
			int val = -PQ.top().fi;
			if (MAP[temp] == val) break; else PQ.pop();
		} while (true);
		
		if (PQ.top().fi <= 0) break;
		ans.pb(PQ.top().se);
		tukar(PQ.top().se);
		//printf("%d %d %d %d --> %d\n",ans[step].fi.fi,ans[step].fi.se,ans[step].se.fi,ans[step].se.se,s.begin()->fi);
	}
	printf("%d\n",step);
	REP(i,step){
		printf("%d %d %d %d\n",ans[i].fi.fi,ans[i].fi.se,ans[i].se.fi,ans[i].se.se);
	}
	
	return 0;
}
