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

#define INF 1e9

int tc;
int nh, nc;
double loc[205];
double dp[205][205];
int vis[205][205];

double precomp[205][205];


double foo(int i, int j, int k)
{
	return fabs((loc[i] + (loc[j]-loc[i]) * (double)(k-i) / (double)(j-i)) - loc[k]);
}

double work(int last, int rem)
{
	if (rem < 0)
		return INF;
		
	if (rem == 0 || last == nh-2)
	{		
		return precomp[last][nh-1];
	}	
	
	double &ret = dp[last][rem];
	if (vis[last][rem] == 0)
	{
		vis[last][rem] = 1;
		ret = INF;
		
		FOR (i, last+1, nh-2)
		{
			MN(ret, work(i,rem-1)+precomp[last][i]);	
		}
	}
	return ret;
}

int main(){
	
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d%d", &nh, &nc);
		REP(i, nh)
			scanf("%lf", &loc[i]);
	
		REP(i, nh)
			FOR(j,i+1,nh)
			{
				precomp[i][j] = 0;
				FOR(k,i+1,j-1)
				{
					precomp[i][j] += foo(i,j,k);
				}
			}
	
		nc -= 2;
		RESET(vis,0);
		printf("%.4lf\n", work(0,nc)/(double)nh);
	}
	
	return 0;
}
