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

/* -------------- end of azaky's template -------------- */

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
	double x, y;
	point() { x = y = 0; }
	point(double x, double y) : x(x), y(y) {}
	point operator-(const point &p) const {
		return point(x - p.x, y - p.y);
	}
	point operator+(const point &p) const {
		return point(x + p.x, y + p.y);
	}
	bool operator<(const point &p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	double cross(const point &p) {
		return x * p.y - y * p.x;
	}
	double dot(const point &p) {
		return x * p.x + y * p.y;
	}
	double getAngle(const point &p) {
		return fabs(acos(this->dot(p) / this->distance(point(0,0)) / p.distance(point(0,0))));
	}
	double distance(const point &p) const {
		return sqrt(sqr(x - p.x) + sqr(y - p.y));
	}
	double distanceToSegment(const point &p1, const point &p2) {
		double alpha;
		alpha = (p2 - p1).getAngle(*this - p1);
		if (alpha > PI/2 + EPS) return min(this->distance(p1), this->distance(p2));
		alpha = (p1 - p2).getAngle(*this - p2);
		if (alpha > PI/2 + EPS) return min(this->distance(p1), this->distance(p2));
		return fabs((p1 - *this).cross(p2 - *this)) / p1.distance(p2);
	}
	point rotate(const double &alpha) {
		return point(x * cos(alpha) - y * sin(alpha), x * sin(alpha) + y * cos(alpha));
	}
	point rescale(const double s) {
		return point(x * s / this->distance(point(0,0)), y * s / this->distance(point(0,0)));
	}
};
struct circle {
	point center;
	double r;
	circle() {
		center = point(0, 0);
		r = 0;
	}
	circle(point p, double r) : center(p), r(r) {}
};
struct segment {
	point p1, p2;
	segment() {p1 = p2 = point(0,0);}
	segment(point p1, point p2) : p1(p1), p2(p2) {}
	double length(){
		return p1.distance(p2);
	}
};
/*
double distance(point p1,point p2){
	return p1.distance(p2);
}
double distance(point p,segment s){
	return p.distanceToSegment(s.p1,s.p2);
}
*/
double angle(point p1,point o,point p2){
	return (p1-o).getAngle(p2-o);
}
point rotate(point p,point o,double Theta){
	return (p-o).rotate(Theta)+o;
}
point rotate(point p,double Theta){
	return p.rotate(Theta);
}
point dilate(point p,point o,double Factor){
	return (p-o).rescale(Factor)+o;
}
point dilate(point p,double Factor){
	return p.rescale(Factor);
}
double cross(point p1,point p2){
	return p1.cross(p2);
}
bool right(point p1,point p2,point p3){
	return cross(p2-p1,p3-p2)<=0;
}
bool sameside(point p1,point p2,segment s){
	double z1 = cross(s.p2-s.p1,p1-s.p1);
	double z2 = cross(s.p2-s.p1,p2-s.p1);
	return (z1*z2>=0) || fabs(z1)<EPS || fabs(z2)<EPS;
}
bool online(point p,segment s){
	return fabs((s.p1.y-p.y)*(s.p2.x-p.x)-(s.p2.y-p.y)*(s.p1.x-p.x))<EPS;
}
bool onsegment(point p,segment s){
	return fabs(p.distance(s.p1)+p.distance(s.p2)-s.length())<EPS;
}
bool intersect(segment s1,segment s2){
	return !(sameside(s1.p1,s1.p2,s2) || sameside(s2.p1,s2.p2,s1)) || onsegment(s1.p1,s2) || onsegment(s1.p2,s2) || onsegment(s2.p1,s1) || onsegment(s2.p2,s1);
}
bool parallel(segment s1,segment s2){
	return fabs((s1.p1.y-s1.p2.y)*(s2.p1.x-s2.p2.x)-(s2.p1.y-s2.p2.y)*(s1.p1.x-s1.p2.x))<EPS;
}
point intersectpoint(segment s1,segment s2){
	if (parallel(s1,s2)) return point(INF,INF);
    double a1 = s1.p2.x-s1.p1.x;
    double b1 = s2.p1.x-s2.p2.x;
    double c1 = s2.p1.x-s1.p1.x;
    double a2 = s1.p2.y-s1.p1.y;
    double b2 = s2.p1.y-s2.p2.y;
    double c2 = s2.p1.y-s1.p1.y;
    double i = (c1*b2-c2*b1)/(a1*b2-a2*b1);
	return point(s1.p1.x+a1*i,s1.p1.y+a2*i);
}

//end of geometry template

void BacaPoint(point &a){
	scanf("%lf%lf",&a.x,&a.y);
}
bool IsOrigin(point a){
	return a.x == 0 && a.y == 0;
}

int main(){
	point a, b, c, d, e, f;
	BacaPoint(a);
	BacaPoint(b);
	BacaPoint(c);
	BacaPoint(d);
	BacaPoint(e);
	BacaPoint(f);
	if (IsOrigin(a) && IsOrigin(b) && IsOrigin(c) && IsOrigin(d) && IsOrigin(e) && IsOrigin(f)) return 0;
	
	db area = d.distance(e)*d.distance(f)*sin(angle(e,d,f));
	if (area < 0.) area *= -1.;
	area /= 2.;
	db ah = area / a.distance(b) / sin(angle(b,a,c));
	if (ah < 0.) ah *= -1.;
	db dac = a.distance(c);
	point ac = c-a;
	point h = point(ah * ac.x / dac, ah * ac.y / dac);
	h = h + a;
	point g = b + h - a;
	printf("%.3lf %.3lf %.3lf %.3lf\n",g.x,g.y,h.x,h.y);
	
	main();
	
	return 0;
}
