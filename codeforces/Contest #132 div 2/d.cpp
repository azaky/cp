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

long long n,m,ans,t,tt,x,cost,maxp,cost1,cost2;

int main(){
	scanf("%I64d%I64d",&n,&m);
	ans = 0;
	while (n--){
		scanf("%I64d%I64d%I64d%I64d",&t,&tt,&x,&cost);
		if (t >= tt){
			ans += m * x + cost;
			continue;
		}
		maxp = m % (tt-t) == 0 ? m / (tt-t) : m / (tt-t) + 1;
		cost1 = maxp * cost;
		
		if (cost > x*(tt-t)){
			//p = 0
			cost2 = m * x + cost;
		}
		else {
			cost2 = cost1;
		}
		
		debug("%I64d %I64d\n",cost1,cost2);
		
		ans += min(cost1,cost2);
	}
	cout << ans << endl;
	return 0;
}
