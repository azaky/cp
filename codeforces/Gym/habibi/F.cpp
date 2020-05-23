#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <limits>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

int tc, nc;
int a[105], p[1005];
int presum[105];
int dp[105][105];

int work(int last, int pos)
{
	if (pos >= nc-1)
	{
		int tmp = presum[pos];
		if (last>0)tmp-=presum[last-1];
		
		return (tmp+10)*p[pos];
	}
	
	
	int &ret = dp[last][pos];
	if (ret == -1)
	{
		int tmp = presum[pos];
		if (last>0) tmp -= presum[last-1];
		
		ret = min((tmp+10)*p[pos] + work(pos+1,pos+1), work(last,pos+1));
	}
	
	return ret;
}

int main(){
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &nc);
		REP(i, nc)
		{
			scanf("%d %d", &a[i], &p[i]);
			
			presum[i] = a[i];
			if (i) presum[i] += presum[i-1];
		}
			
		RESET(dp, -1);
		printf("%d\n", work(0,0));		
	}
	
	return 0;
}
