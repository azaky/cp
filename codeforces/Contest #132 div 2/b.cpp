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
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
	#define GetTime int time_void = clock(); printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

inline int StringToInt(string s){
	int x;
	stringstream(s) >> x;
	return x;
}
inline string IntToString(int x){
	stringstream s;
	s << x;
	return s.str();
}

/* -------------- end of azaky's template -------------- */

#define MAXN 5555
int n,x[MAXN],r1,np1,np2;
double ans,r2,a,b,p1[MAXN],p2[MAXN];

int main(){
	cin >> n;
	for (int i=0; i<n; ++i) cin >> x[i];
	for (int i=0; i<n; ++i)
		if (x[i] > r1) r1 = x[i];
	cin >> np1;
	for (int i=0; i<np1; ++i) cin >> p1[i];
	cin >> np2;
	for (int i=0; i<np2; ++i) cin >> p2[i];
	cin >> a >> b;

	for (int i=0; i<np1; ++i) p1[i] = p1[i]*b;
	for (int i=0; i<np2; ++i) p2[i] = p2[i]*a;
	for (int i=0; i<np2; ++i)
		if (p2[i] < p2[0]) p2[0] = p2[i];
	for (int i=0; i<np1; ++i){
		r2 = sqrt(p1[i]*(double)(r1*r1)/(p2[0]+p1[i]));
		if (r2 > ans) ans = r2;
	}
	printf("%.17lf\n",ans);
	return 0;
}
