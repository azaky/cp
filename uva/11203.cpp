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

int ntc, n, m, e, a, b, c;
char s[111];

int main(){
	scanf("%d",&ntc);
	for (int tc = 0; tc <ntc; ++tc){
		scanf("%s",s);
		n = strlen(s);
		m = e = -1;
		for (int i=0; i<n; ++i){
			if (s[i] == 'M') m = i;
			if (s[i] == 'E') e = i;
		}
		a = b = c = 0;
		for (int i=0; i<m; ++i) a += s[i] == '?' ? 1 : 0;
		for (int i=m; i<e; ++i) b += s[i] == '?' ? 1 : 0;
		for (int i=e; i<n; ++i) c += s[i] == '?' ? 1 : 0;
		printf("%s\n",a > 0 && b > 0 && c > 0 && a + b == c && a == m && b == e-m-1 && c == n-e-1 ? "theorem" : "no-theorem");
	}
	return 0;
}
