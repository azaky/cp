#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
	#define GetTime()	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
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

#define MAXN 1000
const int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int r, c, ans;
char peta[MAXN][MAXN];

bool inside(int rn, int cn){
	return (0 <= rn && rn < r && 0 <= cn && cn < c);
}
void go(int rn, int cn, int dir, int nyan){
	//langkah sekali
	rn += next[dir][0];
	cn += next[dir][1];
	if (!inside(rn,cn)) return;
	if (peta[rn][cn] == 'R') return;
	//mau tanam nyan
	int rp = rn + next[dir][0];
	int cp = cn + next[dir][1];
	if (!inside(rp,cp)) return;
	if (peta[rp][cp] == 'R') return;
	//tanam nyan
	peta[rp][cp] = 'R';
/*
	printf("peta after [%d][%d][%d]\n",rn,cn,dir);
	REP(i,r) printf("%s\n",peta[i]);
	printf("-----------------------\n");
*/
	++nyan;
	MX(ans,nyan);
	//jalan lagi
	go(rn,cn,(dir+1)%4,nyan);
	go(rn,cn,(dir+3)%4,nyan);
	//cabut nyan
	peta[rp][cp] = '.';
}
int main(){
	scanf("%d%d",&r,&c);
	REP(i,r) scanf("%s",peta[i]);
	ans = 0;
	int nk = 0;
	REP(i,r) REP(j,c) if (peta[i][j] == 'K'){
		REP(dir,4) go(i,j,dir,0);
		nk ++;
	}
	assert(nk == 1);
	printf("%d\n",ans);
	return 0;
}
