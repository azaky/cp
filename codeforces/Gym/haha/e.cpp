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

int n[11];
int use[11];

int check(int x)
{
	if (x >= 10000) return 0;
	
	RESET(use,0);	
	while (x > 0)
	{
		int cur = x%10;
		
		++use[cur];
		if (use[cur] > n[cur])
			return 0;
		
		x /= 10;
	}
	
	return 1;
}

int checkans(int x)
{
	if (x >= 10000000) return 0;
	
	RESET(use,0);	
	while (x > 0)
	{
		int cur = x%10;
		
		++use[cur];
		if (use[cur] > n[cur])
			return 0;
		
		x /= 10;
	}
	
	return 1;
}

void setback(int x)
{
	while (x > 0)
	{
		int cur = x%10;
		
		++n[cur];
		
		x /= 10;
	}
}

void setremove(int x)
{
	while (x > 0)
	{
		int cur = x%10;
		
		--n[cur];
		
		x /= 10;
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	
	int sum = 0;
	REP(i, 10)
	{
		scanf("%d", &n[i]);
		sum+= n[i];
	}
	
	if (sum != 31) 
	{
		printf("-1\n-1\n");
		return 0;
	}
	
	int ans1 = 0, ans2 = 0;
	
	REP(a,10)
	{
		ans1 += a * 1000;
		if (ans1)
		{
			if (n[a]==0)
			{
				ans1 -= a * 1000;
				continue;
			}
			n[a]--;
		}
		REP(b,10)
		{
			ans1 += b * 100;
			if (ans1)
			{
				if (n[b]==0)
				{	
					ans1 -= b * 100;
					continue;
				}
				n[b]--;
			}
			REP(c,10)
			{
				ans1 += c * 10;
				if (ans1)
				{
					if (n[c]==0)
					{
						ans1 -= c * 10;
						continue;
					}
					n[c]--;
				}
				REP(d, 10)
				{
					if (n[d] == 0)
						continue;
					
					n[d]--;
					
					ans1 +=d;
					
					REP(e, 10)
					{
						if (n[e] == 0) continue;
						
						if (e * ans1 >= 10000)
							break;
						
						n[e]--;
						
						if (check(ans1*e) == 0)
						{
							n[e]++;
							break;
						}
							
						
						setremove(ans1*e);
						
						REP(f, 10)
						{
							if (n[f] == 0) continue;
							n[f]--;
						
							if (check(ans1*f) == 0)
							{
								n[f]++;
								break;
							}
							setremove(ans1*f);
							
							REP(g,10)
							{
								if (n[g] == 0) continue;
								
								n[g]--;
						
								if (check(ans1*g) == 0)
								{
									n[g]++;
									break;
								}
								setremove(ans1*g);
								
								REP(h,10)
								{
									if (n[h] == 0) continue;
									
									n[h]--;
						
									if (check(ans1*h) == 0)
									{
										n[h]++;
										break;
									}
								
									setremove(ans1*h);
									
									ans2 = e*1000 + f*100 + g*10 + h;
									
									if (checkans(ans1*ans2))
									{
										printf("%d\n%d\n", ans1, ans2);
										return 0;
									}
									
									setback(ans1*h);
									n[h]++;
								}
								setback(ans1*g);
								n[g]++;
							}
							setback(ans1*f);
							n[f]++;
						}
						setback(ans1*e);
						n[e]++;
					}
					n[d]++;
					
					ans1 -= d;
				}
				if (ans1)
					n[c]++;
					
				ans1 -= c * 10;
			}
			if (ans1)
				n[b]++;
				
			ans1-= b * 100;
		}
		if (ans1)
			n[a]++;
			
		ans1 -= a * 1000;
	}
						
	printf("-1\n-1\n");
	
	return 0;
}
