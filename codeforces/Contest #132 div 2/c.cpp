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

int n,m,s,nn,mm,a,b,c,ask;
long long ans,ans1,ans2,dbl,cot;

int main(){
	cin >> n >> m >> s;
	ans1 = 0; ans2 = 0; dbl = 0;
	for (a = 0; 2*a < n; ++a)
		for (b = 0; 2*b < m; ++b){
			nn = 2*a + 1;
			mm = 2*b + 1;
			if (nn*mm > s) continue;
			debug ("(a,b): %d %d\n",a,b);
			if (nn*mm == s){
				cot = 2*(long long)(a+1)*(long long)(b+1) - 1;
				cot *= (long long)(n-nn+1) * (long long)(m-mm+1);
				ans1 += cot;
				debug("1st %I64d %I64d\n",ans1,ans2);
				continue;
			}
			ask = s - nn*mm;
			if (ask%2 != 0) continue;
				else ask /= 2;
			//debug ("%d\n",ask);
			for (c = 1; 2*c + 2*a < n; ++c)
				if (ask%c == 0 && (ask/c)%2==1){
					if (ask/c >= mm) continue;
					nn = 2*a + 2*c + 1;
					ans2 += 2 * (long long)(n-nn+1) * (long long)(m-mm+1);
				}
			debug("2nd %I64d %I64d\n",ans1,ans2);
			}
	debug("%I64d %I64d\n",ans1,ans2);
	cout << ans1 + ans2;
	return 0;
}
