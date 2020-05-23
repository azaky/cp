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
const int maxn = 202;
int n,x[2],sum[maxn],a[maxn],ans;
int dp[maxn][maxn*maxn][2],v[maxn][maxn*maxn][2];

int calc(int pos, int sisa, int last){
	if (sisa < 0 || (sum[n]-sum[pos])-(x[0]-sisa) > x[1]) return INF;
	if (v[pos][sisa][last]) return dp[pos][sisa][last];
	v[pos][sisa][last] = 1;
	if (pos == 0) return dp[pos][sisa][last] = 0;
	int inv = last^1;
	int ans1 = last == 0 ? calc(pos-1,sisa-a[pos],last) : calc(pos-1,sisa,last);
	int ans2 = (last == 0 ? calc(pos-1,sisa-a[pos],inv) : calc(pos-1,sisa,inv)) + min(a[pos],a[pos-1]);
	debug("DP POS: %d, SISA: %d, LAST: %d, = %d\n",pos,sisa,last,min(ans1,ans2));
	return dp[pos][sisa][last] = min(ans1,ans2);
}

int main(){
	#ifdef DEBUG
	#else
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	
	scanf("%d",&n);
	scanf("%d%d",&x[0],&x[1]);
	a[0] = sum[0] = 0;
	for (int i=1; i<=n; ++i) {scanf("%d",&a[i]); sum[i] = sum[i-1]+a[i];}
	// dp[posisi][x[0]][last]
	ans = min(calc(n,x[0],0),calc(n,x[0],1));
	printf("%d\n",ans==INF ? -1 : ans);
	return 0;
}
