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

long long f[111];

long long path(long long a, long long b, long long n);

int main(){
	f[0] = 1;
	f[1] = 2;
	for (int i=2; i<77; ++i){
		f[i] = f[i-1] + f[i-2];
	}
	
	scanf("%d%d",&q,&n);
	for (int qq = 0; qq < q; ++qq){
		scanf("%I64d%I64d",&a,&b);
		printf("%I64d\n",path(a,b,76));
	}
	return 0;
}

long long path(long long a, long long b, long long n){
	if (a < b) return path(b,a,n);
	if (a == b) return 0;
	na = nb = n;
	while (a > f[na]) --na;
	while (b > f[nb]) --nb;
	if (na == nb) return path(a-f[na-1],b-f[nb-1],na);
	if (na - nb == 1) return path(