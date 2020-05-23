/*
ID: a_zaky01
PROG: optics
LANG: C++
*/

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

#define INF 1000000001
#define MAXN 200200

typedef pii point;
#define x first
#define y second

int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
/** directions:
 * 0 : up
 * 1 : right
 * 2 : down
 * 3 : left
 */
int nextDir(int dir, char tipe) {
	if (tipe == '/') {
		switch (dir) {
			case 0: return 1;
			case 1: return 0;
			case 2: return 3;
			case 3: return 2;
			default: return -1;
		}
	}
	else if (tipe == '\\') {
		switch (dir) {
			case 0: return 3;
			case 1: return 2;
			case 2: return 1;
			case 3: return 0;
			default: return -1;
		}
	}
	else return -1;
}

int n;
point p[MAXN], b;
char tipe[MAXN];
int nextP[MAXN][4], idx[MAXN];
bool cmpx(int a, int b) {
	if (p[a].y != p[b].y) return p[a].y < p[b].y;
	return p[a].x < p[b].x;
}
bool cmpy(int a, int b) {
	if (p[a].x != p[b].x) return p[a].x < p[b].x;
	return p[a].y < p[b].y;
}

vector<point> liem, fong;

ll intersect(vector<point> liem, vector<point> fong) {
	
}

int main(){
	OPEN("optics");
	
	scanf("%d%d%d", &n, &b.x, &b.y);
	REP(i,n) {
		scanf("%d%d", &p[i].x, &p[i].y);
		tipe[i] = getchar();
		while (tipe[i] != '\\' && tipe[i] != '/') tipe[i] = getchar();
	}
	//p[n] == origin; p[n+1] == goal
	p[n] = MP(0, 0);
	p[n+1] = b;
	
	//get next in x
	REP(i, n+2) idx[i] = i;
	sort(idx, idx + n + 2, cmpx);
	REP(i, n+2) {
		//next left | 3
		if (i == 0) nextP[idx[i]][3] = -1;
		else if (p[idx[i-1]].y == p[idx[i]].y) nextP[idx[i]][3] = idx[i-1];
		else nextP[idx[i]][3] = -1;
		//next right | 1
		if (i == n+1) nextP[idx[i]][1] = -1;
		else if (p[idx[i+1]].y == p[idx[i]].y) nextP[idx[i]][1] = idx[i+1];
		else nextP[idx[i]][1] = -1;
	}
	//get next in y
	sort(idx, idx + n + 2, cmpy);
	REP(i, n+2) {
		//next down | 2
		if (i == 0) nextP[idx[i]][2] = -1;
		else if (p[idx[i-1]].x == p[idx[i]].x) nextP[idx[i]][2] = idx[i-1];
		else nextP[idx[i]][2] = -1;
		//next up | 0
		if (i == n+1) nextP[idx[i]][0] = -1;
		else if (p[idx[i+1]].x == p[idx[i]].x) nextP[idx[i]][0] = idx[i+1];
		else nextP[idx[i]][0] = -1;
	}
	
	ll ans = 0;
	
	//shot from origin
	int dir = 0;
	liem.PB(p[n]);
	int pos = nextP[n][0];
	if (pos != -1) dir = nextDir(dir, tipe[pos]);
	while (pos != -1) {
		liem.PB(p[pos]);
		pos = nextP[pos][dir];
		dir = nextDir(dir, tipe[pos]);
	}
	switch (dir) {
		case 0: liem.PB(MP(liem.back().x, INF)); break;
		case 1: liem.PB(MP(INF, liem.back().y)); break;
		case 2: liem.PB(MP(liem.back().x, -INF)); break;
		case 3: liem.PB(MP(-INF, liem.back().y)); break;
	}
	
	//shot from B for each direction
	bool done[4];
	REP(d, 4) done[d] = false;
	REP(d, 4) {
		if (done[d]) continue;
		
		int dir = d;
		fong.clear();
		fong.PB(p[n+1]);
		int pos = nextP[n+1][d];
		if (pos != -1) dir = nextDir(dir, tipe[pos]);
		while (pos != -1 && pos != n+1) {
			fong.PB(p[pos]);
			pos = nextP[pos][dir];
			dir = nextDir(dir, tipe[pos]);
		}
		if (pos == n+1) {
			fong.PB(p[pos]);
			done[(d+2)%4] = true;
		}
		else switch (dir) {
			case 0: fong.PB(MP(fong.back().x, INF)); break;
			case 1: fong.PB(MP(INF, fong.back().y)); break;
			case 2: fong.PB(MP(fong.back().x, -INF)); break;
			case 3: fong.PB(MP(-INF, fong.back().y)); break;
		}
		
		printf("DIR = %d\n", d);
		FORIT(it, fong) printf("(%d, %d)\n", it->x, it->y);
		
		ans += intersect(liem, fong);
	}
	
	return 0;
}

/* Generated by UsacoTemp v3.0 */
