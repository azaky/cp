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
#define sqr(x) ((x)*(x))

struct point{
	ll x, y;
	point() { x = y = 0; }
	point(ll x, ll y) : x(x), y(y) {}
};
struct segment {
	point p1, p2;
	segment() {p1 = p2 = point(0,0);}
	segment(point p1, point p2) : p1(p1), p2(p2) {}
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

ll triangleArea(point a, point b, point c) {
	ll area = (a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x);
	if (area < 0) {
		return -area;
	} else {
		return area;
	}
}
bool isRightTurn(const point &p1, const point &p2, const point &p3){
	return cross(p2 - p1, p3 - p2) <= 0;
	/* straight returns true */
}
vector<point> convexHull(vector<point> p){
	int m = 0, n = p.size();
	vector<point> hull(2*n);
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

int ntc, n, m;

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		vector<point> p, q;
		REP(i, n) {
			point temp;
			scanf("%lld%lld", &temp.x, &temp.y);
			p.PB(temp);
		}
		scanf("%d", &m);
		REP(i, m) {
			point temp;
			scanf("%lld%lld", &temp.x, &temp.y);
			q.PB(temp);
		}
		q = convexHull(q);
		m = SZ(q);
		printf("sizeq = %d\n", m);
		FORIT(it, q) {
			printf("(%lld, %lld)\n", it->x, it->y);
		}
		int a = 0, b = 1;
		// make sure q is in the left side
		ll area = 0;
		ll ans = 0;
		while (a < n) {
			while (true) {
				int prevb = b;
				b++; b %= n;
				area += triangleArea(p[a], p[b], p[prevb]);
				bool allLeft = true;
				for (int i = 0; i < m; ++i) {
					if (cross(p[a] - q[i], p[b] - p[a]) <= 0) {
						allLeft = false;
						break;
					}
				}
				if (!allLeft) {
					break;
				}
			}
			int prevb = b;
			b = (b + n - 1) % n;
			area -= triangleArea(p[a], p[b], p[prevb]);
			MX(ans, area);
			int preva = a;
			a++;
			area -= triangleArea(p[a], p[preva], p[b]);
		}
		// ll ans2 = ans / 2LL;
		// ll dddd = (ans & 1) * 50LL;
		// printf("%lld.%02lld\n", ans2, dddd);
		printf("%.2lf\n", (double)ans / 2.);
	}
	
	return 0;
}
