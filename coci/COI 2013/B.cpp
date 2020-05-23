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

const int MAXN = 30;
const int MAXE = 1000;
int r, c, a[MAXN][MAXN];
PII pos[MAXE];
vector<PII> ans;

void turn(int r0, int c0){
	assert(r0 < r && c0 < c);
	ans.pb(mp(r0,c0));
	int temp = a[r0][c0];
	a[r0][c0] = a[r0+1][c0]; pos[a[r0][c0]] = mp(r0,c0);
	a[r0+1][c0] = a[r0+1][c0+1]; pos[a[r0+1][c0]] = mp(r0+1,c0);
	a[r0+1][c0+1] = a[r0][c0+1]; pos[a[r0+1][c0+1]] = mp(r0+1,c0+1);
	a[r0][c0+1] = temp; pos[a[r0][c0+1]] = mp(r0,c0+1);
	//printf("=== MOVE: [%d][%d] ===\n",r0,c0);FOR(i,1,r){FOR(j,1,c) printf("%d ",a[i][j]); printf("\n");}
}
void move(int r1, int c1, int r2, int c2){
	if (r1 == r2 && c1 == c2) return;
	if (r1 == r2){
		turn(r1,c1-1);
		r1++;
	}
	if (c1 > c2){
		while (c1 != c2){
			turn(r1-1,c1-1);
			c1--;
		}
	}
	if (c1 < c2){
		if (r1 == r){
			turn(r1-1,c1);
			r1--;
		}
		while (c1 != c2){
			turn(r1,c1);
			c1++;
		}
	}
	while (r1 != r2){
		turn(r1-1,c1);
		r1--;
	}
}


int main(){
	scanf("%d%d",&r,&c);
	FOR(i,1,r) FOR(j,1,c) scanf("%d",&a[i][j]);
	FOR(i,1,r) FOR(j,1,c) pos[a[i][j]] = mp(i,j);
	
	FOR(i,1,r-2){
		FOR(j,1,c-1) move(pos[(i-1)*c+j].fi,pos[(i-1)*c+j].se,i,j);
		if (pos[i*c] == mp(i,c)) continue;
		move(pos[i*c].fi,pos[i*c].se,i+1,c-1);
		turn(i+1,c-1);
		turn(i,c-1);
		turn(i+1,c-1);
		turn(i,c-1);
		turn(i,c-1);
		turn(i,c-1);
	}
	//last two rows
	FOR(j,1,c-2){
		move(pos[(r-2)*c+j].fi,pos[(r-2)*c+j].se,r-1,j);
		if (pos[(r-1)*c+j] == mp(r,j)) continue;
		move(pos[(r-1)*c+j].fi,pos[(r-1)*c+j].se,r-1,j+1);
		turn(r-1,j+1);
		turn(r-1,j);
		turn(r-1,j+1);
		turn(r-1,j+1);
		turn(r-1,j+1);
		turn(r-1,j);
		turn(r-1,j);
	}
	while (a[r][c] != r*c) turn(r-1,c-1);
	
	if (a[r-1][c-1] != (r-2)*c+c-1 || a[r-1][c] != (r-2)*c+c || a[r][c-1] != (r-1)*c+c-1){
		map<vector<int>,vector<PII> > MAP;
		now = 
		
	
	REP(i,(int)ans.size()) printf("%d %d\n",ans[i].fi,ans[i].se);
	
	return 0;
}
