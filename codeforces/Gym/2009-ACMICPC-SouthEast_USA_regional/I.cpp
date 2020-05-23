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

vector<int> pre[1050];
int dp[1050][505];

int n, m;
int cur;


void precompute(int pos, int mask, int ret)
{
	if (pos == n-1)
	{
		//printf("\nselesai dgn mask = %d\n", mask);
		if (mask == (1<<n)-1)
		{
			pre[cur].push_back(ret);
			
			//printf("awal : %d, hasil : %d\n", cur, ret);
		}
		else
		{
			if ((ret & (1<<(n-1))) == 0 && (ret & (1<<(n-2))) == 0)
			{
				ret |= (1 << (n-1));
				ret |= (1 << (n-2));
				
				pre[cur].push_back(ret);
				
				//printf("awal : %d, hasil : %d\n", cur, ret);
			}
		}
		
		return;
	}	
	
	// bolong atas
	if ((mask & (1<<pos)) == 0)
	{
		mask |= (1<<pos);
		
		if (((ret & (1 <<pos)) == 0) && ((ret & (1<<(pos+1))) == 0))
				precompute(pos+1, mask, ret | (1<<pos) | (1<<(pos+1)));
				
		if (pos > 0)
		{
			if (((ret & (1 <<pos)) == 0) && ((ret & (1<<(pos-1))) == 0))
					precompute(pos+1, mask, ret | (1<<pos) | (1<<(pos-1)));	
		}
		
		// bolong bawahnya juga
		if ((mask & (1<<(pos+1))) == 0)
		{
			int newmask = mask | (1<<(pos+1));
			
			if ((ret & (1<<pos)) == 0)
				precompute(pos+1, newmask, ret | (1<<pos));
			if ((ret & (1<<(pos+1))) == 0)
				precompute(pos+1, newmask, ret | (1<<(pos+1)));
				
			if (((ret & (1 <<pos)) == 0) && ((ret & (1<<(pos+1))) == 0))
				precompute(pos+1, newmask, ret | (1<<pos) | (1<<(pos+1)));
		}
	}
	else
	{
		precompute(pos+1, mask, ret);
	}
}

int work(int mask, int pos)
{
	if (pos == m-1)
	{
		//printf("mask = %d\n", mask);
		return (mask == (1<<n)-1)?1:0;
	}
	
	int &ret = dp[mask][pos];
	
	if (ret == -1)
	{
		ret = 0;
		REP(i,SZ(pre[mask]))
		{
			ret = (ret + work(pre[mask][i], pos+1)) % 1000000;
		}
	}
	
	return ret;
}

int main(){
	while (1)
	{
		scanf("%d %d", &n, &m);
		if (n+m ==0)
			break;
				
		RESET(pre, 0);
		
		REP(i,(1<<n))
		{
			cur = i;
			precompute(0,i,0);
		}
		
		RESET(dp, -1);
		printf("%d\n", work(0,0));
		
	}
	
	return 0;
}



