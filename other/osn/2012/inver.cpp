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

const int MAXN = 1005;
const int INF = 1000000;
string dummy;
int n,x[MAXN],a[MAXN][MAXN],a1,a2,ans;

int sol(int a[MAXN][MAXN]){
	
	return 0;
}

int main(){
	getline(cin,dummy);
	scanf("%d",&n);
	for (int i=0; i<n; ++i) scanf("%d",&x[i]);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j) scanf("%d",&a[i][j]);
	a1 = sol(a);
	for (int i=0; i<n; ++i) a[0][i] ^= x[i];
	a2 = sol(a);
	ans = min(a1,a2);
	if (ans == INF) printf("-1\n");
		else printf("%d\n",ans);
	return 0;
}
