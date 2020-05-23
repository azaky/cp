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

const int INF = 1000000000;
int n, m, a[16][16], aa, bb, cc;
int dp[16][1<<16], visit[16][1<<16], ans;

int calc(int end, int mask){
	if (visit[end][mask]) return dp[end][mask];
	if (mask == 1) return dp[end][mask] = 0;
	visit[end][mask] = 1;
	dp[end][mask] = INF;
	for (int i=0; i<n; ++i){
		if ((mask & (1 << i)) == 0 || i == end) continue;
		dp[end][mask] = min(dp[end][mask],a[i][end]+calc(i,mask-(1 << end)));
	}
	debug("END = %d, mask = %d --> %d\n",end,mask,dp[end][mask]);
	return dp[end][mask];
}

int main(){
	while (true){
		scanf("%d",&n);
		if (n==0) break;
		scanf("%d",&m);
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j) a[i][j] = INF;
		for (int i=0; i<m; ++i){
			scanf("%d%d%d",&aa,&bb,&cc);
			--aa; --bb;
			a[aa][bb] = a[bb][aa] = min(cc,a[aa][bb]);
		}
		//dp[start = 0][end][bitmask]
		memset(dp,63,sizeof(dp));
		memset(visit,0,sizeof(visit));
		ans = INF;
		for (int i=1; i<n; ++i){
			ans = min(ans,a[0][i]+calc(i,(1<<n)-1));
		}
		printf("%d\n",ans);
	}
	return 0;
}
