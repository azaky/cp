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

const int MAXN = 2222;
int _tc;
int n, shot[MAXN], ans, hitall;
long long r;
point p[MAXN];

bool cmp(const point &a, const point &b){
	//return (atan2(a.y,a.x) < atan2(b.y,b.x));
	return a.x*b.y < a.y*b.x;
}

bool hit(int i,int k){
	//persamaan garis ax + by + c = 0
	long long a = p[i].y;
	long long b = -p[i].x;
	long long lhs = (a*p[k].x + b*p[k].y);
	lhs = lhs*lhs;
	long long rhs = (a*a + b*b) * (r*r);
	return lhs <= rhs;
}

int main(){
	scanf("%d",&_tc);
	for (int tc = 1; tc <= _tc; ++tc){
		cin >> n >> r; //scanf("%d%d",&n,&r);
		for (int i=0; i<n; ++i) cin >> p[i].x >> p[i].y; //scanf("%d%d",&p[i].x,&p[i].y);
		sort(p,p+n,cmp);
		//for (int i=0; i<n; ++i) debug("p[%d] = (%I64d, %I64d)\n",i,p[i].x,p[i].y);
		memset(shot,0,sizeof(shot));
		ans = 0;
		for (int i=0; i<n; ++i){
			//if (shot[i]) continue;
			hitall = 1;
			for (int j=0; j<i; ++j)
				if (!hit(i,j) && !shot[j]){hitall = 0; break;}
			if (hitall) continue;
			//debug("TEMBAK %d\n",i-1);
			++ans;
			for (int j=0; j<n; ++j)
				if (hit(i-1,j)) shot[j] = 1;
			//debug("DONE %d\n",i-1);
		}
		hitall = 0;
		for (int i=0; i<n; ++i)
			if (!shot[i]) hitall = 1;
		if (hitall) ++ans;
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
