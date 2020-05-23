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
int use2[11];


int getdigits(int x)
{
	if (x == 0) return 1;
	
	int ret = 0;
	while (x > 0)
	{		
		++ret;
		x /= 10;
	}
	
	return ret;
}

int check(int x)
{
	RESET(use2,0);	
	
	int dg = getdigits(x);
	REP(i, dg)
	{
		int cur = x%10;
		
		++use2[cur];
		if (use2[cur] > n[cur])
			return 0;
		
		x /= 10;
	}
	
	return 1;
}

void setplus(int x)
{
	int dg = getdigits(x);
	REP(i, dg)
	{
		int cur = x%10;
		
		++n[cur];
		
		x /= 10;
	}
}

void setmin(int x)
{
	int dg = getdigits(x);
	REP(i, dg)
	{
		int cur = x%10;
		
		--n[cur];
		
		x /= 10;
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	REP(i, 10)
	{
		scanf("%d", &n[i]);
	}
	
	int j = 0;
	
	int am, bm, cm, dm;
	
	am = bm = cm = dm = 0;
	
	REP(i, 10000)
	{
		if (check(i) == 0)
			continue;
		setmin(i);
				
		FOR(a, am,9)
		{
			if (i * a > 9999)
				break;
			
			j = a * 1000;
			
			if (j * i > 9999999)
				break;
			
			if (j)
			{
				if (n[a] == 0)
					continue;
				n[a]--;
			}
				
			if (check(i*a) == 0)
			{
				if (j)
					n[a]++;
				break;
			}
			
			setmin(i*a);
			
			FOR(b, bm, 9)
			{
				if (b * i > 9999) 
					break;
				
				j += b * 100;
			
				if (j * i > 9999999)
				{
					j -= b * 100;
					break;
				}
				
				if (j)
				{
					if (n[b] == 0)
					{
						j -= b * 100;
						continue;
					}
					n[b]--;
				}
				
				if (check(i*b) == 0)
				{
					if (j)
						n[b]++;
					j -= b*100;
					
					break;
				}
				
				setmin(i*b);
				
				FOR(c, cm, 9)
				{
					if (c * i > 9999)
						break;
					
					j += c * 10;
					
					if (j * i > 9999999)
					{
						j -= c * 10;
						break;
					}
					
					if (j)
					{
						if (n[c] == 0)
						{
							j -= c * 10;
							continue;
						}
						n[c]--;
					}
					
					if (check(i*c) == 0)
					{
						if (j)
							n[c]++;
						j -= c*10;
						
						break;
					}
					
					setmin(i*c);
					
					FOR(d, dm, 9)
					{
						if (d * i > 9999)
							break;
						
						j += d;
						
						if (j * i > 9999999)
						{
							j -= d;
							break;
						}
						
						if (n[d] == 0)
						{
							j -= d;
							continue;
						}
						n[d]--;
						
						if (check(i*d) == 0)
						{							
							n[d]++;
							j -= d;
							
							break;
						}
						setmin(i*d);
						
						if (check(i*j) == 0)
						{
							n[d]++;
							j -= d;
							setplus(i*d);
							break;
						}
						
						setmin(i*j);
						
						int flag = 1;
						FOR(k,1,9)
						{
							if (n[k])
							{
								flag = 0;
								break;
							}
						}
						
						if (flag)
						{
							printf("%d\n%d\n",i,j);
							return 0;
						}
						
						setplus(i*j);
						setplus(i*d);
						n[d]++;
						j -= d;
					}
					
					if (j)
						n[c]++;
					setplus(i*c);
					j -= c*10;	
				}
				
				if (j)
					n[b]++;
				setplus(i*b);
				j -= b*100;
			}
			
			setplus(i*a);
			
			if (j)
				n[a]++;
		}
		
		setplus(i);
	}
						
	printf("-1\n-1\n");
	
	return 0;
}
