#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

double _acos(double x) {
	double ret = acos(x);
	if (ret == ret) return ret;
	if (x < 0) return acos(-1.0);
	return acos(1.0);
}
#define acos _acos
#define sqr(x) ((x)*(x))

const double PI = acos(-1);
const double EPS = 1e-9;
const double INF = 1e300;

struct point{
	double x, y;
	point() { x = y = 0; }
	point(double x, double y) : x(x), y(y) {}
};
struct circle {
	point center;
	double r;
	circle() { center = point(0, 0); r = 0; }
	circle(point p, double r) : center(p), r(r) {}
};
struct segment {
	point p1, p2;
	segment() {p1 = p2 = point(0,0);}
	segment(point p1, point p2) : p1(p1), p2(p2) {}
};
typedef vector<point> polygon;

/** basic operators and functions **/
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
	return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS;
}
double cross(const point &p1, const point &p2) {
	return p1.x * p2.y - p1.y * p2.x;
}
double dot(const point &p1, const point &p2) {
	return p1.x * p2.x + p1.y * p2.y;
}
double dist(const point &p1, const point &p2) {
	return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}
double length(const segment &s) {
	return sqrt(sqr(s.p1.x - s.p2.x) + sqr(s.p1.y - s.p2.y));
}
double getAngle(const point &p1, const point &p2) {
	return fabs(acos(dot(p1,p2) / dist(p1,point(0,0)) / dist(p2,point(0,0))));
}
double getAngle(const point &p1, const point &center, const point &p2) {
	return getAngle(p1 - center, p2 - center);
}
double distToSegment(const point &p, const segment &s) {
	if (getAngle(s.p2, s.p1, p) > PI/2 + EPS || getAngle(s.p1, s.p2, p) > PI/2 + EPS) return min(dist(p,s.p1), dist(p,s.p2));
	return fabs(cross(s.p1 - p, s.p2 - p)) / dist(s.p1, s.p2);
}
double distToLine(const point &p, const segment &s){
	return fabs(cross(s.p1 - p, s.p2 - p)) / dist(s.p1, s.p2);
}
point rotate(const point &p, const double &alpha) {
	return point(p.x * cos(alpha) - p.y * sin(alpha), p.x * sin(alpha) + p.y * cos(alpha));
}
point rotate(const point &p, const point &center, const double &alpha){
	return center + rotate(p - center, alpha);
}
point rescale(const point &p, const double s) {
	return point(p.x * s, p.y * s);
}
point dilate(const point &p, const double Factor){
	return rescale(p, Factor);
}
point dilate(const point &p, const point &center, double factor){
	return dilate(p- center, factor) + center;
}
bool isRightTurn(const point &p1, const point &p2, const point &p3){
	return cross(p2 - p1, p3 - <= 0;
	/* straight returns true */
}
bool isOnSameSide(const point &p1, const point &p2, const segment &s){
	double z1 = cross(s.p2 - s.p1, p1 - s.p1);
	double z2 = cross(s.p2 - s.p1, p2 - s.p1);
	return (z1 + EPS < 0 && z2 + EPS < 0) || (0 < z1 - EPS && 0 < z2 - EPS);
	/* on segment returns false */
}
bool isOnLine(const point &p, const segment &s){
	return fabs((s.p1.y - p.y) * (s.p2.x - p.x) - (s.p2.y - p.y) * (s.p1.x - p.x)) < EPS;
}
bool isOnSegment(const point &p, const segment &s){
	return fabs(dist(p, s.p1) + dist(p, s.p2) - dist(s.p1, s.p2)) < EPS;
}
bool isIntersecting(const segment &s1, const segment &s2){
	return !(isOnSameSide(s1.p1,s1.p2,s2) || isOnSameSide(s2.p1,s2.p2,s1)) || isOnSegment(s1.p1,s2) || isOnSegment(s1.p2,s2) || isOnSegment(s2.p1,s1) || isOnSegment(s2.p2,s1);
}
bool isParallel(const segment &s1, const segment &s2){
	return fabs((s1.p1.y-s1.p2.y)*(s2.p1.x-s2.p2.x)-(s2.p1.y-s2.p2.y)*(s1.p1.x-s1.p2.x)) < EPS;
}
point intersection(const segment &s1, const segment &s2){
	/* assumes !isParallel(s1,s2) */
	double x1 = s1.p1.x - s1.p2.x;
	double x2 = s2.p1.x - s2.p2.x;
	double y1 = s1.p1.y - s1.p2.y;
	double y2 = s2.p1.y - s2.p2.y;
	double cross1 = cross(s1.p1, s1.p2);
	double cross2 = cross(s2.p1, s2.p2);
	return point ((cross1 * x2 - cross2 * x1) / (x1 * y2 - x2 * y1), (cross1 * y2 - cross2 * x1) / (x1 * y2 - x2 * y1));
}

/** Area of Polygon **/
/* complexity : O(N) */
double polygonArea(polygon p){
	double area = p.front().y * p.back().x - p.front().x * p.back().y;
	for (int i = 0; i + 1 < (int)p.size(); ++i){
		area += p[i].x * p[i+1].y;
		area -= p[i].y * p[i+1].x;
	}
	return fabs(area) / 2.;
}

/** Check order of points: clockwise or counterclockwise **/
/* complexity : O(N) */
bool isClockwise(polygon p){
	double area = p.front().y * p.back().x - p.front().x * p.back().y;
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

int main(){
	string line;
	while (getline(cin,line)){
		polygon q;
		double x, y;
		stringstream s (line);
		char ch;
		while (s >> ch >> x >> ch >> y >> ch){
			q.push_back(point(x,y));
		}
		polygon p = convexHull(q);
		for(int i = 0; i+1 < (int)p.size(); ++i) printf("(%g,%g) ",p[i].x,p[i].y);
		printf("(%g,%g)\n",p.back().x,p.back().y);
	}
	
	return 0;
}
