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
	#define debug(...) fprintf(stderr, __VA_ARGS__)
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

#define sqr(x) ((x)*(x))

struct point{
	ll x, y;
	point() { x = y = 0; }
	point(ll x, ll y) : x(x), y(y) {}
};

/** basic operators and functions of point and segment **/
/* complexity: constant */
point operator-(const point &p1, const point &p2) {
	return point(p1.x - p2.x, p1.y - p2.y);
}
point operator+(const point &p1, const point &p2) {
	return point(p1.x + p2.x, p1.y + p2.y);
}
bool operator<(const point &p1, const point &p2) {
	if (p1.x != p2.x) return p1.x < p2.x;
	return p1.y < p2.y;
}
bool operator==(const point &p1, const point &p2) {
	return p1.x == p2.x && p1.y == p2.y;
}
ll cross(const point &p1, const point &p2) {
	/* returns z-component of cross product of two points (vectors) */
	return p1.x * p2.y - p1.y * p2.x;
}
ll dot(const point &p1, const point &p2) {
	/* returns dot product of two points (vectors) */
	return p1.x * p2.x + p1.y * p2.y;
}
bool isRightTurn(const point &p1, const point &p2, const point &p3){
	return cross(p2 - p1, p3 - p2) <= 0;
	/* straight returns true */
}

/** introducing polygon **/
typedef vector<point> polygon;

/** Check orientation of points: clockwise or counterclockwise **/
/* complexity : O(N) */
bool isClockwise(polygon p){
	ll area = p.front().y * p.back().x - p.front().x * p.back().y;
	for (int i = 0; i + 1 < (int)p.size(); ++i){
		area += p[i].x * p[i+1].y;
		area -= p[i].y * p[i+1].x;
	}
	return area < 0;
}

/** Convex Hull | monotone chain algorithm **/
/* complexity : O(N log N) */
polygon convexHull(polygon p){
	int m = 0, n = p.size();
	polygon hull(2*n);
	sort(p.begin(),p.end());
	for (int i = 0; i < n; ++i){
		while (m >= 2 && isRightTurn(hull[m-2],hull[m-1],p[i])) --m;
		hull[m++] = p[i];
	}
	for (int i = n-1, t = m+1; i >= 0; --i){
		while (m >= t && isRightTurn(hull[m-2],hull[m-1],p[i])) --m;
		hull[m++] = p[i];
	}
	hull.resize(m);
	return hull;
}


/* -------------- end of azaky's template -------------- */

ll INF = (ll)(0x7FFFFFFF) * (ll)(0x7FFFFFFF);
int n, q;

int main(){
	scanf("%d%d", &n, &q);
	polygon p;
	REP(i, n) {
		point _p;
		scanf("%lld%lld", &_p.x, &_p.y);
		//scanf("%I64d%I64d", &_p.x, &_p.y);
		p.PB(_p);
	}
	polygon hull = convexHull(p);
	//selects point in the bottom-left area
	polygon c;
	c.PB(hull[0]);
	FOR(i, 1, SZ(hull)-1) {
		if (hull[i].y > hull[i-1].y) break;
		c.PB(hull[i]);
	}
	n = SZ(c);
	REP(i, q) {
		point t;
		scanf("%lld%lld", &t.x, &t.y);
		//scanf("%I64d%I64d", &t.x, &t.y);
		//performs a ternary search
		int a = 0, b = n-1;
		while (a + 10 < b) {
			int lt = a + (b-a)/3;
			int rt = b - (b-a)/3;
			if (dot(t, c[lt]) > dot(t, c[rt])) {
				a = lt;
			}
			else {
				b = rt;
			}
		}
		ll ans = INF;
		FOR(j, a, b) {
			MN(ans, dot(t, c[j]));
		}
		printf("%lld\n", ans);
		//printf("%I64d\n", ans);
	}
	//GetTime();
	
	return 0;
}
