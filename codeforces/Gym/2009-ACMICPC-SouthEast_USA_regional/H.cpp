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

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back
#define LLD "%I64d"

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

/* -------------- end of azaky's template -------------- */

int n;
double x[1005],y[1005],p[1005];

double dp[1005][1005];
double dist[1005][1005];

int vis[1005][1005];

double work(int pos, int last)
{
	if (pos > n)
	{
		return dist[last][n+1];
	}
	
	double &ret = dp[pos][last];
	
	if (vis[pos][last] == 0)
	{
		vis[pos][last] = 1;
		ret = min(p[pos]+work(pos+1,last), work(pos+1,pos) + dist[pos][last]+1.00);
	}
	
	
	return ret;
}


double _distance(int a, int b)
{
	double dx = x[a]-x[b];
	double dy = y[a]-y[b];
	
	return sqrt(dx*dx + dy*dy);
}

int main(){
	while (1)
	{
		scanf("%d",&n);
		if (n == 0) return 0;
		
		x[0] = 0.00; y[0] = 0.00;
		x[n+1] =100.00; y[n+1] =100.00;
		FOR(i,1,n)
		{
			scanf("%lf%lf%lf", &x[i], &y[i], &p[i]);
		}
		
		
		FOR(i,0,n+1)
		{
			FOR(j,i,n+1)
			{
				dist[i][j] = dist[j][i] = _distance(i,j);
				
				//printf("dist %d %d = %.3lf\n", i, j, dist[i][j]);
			}
		}
		
		RESET(vis, 0);
		printf("%.3lf\n", work(1,0)+1.00);
	}
	
	return 0;
}
