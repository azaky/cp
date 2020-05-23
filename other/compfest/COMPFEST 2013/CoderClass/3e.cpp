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

//Geometry Template Beta
//Credit to ptrrsn_1
double _acos(double x) {
	double ret = acos(x);
	if (ret == ret) return ret;
	if (x < 0) return acos(-1.0);
	return acos(1.0);
}
#define acos _acos
#define sqr(x) ((x)*(x))

const double PI = 3.1415926535897932384626433832795028841971693993751058;
const double EPS = 1e-9;
const double INF = 1e300;

struct point{
	ll x, y;
	point() { x = y = 0; }
	point(ll x, ll y) : x(x), y(y) {}
	point operator-(const point &p) const {
		return point(x - p.x, y - p.y);
	}

};
struct segment {
	point p1, p2;
//	segment() {p1 = p2 = point(0,0);}
//	segment(point p1, point p2) : p1(p1), p2(p2) {}
};
/*
point operator-(const point &a, const point &b){
	point ret;
	ret.x = a.x - b.x; ret.y = a.y - b.y;
	return ret;
}
*/
ll cross(point p1,point p2){
	return p1.x * p2.y - p1.y * p2.x;
}
bool right(point p1,point p2,point p3){
	return cross(p2-p1,p3-p2)<=0;
}
bool sameside(point p1,point p2,segment s){
	ll z1 = cross(s.p2-s.p1,p1-s.p1);
	ll z2 = cross(s.p2-s.p1,p2-s.p1);
	assert(z1 != 0 && z2 != 0);
	return (z1 > 0 && z2 > 0) || (z1 < 0 && z2 < 0);
}
/* -------------- end of azaky's template -------------- */

ll zassert(bool expr){
	if (!expr){
//		printf("hoho\n");
		ll k = 0;
		FOR(i,1,1000000000) k += rand();
		return k;
	}
	return 0;
}

#define MAXN 100100

int ntc, n, nu, nd;
segment s;
point p[MAXN], up[MAXN], down[MAXN], d1[MAXN], d2[MAXN];

bool comp1(const point &a, const point &b){return right(a,s.p1,b);}
bool comp2(const point &a, const point &b){return right(a,s.p2,b);}

ll gcd(ll a, ll b){return a == 0 ? b : gcd(b % a, a);}

int main(){
	scanf("%d",&ntc);
	REP(itc,ntc){
		cin >> n >> s.p1.x >> s.p1.y >> s.p2.x >> s.p2.y;
//		scanf("%d%lld%lld%lld%lld",&n,&s.p1.x,&s.p1.y,&s.p2.x,&s.p2.y);
		REP(i,n) cin >> p[i].x >> p[i].y;
//		REP(i,n) scanf("%lld%lld",&p[i].x,&p[i].y);
		random_shuffle(p,p+n);
		up[0] = p[0];
		nu = 1; nd = 0;
		FOR(i,1,n-1) if (sameside(p[0],p[i],s)) up[nu++] = p[i]; else down[nd++] = p[i];
		if (nd == 0 ){
			puts("0/1");
			continue;
		}
		REP(i,nd) d1[i] = d2[i] = down[i];
		sort(d1,d1+nd,comp1); sort(d2,d2+nd,comp2);
//		puts("D1");
//		REP(i,nd) printf("(%I64d,%I64d)\n",d1[i].x,d1[i].y);
		ll ans = 0;
		continue;
		REP(i,nu){
			//cek keliatan semua apa kagak
			segment s1, s2;
			s1.p1 = s.p1; s1.p2 = up[i];
			s2.p1 = s.p2; s2.p2 = up[i];
			if (!sameside(d1[0],s.p2,s1) && !sameside(d1[nd-1],s.p2,s1)) continue;
			if (!sameside(d2[0],s.p1,s2) && !sameside(d2[nd-1],s.p1,s2)) continue;
			int ans1, ans2;
			//binary search p1
			if (right(up[i],s.p1,s.p2)){
				int l = 0, r = nd-1;
				while (l < r){
					int mid = (l+r+1)/2;
					if (sameside(d1[mid],s.p2,s1)) l = mid; else r = mid-1;
				}
				ans1 = nd - l - 1;
			}
			else {
				int l = 0, r = nd-1;
				while (l < r){
					int mid = (l+r)/2;
					if (sameside(d1[mid],s.p2,s1)) r = mid; else l = mid+1;
				}
				ans1 = l;
			}
			
			//binary search p2
			if (right(up[i],s.p2,s.p1)){
				int l = 0, r = nd-1;
				while (l < r){
					int mid = (l+r+1)/2;
					if (sameside(d2[mid],s.p1,s2)) l = mid; else r = mid-1;
				}
				ans2 = nd - l - 1;
			}
			else {
				int l = 0, r = nd-1;
				while (l < r){
					int mid = (l+r)/2;
					if (sameside(d2[mid],s.p1,s2)) r = mid; else l = mid+1;
				}
				ans2 = l;
			}
			ans += (ll)(nd - ans1 - ans2);
		}
//		printf("ans = %I64d\n",ans);
		ll total = (ll)n*((ll)n-1LL)/2LL;
		ll d = gcd(ans,total);
		cout << ans/d << "/" << total/d << endl;
	}
	
	return 0;
}
