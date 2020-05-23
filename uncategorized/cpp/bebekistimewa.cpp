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

#define MAXM 1010
#define MAXN 2020
int n,m,menyerah,bebek,ba[MAXM],dp[MAXM][MAXN];

int kabur(int waktu, int kandang){
	if (kandang==0 || kandang>n || ba[waktu]==kandang) return 0;
	if (waktu==m) return 1;
	if (dp[waktu][kandang]>=0) return dp[waktu][kandang];
	dp[waktu][kandang] = kabur(waktu+1,kandang-1)|kabur(waktu+1,kandang+1);
	return dp[waktu][kandang];
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; ++i) scanf("%d",&ba[i]);
	if (n > 2*m + 3){
		int dengklek[MAXN];
		for (int i=0; i<m; ++i)
			if (ba[i]<MAXN) dengklek[ba[i]] = 1;
		for (int i=2; i<=n && i<MAXN; ++i)
			if (dengklek[i]==0 && dengklek[i-1]==0) bebek = i;
		for (int i=0; i<m; ++i)
			if (i&1) printf("%d\n",bebek); else printf("%d\n",bebek-1);
		return 0;
	}
	menyerah = 0;
	memset(dp,255,sizeof(dp));
	for (int i=1; i<=n; ++i)
		if (kabur(0,i)) menyerah = i;
	if (!menyerah) printf("menyerah\n");
		else {
			bebek = menyerah;
			printf("%d\n",bebek);
			for (int i=1; i<m; ++i){
				if (kabur(i,bebek-1)) --bebek; else ++bebek;
				printf("%d\n",bebek);
			}
		}
	return 0;
}
