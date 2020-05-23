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

const double PI = acos(-1);

double solve(double w, double h, double a){
	if (a > PI/2) return solve(w,h,PI-a);
	if (w < h) return solve(h,w,a);
	double crangle = 2 * atan(h/w);
	if (a < crangle){
		double s = (w/2.) - (h*tan(a/2.)/2.);
		double t = (h/2.) - (w*tan(a/2.)/2.);
		return w*h - tan(a)*(s*s + t*t);
	}
	else {
		double s = (w/2.) - (h*tan(a/2.)/2.);
		double t = (w/2.) - (h/tan(a/2.)/2.);
		return w*h - (s+t)*h;
	}
}

int main(){
	double w, h, alpha;
	
	scanf("%lf%lf%lf",&w,&h,&alpha);
	//printf("%.15lf\n",solve(w,h,alpha*PI/180.));
	
	puts("JAWABAN ORANG");
	double th = alpha;
	if (th > 90) th = 180 - th;
	th = th / 180*PI;
	double a = 1 + 1/cos(th), b = 1.0;
	double aa = tan(th), bb = 1/tan(th)+1/sin(th);
	double y = (w*aa-h*a)/(aa*b-bb*a),x = (w-b*y)/a;
	double ans = w*h - x*x*tan(th)-y*y*tan(th);
	printf("%.15lf\n",ans);
	
	return 0;
}
