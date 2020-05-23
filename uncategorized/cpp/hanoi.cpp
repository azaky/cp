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

const int maxn = 100100;
const int MOD = 1000000;
int n, line, s[3], pos[3], step[maxn], c[3][maxn];

int solve(int *pos, int maxc){
	if (maxc == 1) return 0;
	int now, sec = -1;
	for (int i=0; i<3; ++i)
		if (c[i][pos[i]] == maxc) now = i;
	for (int i=0; i<3; ++i)
		if (c[i][pos[i]] == maxc-1) sec = i;
	if (sec < 0){
		--pos[now];
		return solve(pos,maxc-1);
	}
	--pos[now]; --pos[sec];
	return (solve(pos,maxc-2)+1+step[maxc-2])%MOD;
}

int main(){
	scanf("%d",&n);
	for (line = 0; line < 3; ++line) scanf("%d",&s[line]);
	for (line = 0; line < 3; ++line)
		for (int i=0; i<s[line]; ++i) scanf("%d",&c[line][i]);
	step[0] = 0;
	for (int i=1; i<=n; ++i) step[i] = (2*step[i-1]+1)%MOD;
	printf("%d\n",solve(pos,n));
	return 0;
}
