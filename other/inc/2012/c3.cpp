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

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	int time_void;
	#define GetTime time_void = clock();\
	printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
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

struct point{
	long long x;
	long long y;
};
bool cmp(const point &a, const point &b){
	return a.x*b.y < a.y*b.x;
}

int tc,n,hitall,ans,shot[2222];
point p[2222];
long long r;

bool hit(int i, int j){
	long long a = p[i].y;
	long long b = -p[i].x;
	long long lhs = a*p[j].x + b*p[j].y; lhs = lhs*lhs;
	long long rhs = (a*a + b*b)*(r*r);
	return lhs <= rhs;
}

int main(){
	cin >> tc;
	for (int _tc = 1; _tc <= tc; ++_tc){
		memset(shot,0,sizeof(shot));
		ans = 0;
		
		cin >> n >> r;
		for (int i=0; i<n; ++i) cin >> p[i].x >> p[i].y;
		sort(p,p+n,cmp);
		for (int i=0; i<n; ++i){
			hitall = 1;
			for (int j=0; j<i; ++j)
				if (!hit(i,j) && !shot[j]) hitall = 0;
			if (hitall && i < n-1) continue;
			for (int j=0; j<n; ++j)
				if (hit(i-1,j)) shot[j] = 1;
			++ans;
		}
		printf("Case %d: %d\n",_tc,ans);
	}
	return 0;
}
