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

const string cc = "o-<>";
const int ll = 0;
const int rr = 1;
const int MAXN = 555;
const int INF = 1061109567;

string s;
int tc,n,dp[MAXN][4][2],add,ans;

int main(){
	scanf("%d\n",&tc);
	while (tc--){
		getline(cin,s);
		n = s.length();
		memset(dp,63,sizeof(dp));
		/*
		 * o = 0;
		 * - = 1;
		 * < = 2;
		 * > = 3;
		 * dir 0 = ll
		 * dir 1 = rr
		 */
		for (int pos = 0; pos < n; ++pos)
			for (int ch = 0; ch < 4; ++ch)
				for (int dir = 0; dir <2; ++dir){
					add = s[pos]==cc[ch] ? 0 : 1;
					if (pos == 0){
						if (ch == 2 && dir == 0) dp[pos][ch][dir] = add;
						if (ch == 0 && dir == 1) dp[pos][ch][dir] = add;
						continue;
					}
					// <-o OKD
					if (ch == 0 && dir == ll){
						dp[pos][ch][dir] = dp[pos-1][1][0];
						if (dp[pos][ch][dir] != INF) dp[pos][ch][dir]+=add;
					}
					// -oo OR ->o OR -o- OKD
					if (ch == 0 && dir == rr){
						dp[pos][ch][dir] = min(dp[pos-1][0][ll],min(dp[pos-1][3][rr],dp[pos-1][1][ll]));
						if (dp[pos][ch][dir] != INF) dp[pos][ch][dir]+=add;
					}
					// <-- OR ><- OKD
					if (ch == 1 && dir == ll){
						dp[pos][ch][dir] = min(dp[pos-1][1][ll],dp[pos-1][2][ll]);
						if (dp[pos][ch][dir] != INF) dp[pos][ch][dir]+=add;
					}
					// ---> OR oo-> OR -o- OKD
					if (ch == 1 && dir == rr){
						dp[pos][ch][dir] = min(dp[pos-1][0][rr],min(dp[pos-1][1][rr],dp[pos-1][0][ll]));
						if (dp[pos][ch][dir] != INF) dp[pos][ch][dir]+=add;
					}
					// -o< OR ->< OKD
					if (ch == 2 && dir == ll){
						dp[pos][ch][dir] = min(dp[pos-1][0][ll],dp[pos-1][3][rr]);
						if (dp[pos][ch][dir] != INF) dp[pos][ch][dir]+=add;
					}
					// --> OKD
					if (ch == 3 && dir == rr){
						dp[pos][ch][dir] = dp[pos-1][1][rr];
						if (dp[pos][ch][dir] != INF) dp[pos][ch][dir]+=add;
					}
				}
		ans = min(dp[n-1][0][ll],dp[n-1][3][rr]);
		printf("%d\n",ans);
	}
						
	return 0;
}
