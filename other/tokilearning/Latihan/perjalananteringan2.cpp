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

#define MAXN 1010
const int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int r, c, ra, ca, rb, cb, x[MAXN][MAXN], v[MAXN][MAXN];
queue<pii> q;

int can(int h){
	int rr, cc;
	pii now;
	REP(i,r) REP(j,c) v[i][j] = 0;
	while (!q.empty()) q.pop();
	q.push(MP(ra,ca)); v[ra][ca] = 1;
	while (!q.empty()){
		now = q.front(); q.pop();
		REP(d,4){
			rr = now.A+next[d][0]; cc = now.B+next[d][1];
			if (rr < 0 || cc < 0 || rr == r || cc == c) continue;
			if (v[rr][cc] || x[rr][cc] < 0 || x[rr][cc] > h) continue;
			v[rr][cc] = 1;
			q.push(MP(rr,cc));
		}
	}
	return v[rb][cb];
}

int main(){
	scanf("%d%d",&r,&c);
	REP(i,r) REP(j,c) scanf("%d",&x[i][j]);
	scanf("%d%d%d%d",&ra,&ca,&rb,&cb);
	--ra; --ca; --rb; --cb;
	x[ra][ca] = 0;
	int a = 0, b = 1000000, mid;
	while (a < b){
		mid = (a+b)/2;
		if (can(mid)) b = mid; else a = mid+1;
	}
	assert(a == b);
	printf("%d\n",a);
	
	return 0;
}
