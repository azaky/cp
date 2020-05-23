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
#include <limits>
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
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

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

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

int tc;
int w, h;
int n;
int xl[105], yl[105], xh[105], yh[105], vis[105];

pair<pair<int,int>, pair<int,int> > p[105];
pair<pair<int,int>, pair<int,int> > q[105];

int ans;

void work(int xa, int ya, int xb, int yb)
{
//	printf("xa = %d, ya = %d, xb = %d, yb = %d\n",xa,ya,xb,yb);
	// cut horizontally
	int cur_x = xa;
	int area = 0;
	priority_queue <pair<pii,pii> > pqx;
	REP(i,n){
		if ((xa <= xl[i] && xh[i] <= xb && ya <= yl[i] && yh[i] <= yb)){
			pqx.push(MP(MP(-xl[i],-xh[i]),MP(yl[i],yh[i])));
		}
	}
	while ((cur_x == xa || ((cur_x-xa) * (yb-ya) != area))/* && !pqx.empty()*/){
		pair<pii,pii> top = pqx.top(); pqx.pop();
		area += (-top.A.B + top.A.A) * (top.B.B - top.B.A);
		MX(cur_x,-top.A.B);
//		printf("cur_x = %d, area = %d\n",cur_x,area);
	}
//	printf("cur_x = %d\n",cur_x);
	if (cur_x != xb){
		work(xa,ya,cur_x,yb);
		work(cur_x,ya,xb,yb);
		return;
	}
	// cut vertically
	int cur_y = ya;
	area = 0;
	priority_queue <pair<pii,pii> > pqy;
	REP(i,n){
		if ((xa <= xl[i] && xh[i] <= xb && ya <= yl[i] && yh[i] <= yb)){
			pqy.push(MP(MP(-yl[i],-yh[i]),MP(xl[i],xh[i])));
		}
	}
	while ((cur_y == ya || ((cur_y-ya) * (xb-xa) != area))/* && !pqy.empty()*/){
		pair<pii,pii> top = pqy.top(); pqy.pop();
		area += (-top.A.B + top.A.A) * (top.B.B - top.B.A);
		MX(cur_y,-top.A.B);
//		printf("cur_y = %d, area = %d\n",cur_y,area);
	}
//	printf("cur_y = %d\n",cur_y);
	if (cur_y != yb){
		work(xa,ya,xb,cur_y);
		work(xa,cur_y,xb,yb);
		return;
	}
	MX(ans,(xb - xa) * (yb - ya));
}

int main(){
	scanf("%d", &tc);
	
	while (tc--)
	{
		scanf("%d %d", &w, &h);
		scanf("%d", &n);
		REP(i, n)
		{
			scanf("%d %d %d %d", &xl[i],&yl[i], &xh[i], &yh[i]);
			p[i] = MP( MP(xl[i], xh[i]), MP(yl[i], yh[i]));
			q[i] = MP( MP(yl[i], yh[i]), MP(xl[i], xh[i]));
		}
		sort(p, p+n);
		sort(q, q+n);
		ans = 0;
		work(0,0,w,h);
		printf("%d\n", ans);
	}
	
	
	return 0;
}
