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
int n, m, k, a[MAXN][MAXN], aa[MAXN][MAXN];
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

pair<int,vector<PI> > GetAns(int hasembuh){
	vector<PI> ans;
	int score = 0;
	
	/* Creating duplicates */
	FOR(i,1,n) FOR(j,1,m) a[i][j] = aa[i][j];
	
	/* Initialization */
	FOR(i,1,n) FOR(j,1,m){
		if (j < m){
			PI temp = mp(mp(i,j),mp(i,j+1));
			V[i][j][2] = change(temp);
		}
		if (i < n){
			PI temp = mp(mp(i,j),mp(i+1,j));
			V[i][j][1] = change(temp);
		}
	}
	
	REP(step,k){
		/* modify MAP */
		if (step){
			int r = ans.back().fi.fi, c = ans.back().fi.se;
			FOR(i,r-3,r+3) FOR(j,c-3,c+3){
				//printf("BOO [%d][%d]\n",i,j);
				if (i < 1 || i > n || j < 1 || j > m) continue;
				if (j < m){
					PI temp = mp(mp(i,j),mp(i,j+1));
					V[i][j][2] = change(temp);
				}
				if (i < n){
					PI temp = mp(mp(i,j),mp(i+1,j));
					V[i][j][1] = change(temp);
				}
			}
		}
		//printf("BOO\n");
		
		PI best = mp(mp(1,1),mp(1,2)), best2 = mp(mp(1,1),mp(2,1)), take;
		FOR(i,1,n) FOR(j,1,m){
			if (j < m){
				if (V[i][j][2] < V[best.fi.fi][best.fi.se][best.fi.fi == best.se.fi ? 2 : 1]) best = mp(mp(i,j),mp(i,j+1));
			}
			if (i < n){
				if (V[i][j][1] < V[best.fi.fi][best.fi.se][best.fi.fi == best.se.fi ? 2 : 1]) best = mp(mp(i,j),mp(i+1,j));
			}
		}
		//assert(best != mp(mp(1,1),mp(1,2)));
		FOR(i,1,n) FOR(j,1,m){
			if (j < m){
				if (V[i][j][2] < V[best2.fi.fi][best2.fi.se][best2.fi.fi == best2.se.fi ? 2 : 1] && best != mp(mp(i,j),mp(i,j+1))) best2 = mp(mp(i,j),mp(i,j+1));
			}
			if (i < n){
				if (V[i][j][1] < V[best2.fi.fi][best2.fi.se][best2.fi.fi == best2.se.fi ? 2 : 1] && best != mp(mp(i,j),mp(i+1,j))) best2 = mp(mp(i,j),mp(i+1,j));
			}
		}
		//assert(best != best2);
		
		//printf("%d %d %d %d --> %d\n",best.fi.fi,best.fi.se,best.se.fi,best.se.se,V[best.fi.fi][best.fi.se][best.fi.fi == best.se.fi ? 2 : 1]);
		
		if (random(1000) || hasembuh) take = best; else {
			int r = random(1,n-1), c = random(1,m-1);
			if (random(2)) take = mp(mp(r,c),mp(r,c+1)); else take = mp(mp(r,c),mp(r+1,c));
		}
		if (V[take.fi.fi][take.fi.se][take.fi.fi == take.se.fi ? 2 : 1] >= 0) break;
		ans.pb(take);
		tukar(take);
		score -= V[take.fi.fi][take.fi.se][take.fi.fi == take.se.fi ? 2 : 1];
		//printf("%d %d %d %d --> %d\n",ans[step].fi.fi,ans[step].fi.se,ans[step].se.fi,ans[step].se.se,s.begin()->fi);
	}
	return mp(score,ans);
}

int main(){
	srand(time(NULL));
	
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,1,n) FOR(j,1,m) scanf("%d",&aa[i][j]);
	
	int LIM = 50000000 / n / m / k;
	
	pair<int,vector<PI> > best = GetAns(1);
	REP(coba,LIM){
		pair<int,vector<PI> > temp = GetAns(0);
		if (temp.fi > best.fi) best = temp;
	}
	
	ans = best.se;
	
	int step = ans.size();
	printf("%d\n",step);
	REP(i,step){
		printf("%d %d %d %d\n",ans[i].fi.fi,ans[i].fi.se,ans[i].se.fi,ans[i].se.se);
	}
	
	return 0;
}
